// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _LIBGNOMECANVASMM_RECT_H
#define _LIBGNOMECANVASMM_RECT_H


#include <glibmm.h>

/* $Id: rect.hg,v 1.5 2002/04/01 16:54:22 murrayc Exp $ */

/* rect.h
 * 
 * Copyright (C) 1998 EMC Capital Management Inc.
 * Developed by Havoc Pennington <hp@pobox.com>
 *
 * Copyright (C) 1999 The Gtk-- Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <libgnomecanvasmm/item.h>
#include <libgnomecanvasmm/group.h>
#include <libgnomecanvasmm/rect-ellipse.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GnomeCanvasRect GnomeCanvasRect;
typedef struct _GnomeCanvasRectClass GnomeCanvasRectClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gnome
{

namespace Canvas
{ class Rect_Class; } // namespace Canvas

} // namespace Gnome
namespace Gnome
{

namespace Canvas
{

//class Group;


class Rect : public RectEllipse
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Rect CppObjectType;
  typedef Rect_Class CppClassType;
  typedef GnomeCanvasRect BaseObjectType;
  typedef GnomeCanvasRectClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~Rect();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Rect_Class;
  static CppClassType rect_class_;

  // noncopyable
  Rect(const Rect&);
  Rect& operator=(const Rect&);

protected:
  explicit Rect(const Glib::ConstructParams& construct_params);
  explicit Rect(GnomeCanvasRect* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GnomeCanvasRect*       gobj()       { return reinterpret_cast<GnomeCanvasRect*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GnomeCanvasRect* gobj() const { return reinterpret_cast<GnomeCanvasRect*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:


public:
  Rect(Group& parent, double x1, double y1, double x2, double y2);
  explicit Rect(Group& parent);


};

} /* namespace Canvas */
} /* namespace Gnome */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gnome::Canvas::Rect
   */
  Gnome::Canvas::Rect* wrap(GnomeCanvasRect* object, bool take_copy = false);
} //namespace Glib


#endif /* _LIBGNOMECANVASMM_RECT_H */

