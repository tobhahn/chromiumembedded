// Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing static and
// virtual method implementations. See the translator.README.txt file in the
// tools directory for more information.
//

#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/tab_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

CefRefPtr<CefBrowser> CefTabCToCpp::GetBrowser()
{
  if(CEF_MEMBER_MISSING(struct_, get_browser))
    return NULL;
  
  cef_browser_t* impl = struct_->get_browser(struct_);
  if(impl)
    return CefBrowserCToCpp::Wrap(impl);
  return NULL;
}

void CefTabCToCpp::Destroy()
{
  if(CEF_MEMBER_MISSING(struct_, destroy))
    return;

  struct_->destroy(struct_);
}

int CefTabCToCpp::GetIndex()
{
  if(CEF_MEMBER_MISSING(struct_, get_index))
    return -1;

  return struct_->get_index(struct_);
}

bool CefTabCToCpp::IsSelected()
{
  if(CEF_MEMBER_MISSING(struct_, is_selected))
    return false;

  return struct_->is_selected(struct_) ? true : false;
}

void CefTabCToCpp::Select()
{
  if(CEF_MEMBER_MISSING(struct_, select))
    return;

  struct_->select(struct_);
}

bool CefTabCToCpp::CanGoBack()
{
  if(CEF_MEMBER_MISSING(struct_, can_go_back))
    return false;

  return struct_->can_go_back(struct_) ? true : false;
}

void CefTabCToCpp::GoBack()
{
  if(CEF_MEMBER_MISSING(struct_, go_back))
    return;

  struct_->go_back(struct_);
}

bool CefTabCToCpp::CanGoForward()
{
  if(CEF_MEMBER_MISSING(struct_, can_go_forward))
    return false;

  return struct_->can_go_forward(struct_) ? true : false;
}

void CefTabCToCpp::GoForward()
{
  if(CEF_MEMBER_MISSING(struct_, go_forward))
    return;

  struct_->go_forward(struct_);
}

bool CefTabCToCpp::IsLoading()
{
  if(CEF_MEMBER_MISSING(struct_, is_loading))
    return false;

  return struct_->is_loading(struct_) ? true : false;
}

void CefTabCToCpp::Reload()
{
  if(CEF_MEMBER_MISSING(struct_, reload))
    return;

  struct_->reload(struct_);
}

void CefTabCToCpp::StopLoad()
{
  if(CEF_MEMBER_MISSING(struct_, stop_load))
    return;

  struct_->stop_load(struct_);
}

std::wstring CefTabCToCpp::GetAddress()
{
  std::wstring str;
  if(CEF_MEMBER_MISSING(struct_, get_address))
    return str;

  cef_string_t cef_str = struct_->get_address(struct_);
  if(cef_str) {
    str = cef_str;
    cef_string_free(cef_str);
  }
  return str;
}

std::wstring CefTabCToCpp::GetTitle()
{
  std::wstring str;
  if(CEF_MEMBER_MISSING(struct_, get_title))
    return str;

  cef_string_t cef_str = struct_->get_title(struct_);
  if(cef_str) {
    str = cef_str;
    cef_string_free(cef_str);
  }
  return str;
}

void CefTabCToCpp::Undo()
{
  if(CEF_MEMBER_MISSING(struct_, undo))
    return;

  struct_->undo(struct_);
}

void CefTabCToCpp::Redo()
{
  if(CEF_MEMBER_MISSING(struct_, redo))
    return;

  struct_->redo(struct_);
}

void CefTabCToCpp::Cut()
{
  if(CEF_MEMBER_MISSING(struct_, cut))
    return;

  struct_->cut(struct_);
}

void CefTabCToCpp::Copy()
{
  if(CEF_MEMBER_MISSING(struct_, copy))
    return;

  struct_->copy(struct_);
}

void CefTabCToCpp::Paste()
{
  if(CEF_MEMBER_MISSING(struct_, paste))
    return;

  struct_->paste(struct_);
}

void CefTabCToCpp::Delete()
{
  if(CEF_MEMBER_MISSING(struct_, del))
    return;

  struct_->del(struct_);
}

void CefTabCToCpp::SelectAll()
{
  if(CEF_MEMBER_MISSING(struct_, select_all))
    return;

  struct_->select_all(struct_);
}

void CefTabCToCpp::Print()
{
  if(CEF_MEMBER_MISSING(struct_, print))
    return;

  struct_->print(struct_);
}

void CefTabCToCpp::ViewSource()
{
  if(CEF_MEMBER_MISSING(struct_, view_source))
    return;

  struct_->view_source(struct_);
}

void CefTabCToCpp::LoadAddress(const std::wstring& url,
    const std::wstring& referrer)
{
  if(CEF_MEMBER_MISSING(struct_, load_address))
    return;

  struct_->load_address(struct_, url.c_str(), referrer.c_str());
}

void CefTabCToCpp::ExecuteJavaScript(const std::wstring& frame_xpath,
    const std::wstring& jscript)
{
  if(CEF_MEMBER_MISSING(struct_, execute_java_script))
    return;

  struct_->execute_java_script(struct_, frame_xpath.c_str(), jscript.c_str());
}


#ifdef _DEBUG
long CefCToCpp<CefTabCToCpp, CefTab, cef_tab_t>::DebugObjCt = 0;
#endif

