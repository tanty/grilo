/*
 * Copyright (C) 2010 Stefan Kost <ensonic@users.sf.net>
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

#undef G_DISABLE_ASSERT
#undef G_LOG_DOMAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#include <grilo.h>

static void
registry_init (void)
{
  GrlPluginRegistry *registry;

  registry = grl_plugin_registry_get_instance ();
  g_assert (registry);
}

static void
registry_load (void)
{
  GrlPluginRegistry *registry;
  gboolean res;

  registry = grl_plugin_registry_get_instance ();
  res = grl_plugin_registry_load_all (registry);
  g_assert_cmpint (res, ==, TRUE);
}

int
main (int argc, char *argv[])
{
  g_type_init ();
  g_test_init (&argc, &argv, NULL);

  //g_test_bug_base ("http://bugs.gnome.org/%s");

  /* registry tests */
  g_test_add_func ("/registry/init", registry_init);
  g_test_add_func ("/registry/load", registry_load);

  return g_test_run ();
}
