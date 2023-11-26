// Generated by gtkmmproc -- DO NOT MODIFY!


#include <libgnomecanvasmm/widget.h>
#include <libgnomecanvasmm/private/widget_p.h>

/* $Id: widget.ccg,v 1.1 2002/02/24 20:41:19 murrayc Exp $ */

/* widget.cc
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
#include <stdarg.h>
#include <gtkmm/widget.h>

namespace Gnome
{

namespace Canvas
{

Widget::Widget(Group& parentx, double x, double y,
                           Gtk::Widget& w)
  : Item(GNOME_CANVAS_ITEM(g_object_new(get_type(),0)))
{
  item_construct(parentx);
  set("x", x, "y", y, "widget",w.gobj(), 0);
}

Widget::Widget(Group& parentx)
  : Item(GNOME_CANVAS_ITEM(g_object_new(get_type(),0)))
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

Gnome::Canvas::Widget* wrap(GnomeCanvasWidget* object, bool take_copy)
{
  return dynamic_cast<Gnome::Canvas::Widget *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gnome
{

namespace Canvas
{


/* The *_Class implementation: */

const Glib::Class& Widget_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Widget_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gnome_canvas_widget_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void Widget_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* Widget_Class::wrap_new(GObject* o)
{
  return manage(new Widget((GnomeCanvasWidget*)(o)));

}


/* The implementation: */

Widget::Widget(const Glib::ConstructParams& construct_params)
:
  Item(construct_params)
{
  }

Widget::Widget(GnomeCanvasWidget* castitem)
:
  Item((GnomeCanvasItem*)(castitem))
{
  }

Widget::~Widget()
{
  destroy_();
}

Widget::CppClassType Widget::widget_class_; // initialize static member

GType Widget::get_type()
{
  return widget_class_.init().get_type();
}

GType Widget::get_base_type()
{
  return gnome_canvas_widget_get_type();
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Gtk::Widget*> Widget::property_widget() 
{
  return Glib::PropertyProxy<Gtk::Widget*>(this, "widget");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Gtk::Widget*> Widget::property_widget() const
{
  return Glib::PropertyProxy_ReadOnly<Gtk::Widget*>(this, "widget");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<double> Widget::property_x() 
{
  return Glib::PropertyProxy<double>(this, "x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<double> Widget::property_x() const
{
  return Glib::PropertyProxy_ReadOnly<double>(this, "x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<double> Widget::property_y() 
{
  return Glib::PropertyProxy<double>(this, "y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<double> Widget::property_y() const
{
  return Glib::PropertyProxy_ReadOnly<double>(this, "y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<double> Widget::property_width() 
{
  return Glib::PropertyProxy<double>(this, "width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<double> Widget::property_width() const
{
  return Glib::PropertyProxy_ReadOnly<double>(this, "width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<double> Widget::property_height() 
{
  return Glib::PropertyProxy<double>(this, "height");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<double> Widget::property_height() const
{
  return Glib::PropertyProxy_ReadOnly<double>(this, "height");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Gtk::AnchorType> Widget::property_anchor() 
{
  return Glib::PropertyProxy<Gtk::AnchorType>(this, "anchor");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Gtk::AnchorType> Widget::property_anchor() const
{
  return Glib::PropertyProxy_ReadOnly<Gtk::AnchorType>(this, "anchor");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> Widget::property_size_pixels() 
{
  return Glib::PropertyProxy<bool>(this, "size-pixels");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> Widget::property_size_pixels() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "size-pixels");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Canvas

} // namespace Gnome


