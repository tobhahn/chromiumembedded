// Copyright (c) 2012 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#ifndef _CONTENTFILTER_CTOCPP_H
#define _CONTENTFILTER_CTOCPP_H

#ifndef BUILDING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed DLL-side only")
#else // BUILDING_CEF_SHARED

#include "include/cef.h"
#include "include/cef_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefContentFilterCToCpp
    : public CefCToCpp<CefContentFilterCToCpp, CefContentFilter,
        cef_content_filter_t>
{
public:
  CefContentFilterCToCpp(cef_content_filter_t* str)
      : CefCToCpp<CefContentFilterCToCpp, CefContentFilter,
          cef_content_filter_t>(str) {}
  virtual ~CefContentFilterCToCpp() {}

  // CefContentFilter methods
  virtual void ProcessData(const void* data, int data_size,
      CefRefPtr<CefStreamReader>& substitute_data) OVERRIDE;
  virtual void Drain(CefRefPtr<CefStreamReader>& remainder) OVERRIDE;
};

#endif // BUILDING_CEF_SHARED
#endif // _CONTENTFILTER_CTOCPP_H

