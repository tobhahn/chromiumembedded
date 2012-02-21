/// Copyright (c) 2012 The Chromium Embedded Framework Authors.
// Portions (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/renderer/render_message_filter.h"
#include "libcef/common/cef_messages.h"

#include "base/bind.h"
#include "googleurl/src/gurl.h"
#include "googleurl/src/url_util.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/WebSecurityPolicy.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/platform/WebString.h"
#include "third_party/WebKit/Source/WebKit/chromium/public/platform/WebURL.h"

CefRenderMessageFilter::CefRenderMessageFilter()
    : channel_(NULL),
      render_loop_(base::MessageLoopProxy::current()) {
}

CefRenderMessageFilter::~CefRenderMessageFilter() {
}

void CefRenderMessageFilter::OnFilterAdded(IPC::Channel* channel) {
  channel_ = channel;
}

void CefRenderMessageFilter::OnFilterRemoved() {
}

bool CefRenderMessageFilter::OnMessageReceived(const IPC::Message& message) {
  bool handled = true;
  IPC_BEGIN_MESSAGE_MAP(CefRenderMessageFilter, message)
    IPC_MESSAGE_HANDLER(CefProcessMsg_RegisterScheme, OnRegisterScheme)
    IPC_MESSAGE_HANDLER(CefProcessMsg_ModifyCrossOriginWhitelistEntry,
                        OnModifyCrossOriginWhitelistEntry)
    IPC_MESSAGE_HANDLER(CefProcessMsg_ClearCrossOriginWhitelist,
                        OnClearCrossOriginWhitelist)
    IPC_MESSAGE_UNHANDLED(handled = false)
  IPC_END_MESSAGE_MAP()
  return handled;
}

void CefRenderMessageFilter::OnRegisterScheme(
    const std::string& scheme_name,
    bool is_standard,
    bool is_local,
    bool is_display_isolated) {
  if (is_standard) {
    // Make this registration as early as possible.
    url_parse::Component scheme_comp(0, scheme_name.length());
    if (!url_util::IsStandard(scheme_name.c_str(), scheme_comp))
      url_util::AddStandardScheme(scheme_name.c_str());
  }
  
  render_loop_->PostTask(FROM_HERE,
      base::Bind(&CefRenderMessageFilter::RegisterSchemeOnRenderThread, this,
                 scheme_name, is_local, is_display_isolated));
}

void CefRenderMessageFilter::OnModifyCrossOriginWhitelistEntry(
    bool add,
    const std::string& source_origin,
    const std::string& target_protocol,
    const std::string& target_domain,
    bool allow_target_subdomains) {
  render_loop_->PostTask(FROM_HERE,
      base::Bind(
        &CefRenderMessageFilter::ModifyCrossOriginWhitelistEntryOnRenderThread,
          this, add, source_origin, target_protocol, target_domain,
          allow_target_subdomains));
}

void CefRenderMessageFilter::OnClearCrossOriginWhitelist() {
  render_loop_->PostTask(FROM_HERE,
      base::Bind(
          &CefRenderMessageFilter::ClearCrossOriginWhitelistOnRenderThread,
          this));
}

void CefRenderMessageFilter::RegisterSchemeOnRenderThread(
    const std::string& scheme_name,
    bool is_local,
    bool is_display_isolated) {
  DCHECK(render_loop_->BelongsToCurrentThread());
  if (is_local) {
    WebKit::WebSecurityPolicy::registerURLSchemeAsLocal(
        WebKit::WebString::fromUTF8(scheme_name));
  }
  if (is_display_isolated) {
    WebKit::WebSecurityPolicy::registerURLSchemeAsDisplayIsolated(
        WebKit::WebString::fromUTF8(scheme_name));
  }
}

void CefRenderMessageFilter::ModifyCrossOriginWhitelistEntryOnRenderThread(
    bool add,
    const std::string& source_origin,
    const std::string& target_protocol,
    const std::string& target_domain,
    bool allow_target_subdomains) {
  DCHECK(render_loop_->BelongsToCurrentThread());
  GURL gurl = GURL(source_origin);
  if (add) {
    WebKit::WebSecurityPolicy::addOriginAccessWhitelistEntry(
        gurl,
        WebKit::WebString::fromUTF8(target_protocol),
        WebKit::WebString::fromUTF8(target_domain),
        allow_target_subdomains);
  } else {
    WebKit::WebSecurityPolicy::removeOriginAccessWhitelistEntry(
        gurl,
        WebKit::WebString::fromUTF8(target_protocol),
        WebKit::WebString::fromUTF8(target_domain),
        allow_target_subdomains);
  }
}

void CefRenderMessageFilter::ClearCrossOriginWhitelistOnRenderThread() {
  DCHECK(render_loop_->BelongsToCurrentThread());
  WebKit::WebSecurityPolicy::resetOriginAccessWhitelists();
}