// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _LIBGNOMECANVASMM_POLYGON_H
#define _LIBGNOMECANVASMM_POLYGON_H


#include <glibmm.h>

/* $Id: polygon.hg,v 1.5 2002/04/01 16:54:22 murrayc Exp $ */


/* polygon.hg
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

#include <libgnomecanvasmm/shape.h>
#include <libgnomecanvasmm/line.h>
#include <libgnomecanvas/gnome-canvas-polygon.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GnomeCanvasPolygon GnomeCanvasPolygon;
typedef struct _GnomeCanvasPolygonClass GnomeCanvasPolygonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gnome
{

namespace Canvas
{ class Polygon_Class; } // namespace Canvas

} // namespace Gnome
namespace Gnome
{

namespace Canvas
{


class Polygon : public Shape
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Polygon CppObjectType;
  typedef Polygon_Class CppClassType;
  typedef GnomeCanvasPolygon BaseObjectType;
  typedef GnomeCanvasPolygonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~Polygon();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Polygon_Class;
  static CppClassType polygon_class_;

  // noncopyable
  Polygon(const Polygon&);
  Polygon& operator=(const Polygon&);

protected:
  explicit Polygon(const Glib::ConstructParams& construct_params);
  explicit Polygon(GnomeCanvasPolygon* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GnomeCanvasPolygon*       gobj()       { return reinterpret_cast<GnomeCanvasPolygon*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GnomeCanvasPolygon* gobj() const { return reinterpret_cast<GnomeCanvasPolygon*>(gobject_); }


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
  Polygon(Group& parent, const Points& points);
  explicit Polygon(Group& parent);

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Points> property_points() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Points> property_points() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


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
   * @relates Gnome::Canvas::Polygon
   */
  Gnome::Canvas::Polygon* wrap(GnomeCanvasPolygon* object, bool take_copy = false);
} //namespace Glib


#endif /* _LIBGNOMECANVASMM_POLYGON_H */

