// Generated by gtkmmproc -- DO NOT MODIFY!


#include <libgnomecanvasmm/ellipse.h>
#include <libgnomecanvasmm/private/ellipse_p.h>

// -*- C++ -*-
/* $Id: ellipse.ccg,v 1.1 2002/02/24 20:41:19 murrayc Exp $ */

/* ellipse.cc
 *
 * Copyright (C) 1998 EMC Capital Management Inc.
 * Developed by Havoc Pennington <hp@pobox.com>
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

Ellipse::Ellipse(Group& parentx, double x1, double y1, double x2, double y2)
 : RectEllipse(GNOME_CANVAS_RE(g_object_new(get_type(), 0)))
{
  item_construct(parentx);
  set("x1",x1,"y1",y1,"x2",x2,"y2",y2,0);
}

Ellipse::Ellipse(Group& parentx)
  : RectEllipse(GNOME_CANVAS_RE(g_object_new(get_type(), 0)))
{
  item_construct(parentx);
}

} /* namespace Canvas */
} /* namespace Gnome */

namespace
{
} // anonymous namespace


namespace Glib
{

Gnome::Canvas::Ellipse* wrap(GnomeCanvasEllipse* object, bool take_copy)
{
  return dynamic_cast<Gnome::Canvas::Ellipse *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gnome
{

namespace Canvas
{


/* The *_Class implementation: */

const Glib::Class& Ellipse_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Ellipse_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gnome_canvas_ellipse_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void Ellipse_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* Ellipse_Class::wrap_new(GObject* o)
{
  return manage(new Ellipse((GnomeCanvasEllipse*)(o)));

}


/* The implementation: */

Ellipse::Ellipse(const Glib::ConstructParams& construct_params)
:
  RectEllipse(construct_params)
{
  }

Ellipse::Ellipse(GnomeCanvasEllipse* castitem)
:
  RectEllipse((GnomeCanvasRE*)(castitem))
{
  }

Ellipse::~Ellipse()
{
  destroy_();
}

Ellipse::CppClassType Ellipse::ellipse_class_; // initialize static member

GType Ellipse::get_type()
{
  return ellipse_class_.init().get_type();
}

GType Ellipse::get_base_type()
{
  return gnome_canvas_ellipse_get_type();
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Canvas

} // namespace Gnome


