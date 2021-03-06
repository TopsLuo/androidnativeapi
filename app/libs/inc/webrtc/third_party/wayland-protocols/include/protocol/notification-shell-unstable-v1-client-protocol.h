/* Generated by wayland-scanner 1.13.0 */

#ifndef NOTIFICATION_SHELL_UNSTABLE_V1_CLIENT_PROTOCOL_H
#define NOTIFICATION_SHELL_UNSTABLE_V1_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_notification_shell_unstable_v1 The notification_shell_unstable_v1 protocol
 * Create desktop notifications
 *
 * @section page_desc_notification_shell_unstable_v1 Description
 *
 * notification_shell allows clients to create desktop notification on host.
 *
 * Warning! The protocol described in this file is experimental and backward
 * incompatible changes may be made. Backward compatible changes may be added
 * together with the corresponding interface version bump. Backward
 * incompatible changes are done by bumping the version number in the protocol
 * and interface names and resetting the interface version. Once the protocol
 * is to be declared stable, the 'z' prefix and the version number in the
 * protocol and interface names are removed and the interface version number is
 * reset.
 *
 * @section page_ifaces_notification_shell_unstable_v1 Interfaces
 * - @subpage page_iface_zcr_notification_shell_v1 - A notification window
 * - @subpage page_iface_zcr_notification_shell_surface_v1 - A notification window
 * @section page_copyright_notification_shell_unstable_v1 Copyright
 * <pre>
 *
 * Copyright 2018 The Chromium Authors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct wl_surface;
struct zcr_notification_shell_surface_v1;
struct zcr_notification_shell_v1;

/**
 * @page page_iface_zcr_notification_shell_v1 zcr_notification_shell_v1
 * @section page_iface_zcr_notification_shell_v1_desc Description
 *
 * An interface that is used for creating desktop notification on host.
 * @section page_iface_zcr_notification_shell_v1_api API
 * See @ref iface_zcr_notification_shell_v1.
 */
/**
 * @defgroup iface_zcr_notification_shell_v1 The zcr_notification_shell_v1 interface
 *
 * An interface that is used for creating desktop notification on host.
 */
extern const struct wl_interface zcr_notification_shell_v1_interface;
/**
 * @page page_iface_zcr_notification_shell_surface_v1 zcr_notification_shell_surface_v1
 * @section page_iface_zcr_notification_shell_surface_v1_desc Description
 *
 * An interface that may be implemented by a wl_surface to host
 * notification contents.
 * @section page_iface_zcr_notification_shell_surface_v1_api API
 * See @ref iface_zcr_notification_shell_surface_v1.
 */
/**
 * @defgroup iface_zcr_notification_shell_surface_v1 The zcr_notification_shell_surface_v1 interface
 *
 * An interface that may be implemented by a wl_surface to host
 * notification contents.
 */
extern const struct wl_interface zcr_notification_shell_surface_v1_interface;

#ifndef ZCR_NOTIFICATION_SHELL_V1_ERROR_ENUM
#define ZCR_NOTIFICATION_SHELL_V1_ERROR_ENUM
enum zcr_notification_shell_v1_error {
	/**
	 * invalid notification key
	 */
	ZCR_NOTIFICATION_SHELL_V1_ERROR_INVALID_NOTIFICATION_KEY = 1,
};
#endif /* ZCR_NOTIFICATION_SHELL_V1_ERROR_ENUM */

#define ZCR_NOTIFICATION_SHELL_V1_CREATE_NOTIFICATION 0
#define ZCR_NOTIFICATION_SHELL_V1_GET_NOTIFICATION_SURFACE 1


/**
 * @ingroup iface_zcr_notification_shell_v1
 */
#define ZCR_NOTIFICATION_SHELL_V1_CREATE_NOTIFICATION_SINCE_VERSION 1
/**
 * @ingroup iface_zcr_notification_shell_v1
 */
#define ZCR_NOTIFICATION_SHELL_V1_GET_NOTIFICATION_SURFACE_SINCE_VERSION 1

/** @ingroup iface_zcr_notification_shell_v1 */
static inline void
zcr_notification_shell_v1_set_user_data(struct zcr_notification_shell_v1 *zcr_notification_shell_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zcr_notification_shell_v1, user_data);
}

/** @ingroup iface_zcr_notification_shell_v1 */
static inline void *
zcr_notification_shell_v1_get_user_data(struct zcr_notification_shell_v1 *zcr_notification_shell_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zcr_notification_shell_v1);
}

static inline uint32_t
zcr_notification_shell_v1_get_version(struct zcr_notification_shell_v1 *zcr_notification_shell_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zcr_notification_shell_v1);
}

/** @ingroup iface_zcr_notification_shell_v1 */
static inline void
zcr_notification_shell_v1_destroy(struct zcr_notification_shell_v1 *zcr_notification_shell_v1)
{
	wl_proxy_destroy((struct wl_proxy *) zcr_notification_shell_v1);
}

/**
 * @ingroup iface_zcr_notification_shell_v1
 *
 * Creates a desktop notification from plain text information.
 */
static inline void
zcr_notification_shell_v1_create_notification(struct zcr_notification_shell_v1 *zcr_notification_shell_v1, const char *title, const char *message, const char *display_source, const char *notification_key)
{
	wl_proxy_marshal((struct wl_proxy *) zcr_notification_shell_v1,
			 ZCR_NOTIFICATION_SHELL_V1_CREATE_NOTIFICATION, title, message, display_source, notification_key);
}

/**
 * @ingroup iface_zcr_notification_shell_v1
 *
 * Creates a notification_surface for the given surface, gives it the
 * notification_surface role and associated it with a notification id.
 */
static inline struct zcr_notification_shell_surface_v1 *
zcr_notification_shell_v1_get_notification_surface(struct zcr_notification_shell_v1 *zcr_notification_shell_v1, struct wl_surface *surface, const char *notification_key)
{
	struct wl_proxy *id;

	id = wl_proxy_marshal_constructor((struct wl_proxy *) zcr_notification_shell_v1,
			 ZCR_NOTIFICATION_SHELL_V1_GET_NOTIFICATION_SURFACE, &zcr_notification_shell_surface_v1_interface, NULL, surface, notification_key);

	return (struct zcr_notification_shell_surface_v1 *) id;
}

#define ZCR_NOTIFICATION_SHELL_SURFACE_V1_DESTROY 0
#define ZCR_NOTIFICATION_SHELL_SURFACE_V1_SET_APP_ID 1


/**
 * @ingroup iface_zcr_notification_shell_surface_v1
 */
#define ZCR_NOTIFICATION_SHELL_SURFACE_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zcr_notification_shell_surface_v1
 */
#define ZCR_NOTIFICATION_SHELL_SURFACE_V1_SET_APP_ID_SINCE_VERSION 1

/** @ingroup iface_zcr_notification_shell_surface_v1 */
static inline void
zcr_notification_shell_surface_v1_set_user_data(struct zcr_notification_shell_surface_v1 *zcr_notification_shell_surface_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zcr_notification_shell_surface_v1, user_data);
}

/** @ingroup iface_zcr_notification_shell_surface_v1 */
static inline void *
zcr_notification_shell_surface_v1_get_user_data(struct zcr_notification_shell_surface_v1 *zcr_notification_shell_surface_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zcr_notification_shell_surface_v1);
}

static inline uint32_t
zcr_notification_shell_surface_v1_get_version(struct zcr_notification_shell_surface_v1 *zcr_notification_shell_surface_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zcr_notification_shell_surface_v1);
}

/**
 * @ingroup iface_zcr_notification_shell_surface_v1
 *
 * Unmap and destroy the notification surface.
 */
static inline void
zcr_notification_shell_surface_v1_destroy(struct zcr_notification_shell_surface_v1 *zcr_notification_shell_surface_v1)
{
	wl_proxy_marshal((struct wl_proxy *) zcr_notification_shell_surface_v1,
			 ZCR_NOTIFICATION_SHELL_SURFACE_V1_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) zcr_notification_shell_surface_v1);
}

/**
 * @ingroup iface_zcr_notification_shell_surface_v1
 *
 * Set an application identifier for the notification surface.
 */
static inline void
zcr_notification_shell_surface_v1_set_app_id(struct zcr_notification_shell_surface_v1 *zcr_notification_shell_surface_v1, const char *app_id)
{
	wl_proxy_marshal((struct wl_proxy *) zcr_notification_shell_surface_v1,
			 ZCR_NOTIFICATION_SHELL_SURFACE_V1_SET_APP_ID, app_id);
}

#ifdef  __cplusplus
}
#endif

#endif
