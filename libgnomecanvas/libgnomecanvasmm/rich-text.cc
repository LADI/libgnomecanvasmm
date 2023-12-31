// Generated by gtkmmproc -- DO NOT MODIFY!


#include <libgnomecanvasmm/rich-text.h>
#include <libgnomecanvasmm/private/rich-text_p.h>

/* $Id: rich-text.ccg,v 1.3 2002/12/09 16:08:51 aholzmann Exp $ */

/* rich-text.cc
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

RichText::RichText (Group& parent,
                    double x, double y, 
                    const Glib::ustring& text)
  : Item (GNOME_CANVAS_ITEM (g_object_new (get_type (), NULL)))
{
  item_construct (parent);
  set ("x", x, 
       "y", y, 
       "text", text.c_str (), 
       NULL);
}

RichText::RichText (Group& parent)
  : Item (GNOME_CANVAS_ITEM (g_object_new (get_type (), NULL)))
{
  item_construct (parent);
}

RichText::iterator RichText::get_iter_at_location(int x, int y) const
{
  iterator iter;
  gnome_canvas_rich_text_get_iter_at_location(const_cast<GnomeCanvasRichText*>(gobj()), iter.gobj(), x, y);
  return iter;
}


}

}


namespace
{


static void RichText_signal_tag_changed_callback(GnomeCanvasRichText* self, GtkTextTag* p0,void* data)
{
  using namespace Gnome::Canvas;
  typedef sigc::slot< void,const Glib::RefPtr<Gtk::TextTag>& > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo RichText_signal_tag_changed_info =
{
  "tag_changed",
  (GCallback) &RichText_signal_tag_changed_callback,
  (GCallback) &RichText_signal_tag_changed_callback
};


} // anonymous namespace


namespace Glib
{

Gnome::Canvas::RichText* wrap(GnomeCanvasRichText* object, bool take_copy)
{
  return dynamic_cast<Gnome::Canvas::RichText *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gnome
{

namespace Canvas
{


/* The *_Class implementation: */

const Glib::Class& RichText_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &RichText_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gnome_canvas_rich_text_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void RichText_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->tag_changed = &tag_changed_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void RichText_Class::tag_changed_callback(GnomeCanvasRichText* self, GtkTextTag* p0)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_tag_changed(Glib::wrap(p0, true)
);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }
  
  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->tag_changed)
    (*base->tag_changed)(self, p0);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* RichText_Class::wrap_new(GObject* o)
{
  return manage(new RichText((GnomeCanvasRichText*)(o)));

}


/* The implementation: */

RichText::RichText(const Glib::ConstructParams& construct_params)
:
  Item(construct_params)
{
  }

RichText::RichText(GnomeCanvasRichText* castitem)
:
  Item((GnomeCanvasItem*)(castitem))
{
  }

RichText::~RichText()
{
  destroy_();
}

RichText::CppClassType RichText::richtext_class_; // initialize static member

GType RichText::get_type()
{
  return richtext_class_.init().get_type();
}

GType RichText::get_base_type()
{
  return gnome_canvas_rich_text_get_type();
}


void RichText::cut_clipboard()
{
gnome_canvas_rich_text_cut_clipboard(gobj()); 
}

void RichText::copy_clipboard()
{
gnome_canvas_rich_text_copy_clipboard(gobj()); 
}

void RichText::paste_clipboard()
{
gnome_canvas_rich_text_paste_clipboard(gobj()); 
}

void RichText::set_buffer(const Glib::RefPtr<Gtk::TextBuffer>& buffer)
{
gnome_canvas_rich_text_set_buffer(gobj(), Glib::unwrap(buffer)); 
}

Glib::RefPtr<Gtk::TextBuffer> RichText::get_buffer() const
{
  return Glib::wrap(gnome_canvas_rich_text_get_buffer(const_cast<GnomeCanvasRichText*>(gobj())));
}

void RichText::get_iter_location(const iterator& iter, Gdk::Rectangle& location) const
{
gnome_canvas_rich_text_get_iter_location(const_cast<GnomeCanvasRichText*>(gobj()), (iter).gobj(), (location).gobj()); 
}


Glib::SignalProxy1< void,const Glib::RefPtr<Gtk::TextTag>& > RichText::signal_tag_changed()
{
  return Glib::SignalProxy1< void,const Glib::RefPtr<Gtk::TextTag>& >(this, &RichText_signal_tag_changed_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Glib::ustring> RichText::property_text() 
{
  return Glib::PropertyProxy<Glib::ustring>(this, "text");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Glib::ustring> RichText::property_text() const
{
  return Glib::PropertyProxy_ReadOnly<Glib::ustring>(this, "text");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<double> RichText::property_x() 
{
  return Glib::PropertyProxy<double>(this, "x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<double> RichText::property_x() const
{
  return Glib::PropertyProxy_ReadOnly<double>(this, "x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<double> RichText::property_y() 
{
  return Glib::PropertyProxy<double>(this, "y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<double> RichText::property_y() const
{
  return Glib::PropertyProxy_ReadOnly<double>(this, "y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<double> RichText::property_width() 
{
  return Glib::PropertyProxy<double>(this, "width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<double> RichText::property_width() const
{
  return Glib::PropertyProxy_ReadOnly<double>(this, "width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<double> RichText::property_height() 
{
  return Glib::PropertyProxy<double>(this, "height");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<double> RichText::property_height() const
{
  return Glib::PropertyProxy_ReadOnly<double>(this, "height");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> RichText::property_editable() 
{
  return Glib::PropertyProxy<bool>(this, "editable");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> RichText::property_editable() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "editable");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> RichText::property_visible() 
{
  return Glib::PropertyProxy<bool>(this, "visible");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> RichText::property_visible() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "visible");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> RichText::property_cursor_visible() 
{
  return Glib::PropertyProxy<bool>(this, "cursor-visible");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> RichText::property_cursor_visible() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "cursor-visible");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> RichText::property_cursor_blink() 
{
  return Glib::PropertyProxy<bool>(this, "cursor-blink");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> RichText::property_cursor_blink() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "cursor-blink");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> RichText::property_grow_height() 
{
  return Glib::PropertyProxy<bool>(this, "grow-height");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> RichText::property_grow_height() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "grow-height");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Gtk::WrapMode> RichText::property_wrap_mode() 
{
  return Glib::PropertyProxy<Gtk::WrapMode>(this, "wrap-mode");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Gtk::WrapMode> RichText::property_wrap_mode() const
{
  return Glib::PropertyProxy_ReadOnly<Gtk::WrapMode>(this, "wrap-mode");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Gtk::Justification> RichText::property_justification() 
{
  return Glib::PropertyProxy<Gtk::Justification>(this, "justification");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Gtk::Justification> RichText::property_justification() const
{
  return Glib::PropertyProxy_ReadOnly<Gtk::Justification>(this, "justification");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Gtk::DirectionType> RichText::property_direction() 
{
  return Glib::PropertyProxy<Gtk::DirectionType>(this, "direction");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Gtk::DirectionType> RichText::property_direction() const
{
  return Glib::PropertyProxy_ReadOnly<Gtk::DirectionType>(this, "direction");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Gtk::AnchorType> RichText::property_anchor() 
{
  return Glib::PropertyProxy<Gtk::AnchorType>(this, "anchor");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Gtk::AnchorType> RichText::property_anchor() const
{
  return Glib::PropertyProxy_ReadOnly<Gtk::AnchorType>(this, "anchor");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> RichText::property_pixels_above_lines() 
{
  return Glib::PropertyProxy<int>(this, "pixels-above-lines");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> RichText::property_pixels_above_lines() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "pixels-above-lines");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> RichText::property_pixels_below_lines() 
{
  return Glib::PropertyProxy<int>(this, "pixels-below-lines");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> RichText::property_pixels_below_lines() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "pixels-below-lines");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> RichText::property_pixels_inside_wrap() 
{
  return Glib::PropertyProxy<int>(this, "pixels-inside-wrap");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> RichText::property_pixels_inside_wrap() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "pixels-inside-wrap");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> RichText::property_left_margin() 
{
  return Glib::PropertyProxy<int>(this, "left-margin");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> RichText::property_left_margin() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "left-margin");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> RichText::property_right_margin() 
{
  return Glib::PropertyProxy<int>(this, "right-margin");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> RichText::property_right_margin() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "right-margin");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> RichText::property_indent() 
{
  return Glib::PropertyProxy<int>(this, "indent");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> RichText::property_indent() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "indent");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gnome::Canvas::RichText::on_tag_changed(const Glib::RefPtr<Gtk::TextTag>& tag)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->tag_changed)
    (*base->tag_changed)(gobj(),Glib::unwrap(tag));
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Canvas

} // namespace Gnome


