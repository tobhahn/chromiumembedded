// Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/browser_listener_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK browser_listener_on_create(
    struct _cef_browser_listener_t* self, struct _cef_browser_t* browser)
{
  DCHECK(self && browser);
  if(!self || !browser)
    return;

  CefBrowserListenerCppToC::Get(self)->OnCreate(
      CefBrowserCToCpp::Wrap(browser));
}

void CEF_CALLBACK browser_listener_on_destroy(
    struct _cef_browser_listener_t* self, struct _cef_browser_t* browser)
{
  DCHECK(self && browser);
  if(!self || !browser)
    return;

  CefBrowserListenerCppToC::Get(self)->OnDestroy(
      CefBrowserCToCpp::Wrap(browser));
}


// CONSTRUCTOR - Do not edit by hand.

CefBrowserListenerCppToC::CefBrowserListenerCppToC(CefBrowserListener* cls)
    : CefCppToC<CefBrowserListenerCppToC, CefBrowserListener,
        cef_browser_listener_t>(cls)
{
  struct_.struct_.on_create = browser_listener_on_create;
  struct_.struct_.on_destroy = browser_listener_on_destroy;
}

#ifdef _DEBUG
long CefCppToC<CefBrowserListenerCppToC, CefBrowserListener,
    cef_browser_listener_t>::DebugObjCt = 0;
#endif

