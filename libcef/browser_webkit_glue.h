// Copyright (c) 2008-2009 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#if defined(OS_WIN)
#include <windows.h>
#endif
#include <string>

#include "base/string_piece.h"
#include "v8/include/v8.h"

namespace WebKit {
class WebFrame;
class WebString;
class WebView;
}

namespace webkit_glue {

#if defined(OS_WIN)
// Capture a bitmap of the web view.
void CaptureWebViewBitmap(HWND mainWnd, WebKit::WebView* webview,
                          HBITMAP& bitmap, SIZE& size);

// Save a bitmap image to file, providing optional alternative data in |lpBits|
BOOL SaveBitmapToFile(HBITMAP hBmp, HDC hDC, LPCTSTR file, LPBYTE lpBits);
#endif

// Text encoding objects must be initialized on the main thread.
void InitializeTextEncoding();

// This is called indirectly by the network layer to access resources.
base::StringPiece NetResourceProvider(int key);

// Clear all cached data.
void ClearCache();

WebKit::WebString StdStringToWebString(const std::string& str);

std::string WebStringToStdString(const WebKit::WebString& str);

}  // namespace webkit_glue