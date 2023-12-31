// Generated by gtkmmproc -- DO NOT MODIFY!


#include <libgnomecanvasmm/rect.h>
#include <libgnomecanvasmm/private/rect_p.h>

/* $Id: rect.ccg,v 1.1 2002/02/24 20:41:19 murrayc Exp $ */

/* rect.c
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

Rect::Rect(Group& parentx, double x1, double y1, double x2, double y2)
: RectEllipse(GNOME_CANVAS_RE(g_object_new(get_type(),0)))
{
  item_construct(parentx);
  set("x1",x1,"y1",y1,"x2",x2,"y2",y2,0);
}

Rect::Rect(Group& parentx)
: RectEllipse(GNOME_CANVAS_RE(g_object_new(get_type(),0)))
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

Gnome::Canvas::Rect* wrap(GnomeCanvasRect* object, bool take_copy)
{
  return dynamic_cast<Gnome::Canvas::Rect *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gnome
{

namespace Canvas
{


/* The *_Class implementation: */

const Glib::Class& Rect_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Rect_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gnome_canvas_rect_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void Rect_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* Rect_Class::wrap_new(GObject* o)
{
  return manage(new Rect((GnomeCanvasRect*)(o)));

}


/* The implementation: */

Rect::Rect(const Glib::ConstructParams& construct_params)
:
  RectEllipse(construct_params)
{
  }

Rect::Rect(GnomeCanvasRect* castitem)
:
  RectEllipse((GnomeCanvasRE*)(castitem))
{
  }

Rect::~Rect()
{
  destroy_();
}

Rect::CppClassType Rect::rect_class_; // initialize static member

GType Rect::get_type()
{
  return rect_class_.init().get_type();
}

GType Rect::get_base_type()
{
  return gnome_canvas_rect_get_type();
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Canvas

} // namespace Gnome


