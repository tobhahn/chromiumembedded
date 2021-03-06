// Copyright (c) 2012 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/browser/render_widget_host_view_osr.h"
#include "libcef/browser/web_contents_view_osr.h"

#include "content/public/browser/render_widget_host.h"
#include "content/public/browser/web_contents.h"

CefWebContentsViewOSR::CefWebContentsViewOSR(
    content::WebContents* web_contents,
    content::WebContentsViewDelegate* delegate)
        : web_contents_(web_contents),
          view_(NULL) {
}

CefWebContentsViewOSR::~CefWebContentsViewOSR() {
}

// Overridden from WebContentsView:

void CefWebContentsViewOSR::CreateView(const gfx::Size& initial_size,
                                       gfx::NativeView context) {
}

content::RenderWidgetHostView* CefWebContentsViewOSR::CreateViewForWidget(
    content::RenderWidgetHost* render_widget_host) {
  if (render_widget_host->GetView())
    return render_widget_host->GetView();

  view_ = new CefRenderWidgetHostViewOSR(render_widget_host);
  return view_;
}

content::RenderWidgetHostView* CefWebContentsViewOSR::CreateViewForPopupWidget(
    content::RenderWidgetHost* render_widget_host) {
  CefRenderWidgetHostViewOSR* popup_widget =
      new CefRenderWidgetHostViewOSR(render_widget_host);
  return popup_widget;
}

gfx::NativeView CefWebContentsViewOSR::GetNativeView() const {
  return gfx::NativeView();
}

gfx::NativeView CefWebContentsViewOSR::GetContentNativeView() const {
  return gfx::NativeView();
}

gfx::NativeWindow CefWebContentsViewOSR::GetTopLevelNativeWindow() const {
  return gfx::NativeWindow();
}


void CefWebContentsViewOSR::GetContainerBounds(gfx::Rect *out) const {
  *out = GetViewBounds();
}

void CefWebContentsViewOSR::SetPageTitle(const string16& title) {
}

void CefWebContentsViewOSR::OnTabCrashed(base::TerminationStatus status,
    int error_code) {
  view_ = NULL;
}

void CefWebContentsViewOSR::SizeContents(const gfx::Size& size) {
}

void CefWebContentsViewOSR::RenderViewCreated(content::RenderViewHost* host) {
  if (view_) {
    CefRenderWidgetHostViewOSR* osr_view =
        static_cast<CefRenderWidgetHostViewOSR*>(view_);
    osr_view->InstallTransparency();
  }
}

void CefWebContentsViewOSR::RenderViewSwappedIn(content::RenderViewHost* host) {
}

void CefWebContentsViewOSR::Focus() {
}

void CefWebContentsViewOSR::SetInitialFocus() {
}

void CefWebContentsViewOSR::StoreFocus() {
}

void CefWebContentsViewOSR::RestoreFocus() {
}

WebDropData* CefWebContentsViewOSR::GetDropData() const {
  return NULL;
}

gfx::Rect CefWebContentsViewOSR::GetViewBounds() const {
  return view_ ? view_->GetViewBounds() : gfx::Rect();
}

#if defined(OS_MACOSX)
bool CefWebContentsViewOSR::IsEventTracking() const {
  return false;
}

void CefWebContentsViewOSR::CloseTabAfterEventTracking() {
}

void CefWebContentsViewOSR::SetAllowOverlappingViews(bool overlapping) {
}
#endif  // defined(OS_MACOSX)

// RenderViewHostDelegateView methods.

void CefWebContentsViewOSR::StartDragging(const WebDropData& drop_data,
    WebKit::WebDragOperationsMask allowed_ops,
    const gfx::ImageSkia& image,
    const gfx::Vector2d& image_offset,
    const content::DragEventSourceInfo& event_info) {
  // Dragging is not supported when window rendering is disabled.
  web_contents_->SystemDragEnded();
}

void CefWebContentsViewOSR::ShowPopupMenu(const gfx::Rect& bounds,
    int item_height,
    double item_font_size,
    int selected_item,
    const std::vector<WebMenuItem>& items,
    bool right_aligned,
    bool allow_multiple_selection) {
}
