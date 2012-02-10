// Copyright (c) 2012 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that can
// be found in the LICENSE file.

#include "libcef/browser/browser_message_loop.h"

CefBrowserMessageLoop::CefBrowserMessageLoop()
  : is_iterating_(true) {
}

// static
CefBrowserMessageLoop* CefBrowserMessageLoop::current() {
  MessageLoop* loop = MessageLoop::current();
  DCHECK_EQ(MessageLoop::TYPE_UI, loop->type());
  return static_cast<CefBrowserMessageLoop*>(loop);
}

bool CefBrowserMessageLoop::DoIdleWork() {
  bool valueToRet = inherited::DoIdleWork();
  if (is_iterating_)
    pump_->Quit();
  return valueToRet;
}

// Do a single interation of the UI message loop.
void CefBrowserMessageLoop::DoMessageLoopIteration() {
#if defined(OS_MACOSX)
  Run();
#else
  RunWithDispatcher(NULL);
#endif
}

// Run the UI message loop.
void CefBrowserMessageLoop::RunMessageLoop() {
  is_iterating_ = false;
  DoMessageLoopIteration();
}
