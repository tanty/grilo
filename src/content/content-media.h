/*
 * Copyright (C) 2010 Igalia S.L.
 *
 * Contact: Iago Toral Quiroga <itoral@igalia.com>
 *
 * Authors: Juan A. Suarez Romero <jasuarez@igalia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef __CONTENT_MEDIA_H__
#define __CONTENT_MEDIA_H__

#include "content.h"


G_BEGIN_DECLS

#define CONTENT_TYPE_MEDIA                                              \
   (content_media_get_type())
#define CONTENT_MEDIA(obj)                                              \
   (G_TYPE_CHECK_INSTANCE_CAST ((obj),                                  \
                                CONTENT_TYPE_MEDIA,                     \
                                ContentMedia))
#define CONTENT_MEDIA_CLASS(klass)                                      \
   (G_TYPE_CHECK_CLASS_CAST ((klass),                                   \
                             CONTENT_TYPE_MEDIA,                        \
                             ContentMediaClass))
#define IS_CONTENT_MEDIA(obj)                                           \
   (G_TYPE_CHECK_INSTANCE_TYPE ((obj),                                  \
                                CONTENT_TYPE_MEDIA))
#define IS_CONTENT_MEDIA_CLASS(klass)                                   \
   (G_TYPE_CHECK_CLASS_TYPE ((klass),                                   \
                             CONTENT_TYPE_MEDIA))
#define CONTENT_MEDIA_GET_CLASS(obj)                                    \
   (G_TYPE_INSTANCE_GET_CLASS ((obj),                                   \
                               CONTENT_TYPE_MEDIA,                      \
                               ContentMediaClass))

typedef struct _ContentMedia      ContentMedia;
typedef struct _ContentMediaClass ContentMediaClass;

struct _ContentMediaClass
{
    ContentClass parent_class;
};

struct _ContentMedia
{
    Content parent;
};

#define content_media_set_id(content, id) \
  content_set_string(CONTENT((content)), METADATA_KEY_ID, (id))
#define content_media_set_url(content, url) \
  content_set_string(CONTENT((content)), METADATA_KEY_URL, (url))
#define content_media_set_author(content, author) \
  content_set_string(CONTENT((content)), METADATA_KEY_AUTHOR, (author))
#define content_media_set_title(content, title) \
  content_set_string(CONTENT((content)), METADATA_KEY_TITLE, (title))
#define content_media_set_description(content, description) \
  content_set_string(CONTENT((content)), METADATA_KEY_DESCRIPTION, (description))
#define content_media_set_source(content, source) \
  content_set_string(CONTENT((content)), METADATA_KEY_SOURCE, (source))
#define content_media_set_thumbnail(content, thumbnail) \
  content_set_string(CONTENT((content)), METADATA_KEY_THUMBNAIL, (thumbnail))

#define content_media_get_id(content) \
  content_get_string(CONTENT((content)), METADATA_KEY_ID)
#define content_media_get_url(content) \
  content_get_string(CONTENT((content)), METADATA_KEY_URL)
#define content_media_get_author(content) \
  content_get_string(CONTENT((content)), METADATA_KEY_AUTHOR)
#define content_media_get_title(content) \
  content_get_string(CONTENT((content)), METADATA_KEY_TITLE)
#define content_media_get_description(content) \
  content_get_string(CONTENT((content)), METADATA_KEY_DESCRIPTION)
#define content_media_get_source(content) \
  content_get_string(CONTENT((content)), METADATA_KEY_SOURCE)
#define content_media_get_thumbnail(content) \
  content_get_string(CONTENT((content)), METADATA_KEY_THUMBNAIL)

GType content_media_get_type (void) G_GNUC_CONST;
ContentMedia *content_media_new (void);

G_END_DECLS

#endif /* __CONTENT_MEDIA_H__ */
