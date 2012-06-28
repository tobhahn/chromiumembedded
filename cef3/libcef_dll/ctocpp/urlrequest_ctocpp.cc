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

#include "libcef_dll/cpptoc/urlrequest_client_cpptoc.h"
#include "libcef_dll/ctocpp/request_ctocpp.h"
#include "libcef_dll/ctocpp/response_ctocpp.h"
#include "libcef_dll/ctocpp/urlrequest_ctocpp.h"


// STATIC METHODS - Body may be edited by hand.

CefRefPtr<CefURLRequest> CefURLRequest::Create(CefRefPtr<CefRequest> request,
    CefRefPtr<CefURLRequestClient> client) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: request; type: refptr_same
  DCHECK(request.get());
  if (!request.get())
    return NULL;
  // Verify param: client; type: refptr_diff
  DCHECK(client.get());
  if (!client.get())
    return NULL;

  // Execute
  cef_urlrequest_t* _retval = cef_urlrequest_create(
      CefRequestCToCpp::Unwrap(request),
      CefURLRequestClientCppToC::Wrap(client));

  // Return type: refptr_same
  return CefURLRequestCToCpp::Wrap(_retval);
}


// VIRTUAL METHODS - Body may be edited by hand.

CefRefPtr<CefRequest> CefURLRequestCToCpp::GetRequest() {
  if (CEF_MEMBER_MISSING(struct_, get_request))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_request_t* _retval = struct_->get_request(struct_);

  // Return type: refptr_same
  return CefRequestCToCpp::Wrap(_retval);
}

CefRefPtr<CefURLRequestClient> CefURLRequestCToCpp::GetClient() {
  if (CEF_MEMBER_MISSING(struct_, get_client))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_urlrequest_client_t* _retval = struct_->get_client(struct_);

  // Return type: refptr_diff
  return CefURLRequestClientCppToC::Unwrap(_retval);
}

CefURLRequest::Status CefURLRequestCToCpp::GetRequestStatus() {
  if (CEF_MEMBER_MISSING(struct_, get_request_status))
    return UR_UNKNOWN;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_urlrequest_status_t _retval = struct_->get_request_status(struct_);

  // Return type: simple
  return _retval;
}

CefURLRequest::ErrorCode CefURLRequestCToCpp::GetRequestError() {
  if (CEF_MEMBER_MISSING(struct_, get_request_error))
    return ERR_NONE;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_errorcode_t _retval = struct_->get_request_error(struct_);

  // Return type: simple
  return _retval;
}

CefRefPtr<CefResponse> CefURLRequestCToCpp::GetResponse() {
  if (CEF_MEMBER_MISSING(struct_, get_response))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_response_t* _retval = struct_->get_response(struct_);

  // Return type: refptr_same
  return CefResponseCToCpp::Wrap(_retval);
}

void CefURLRequestCToCpp::Cancel() {
  if (CEF_MEMBER_MISSING(struct_, cancel))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->cancel(struct_);
}


#ifndef NDEBUG
template<> long CefCToCpp<CefURLRequestCToCpp, CefURLRequest,
    cef_urlrequest_t>::DebugObjCt = 0;
#endif

