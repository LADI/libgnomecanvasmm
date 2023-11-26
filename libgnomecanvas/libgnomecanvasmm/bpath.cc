// Generated by gtkmmproc -- DO NOT MODIFY!


#include <libgnomecanvasmm/bpath.h>
#include <libgnomecanvasmm/private/bpath_p.h>

/* bpath.cc
 *
 * Copyright (C) 2002 The libgnomecanvasmm Development Team
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


Bpath::Bpath(Group& parent)
  : Shape(GNOME_CANVAS_SHAPE(g_object_new(get_type(),0)))
{
  item_construct(parent);
}


void Bpath::set_bpath(const Glib::RefPtr<PathDef>& path)
{
  property_bpath().set_value(path->gobj());
}


} /* namespace Canvas */

} /* namespace Gnome */

namespace
{
} // anonymous namespace


namespace Glib
{

Gnome::Canvas::Bpath* wrap(GnomeCanvasBpath* object, bool take_copy)
{
  return dynamic_cast<Gnome::Canvas::Bpath *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gnome
{

namespace Canvas
{


/* The *_Class implementation: */

const Glib::Class& Bpath_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Bpath_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gnome_canvas_bpath_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void Bpath_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* Bpath_Class::wrap_new(GObject* o)
{
  return manage(new Bpath((GnomeCanvasBpath*)(o)));

}


/* The implementation: */

Bpath::Bpath(const Glib::ConstructParams& construct_params)
:
  Shape(construct_params)
{
  }

Bpath::Bpath(GnomeCanvasBpath* castitem)
:
  Shape((GnomeCanvasShape*)(castitem))
{
  }

Bpath::~Bpath()
{
  destroy_();
}

Bpath::CppClassType Bpath::bpath_class_; // initialize static member

GType Bpath::get_type()
{
  return bpath_class_.init().get_type();
}

GType Bpath::get_base_type()
{
  return gnome_canvas_bpath_get_type();
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<GnomeCanvasPathDef*> Bpath::property_bpath() 
{
  return Glib::PropertyProxy<GnomeCanvasPathDef*>(this, "bpath");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<GnomeCanvasPathDef*> Bpath::property_bpath() const
{
  return Glib::PropertyProxy_ReadOnly<GnomeCanvasPathDef*>(this, "bpath");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Canvas

} // namespace Gnome


