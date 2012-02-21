// Copyright (c) 2012 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// IPC messages for CEF.
// Multiply-included message file, hence no include guard.

#include "base/shared_memory.h"
#include "base/values.h"
#include "content/public/common/common_param_traits.h"
#include "content/public/common/referrer.h"
#include "ipc/ipc_message_macros.h"
#include "net/base/upload_data.h"

// TODO(cef): Re-using the message start for extensions may be problematic in
// the future. It would be better if ipc_message_utils.h contained a value
// reserved for consumers of the content API.
// See: http://crbug.com/110911
#define IPC_MESSAGE_START ExtensionMsgStart


// Messages sent from the browser to the renderer.

// Tell the renderer which browser window it's being attached to.
IPC_MESSAGE_ROUTED1(CefMsg_UpdateBrowserWindowId,
                    int /* id of browser window */)

// Send the renderer a response to a CefHostMsg_Request or a
// CefHostMsg_RequestForIOThread.
IPC_MESSAGE_ROUTED4(CefMsg_Response,
                    int /* request_id */,
                    bool /* success */,
                    std::string /* response */,
                    std::string /* error */)

// Tell the renderer to load a string.
IPC_MESSAGE_ROUTED3(CefMsg_LoadString,
                    int64 /* frame_id */,
                    std::string /* string */,
                    GURL /* url */)

// Parameters for a resource request.
IPC_STRUCT_BEGIN(CefMsg_LoadRequest_Params)
  // The request method: GET, POST, etc.
  IPC_STRUCT_MEMBER(std::string, method)

  // The requested URL.
  IPC_STRUCT_MEMBER(GURL, url)

  // The URL to send in the "Referer" header field. Can be empty if there is
  // no referrer.
  IPC_STRUCT_MEMBER(GURL, referrer)
  // One of the WebKit::WebReferrerPolicy values.
  IPC_STRUCT_MEMBER(int, referrer_policy)

  // Identifies the frame within the RenderView that sent the request.
  // -1 if unknown / invalid.
  IPC_STRUCT_MEMBER(int64, frame_id)

  // Usually the URL of the document in the top-level window, which may be
  // checked by the third-party cookie blocking policy. Leaving it empty may
  // lead to undesired cookie blocking. Third-party cookie blocking can be
  // bypassed by setting first_party_for_cookies = url, but this should ideally
  // only be done if there really is no way to determine the correct value.
  IPC_STRUCT_MEMBER(GURL, first_party_for_cookies)

  // Additional HTTP request headers.
  IPC_STRUCT_MEMBER(std::string, headers)

  // net::URLRequest load flags (0 by default).
  IPC_STRUCT_MEMBER(int, load_flags)

  // Optional upload data (may be null).
  IPC_STRUCT_MEMBER(scoped_refptr<net::UploadData>, upload_data)
IPC_STRUCT_END()

// Tell the renderer to load a request.
IPC_MESSAGE_ROUTED1(CefMsg_LoadRequest,
                    CefMsg_LoadRequest_Params)

// Tell the renderer to execute a command.
IPC_MESSAGE_ROUTED3(CefMsg_ExecuteCommand,
                    int /* request_id */,
                    int64 /* frame_id */,
                    std::string /* command */)

// Parameters structure for CefMsg_ExecuteCode.
IPC_STRUCT_BEGIN(CefMsg_ExecuteCode_Params)
  // Unique request id to match requests and responses.
  IPC_STRUCT_MEMBER(int, request_id)

  // Unique id of the target frame.
  IPC_STRUCT_MEMBER(int64, frame_id)

  // Whether the code is JavaScript or CSS.
  IPC_STRUCT_MEMBER(bool, is_javascript)

  // Code to execute.
  IPC_STRUCT_MEMBER(std::string, code)

  // Code script URL.
  IPC_STRUCT_MEMBER(GURL, script_url)

  // Code script start line.
  IPC_STRUCT_MEMBER(int, script_start_line)
IPC_STRUCT_END()

// Tell the renderer to execute some JavaScript or CSS code.
IPC_MESSAGE_ROUTED1(CefMsg_ExecuteCode,
                    CefMsg_ExecuteCode_Params)

// Sent to child processes to register a scheme.
IPC_MESSAGE_CONTROL4(CefProcessMsg_RegisterScheme,
                     std::string  /* sheme_name */,
                     bool /* is_standard */,
                     bool /* is_local */,
                     bool /* is_display_isolated */)

// Sent to child processes to add or remove a cross-origin whitelist entry.
IPC_MESSAGE_CONTROL5(CefProcessMsg_ModifyCrossOriginWhitelistEntry,
                     bool /* add */,
                     std::string  /* source_origin */,
                     std::string  /* target_protocol */,
                     std::string  /* target_domain */,
                     bool /* allow_target_subdomains */)

// Sent to child processes to clear the cross-origin whitelist.
IPC_MESSAGE_CONTROL0(CefProcessMsg_ClearCrossOriginWhitelist)


// Messages sent from the renderer to the browser.

// Sent when the render thread has started and all filters are attached.
IPC_MESSAGE_CONTROL0(CefProcessHostMsg_RenderThreadStarted)

// Sent when a frame is identified for the first time.
IPC_MESSAGE_ROUTED3(CefHostMsg_FrameIdentified,
                    int64 /* frame_id */,
                    int64 /* parent_frame_id */,
                    string16 /* frame_name */)

// Sent when a frame has been detached.
IPC_MESSAGE_ROUTED1(CefHostMsg_FrameDetached,
                    int64 /* frame_id */)

// Sent when a new frame has been given focus.
IPC_MESSAGE_ROUTED1(CefHostMsg_FrameFocusChange,
                    int64 /* frame_id */)

// Optional response message sent to the browser to return the results requested
// by CefMsg_ExecuteCommand or CefMsg_ExecuteCode.
IPC_MESSAGE_ROUTED2(CefHostMsg_ExecuteResponse,
                    int /* request_id */,
                    std::string /* response */)

// Parameters structure for CefHostMsg_Request.
IPC_STRUCT_BEGIN(CefHostMsg_Request_Params)
  // Unique request id to match requests and responses.
  IPC_STRUCT_MEMBER(int, request_id)

  // Unique id of the source frame.
  IPC_STRUCT_MEMBER(int64, frame_id)

  // Message name.
  IPC_STRUCT_MEMBER(std::string, name)

  // List of message arguments.
  IPC_STRUCT_MEMBER(ListValue, arguments)

  // Web security origin of the frame the request was sent from.
  IPC_STRUCT_MEMBER(string16, source_origin)

  // True if request has a callback specified.
  IPC_STRUCT_MEMBER(bool, has_callback)
IPC_STRUCT_END()

// Sent when the renderer has a request for the browser. The browser will always
// respond with a CefMsg_Response.
IPC_MESSAGE_ROUTED1(CefHostMsg_Request,
                    CefHostMsg_Request_Params)

// Sent when the renderer has a request for the browser that must be executed on
// the IO thread. The browser will always respond with a CefMsg_Response.
IPC_MESSAGE_CONTROL2(CefHostMsg_RequestForIOThread,
                     int /* routing_id */,
                     CefHostMsg_Request_Params)

// Optional Ack message sent to the browser to notify that a CefMsg_Response
// has been processed.
IPC_MESSAGE_ROUTED1(CefHostMsg_ResponseAck,
                    int /* request_id */)