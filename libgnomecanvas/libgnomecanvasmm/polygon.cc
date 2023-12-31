// Generated by gtkmmproc -- DO NOT MODIFY!


#include <libgnomecanvasmm/polygon.h>
#include <libgnomecanvasmm/private/polygon_p.h>

/* $Id: polygon.ccg,v 1.1 2002/02/24 20:41:19 murrayc Exp $ */

/* polygon.ccg
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

namespace Gnome
{

namespace Canvas
{

Polygon::Polygon(Group& parent,const Points& points)
  : Shape(GNOME_CANVAS_SHAPE(g_object_new(get_type(),0)))
{
  item_construct(parent);
  property_points().set_value(points);
}

Polygon::Polygon(Group& parent)
    : Shape(GNOME_CANVAS_SHAPE(g_object_new(get_type(),0)))
{
  item_construct(parent);
}

} /* namespace Canvas */
} /* namespace Gnome */


namespace
{
} // anonymous namespace


namespace Glib
{

Gnome::Canvas::Polygon* wrap(GnomeCanvasPolygon* object, bool take_copy)
{
  return dynamic_cast<Gnome::Canvas::Polygon *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gnome
{

namespace Canvas
{


/* The *_Class implementation: */

const Glib::Class& Polygon_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Polygon_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gnome_canvas_polygon_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void Polygon_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* Polygon_Class::wrap_new(GObject* o)
{
  return manage(new Polygon((GnomeCanvasPolygon*)(o)));

}


/* The implementation: */

Polygon::Polygon(const Glib::ConstructParams& construct_params)
:
  Shape(construct_params)
{
  }

Polygon::Polygon(GnomeCanvasPolygon* castitem)
:
  Shape((GnomeCanvasShape*)(castitem))
{
  }

Polygon::~Polygon()
{
  destroy_();
}

Polygon::CppClassType Polygon::polygon_class_; // initialize static member

GType Polygon::get_type()
{
  return polygon_class_.init().get_type();
}

GType Polygon::get_base_type()
{
  return gnome_canvas_polygon_get_type();
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Points> Polygon::property_points() 
{
  return Glib::PropertyProxy<Points>(this, "points");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Points> Polygon::property_points() const
{
  return Glib::PropertyProxy_ReadOnly<Points>(this, "points");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Canvas

} // namespace Gnome


