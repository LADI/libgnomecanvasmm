#ifndef _LIBGNOMECANVASMM_CANVAS_PROPERTY_H_
#define _LIBGNOMECANVASMM_CANVAS_PROPERTY_H_

// -*- c++ -*-
/* $Id$ */

/* canvas-property.h
 *
 * Copyright (C) 1999-2002 The Free Software Foundation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

//#include <gtk/gtkpacker.h> //For GtkAnchorType.

#include <glibmm/propertyproxy.h>
#include <gdkmm/color.h>
#include <gdkmm/pixmap.h>
#include <pangomm/fontdescription.h>
#include <gtk/gtkenums.h>

namespace Gnome
{

namespace Canvas
{

namespace Properties
{

//TODO: Put implementation in a .cc file:
class PropertyBase
{
public:
  PropertyBase(const char* name);
  ~PropertyBase();

  const char* get_name() const;

protected:
  const char* name_;
};

template <class T_Value>
class Property : public PropertyBase
{
public:
  Property(const char* name, const T_Value& value)
  : PropertyBase(name), value_(value)
  {}

  void set_value_in_object(Glib::Object& object) const
  {
    Glib::PropertyProxy<T_Value> proxy(&object, get_name());
    proxy.set_value(value_);
  }

protected:
  T_Value value_;
};


/** Allow use of << operator on objects:
  * For instance:
  * canvasgroup << Gnome::Canvas::CanvasHelpers::x(2);
  */
template <class O, class T>
O& operator << (O& object, const Property<T>& property)
{
  property.set_value_in_object(object);
  return object;
}

/********* specializations *********/

//Colors can be specified with a string or a Gdk::Color, or an rgba guint.
//TODO: Put implementation in a .cc file.
template<>
class Property<Gdk::Color> : public PropertyBase
{
public:
  Property(const char* name, const Gdk::Color& value)
    : PropertyBase(name), value_(value), value_gobj_used_(true), value_rgba_(0)
  {}

  Property(const char* name, const Glib::ustring& color)
    : PropertyBase(name), value_gobj_used_(false), value_string_(color), value_rgba_(0)
  {}

  Property(const char* name, const guint& rgba_color)
    : PropertyBase(name), value_gobj_used_(false), value_rgba_(rgba_color)
  {}

  void set_value_in_object(Glib::Object& object) const
  {
    //Set the appropriate property name with the appropriately-typed value:
    if(value_string_.size())
    {
      Glib::PropertyProxy<Glib::ustring> proxy(&object, get_name());
      proxy.set_value(value_string_);
    }
    else if(value_gobj_used_)
    {
      Glib::PropertyProxy_Boxed<Gdk::Color> proxy(&object, get_name());
      proxy.set_value(value_);
    }
    else
    {
      Glib::PropertyProxy<guint> proxy(&object, get_name());
      proxy.set_value(value_rgba_);
    }
  }

protected:
  Gdk::Color value_;
  bool value_gobj_used_; //Whether the Gdk::Value was intialised in the constructor.
  Glib::ustring value_string_;
  guint value_rgba_;
};

//Font can be specified with a string or a Pango::FontDescription.
template<>
class Property<Pango::FontDescription> : public PropertyBase
{
public:
  Property(const char* name, const Pango::FontDescription& value)
    : PropertyBase(name), value_(value)
  {}

  Property(const char* name, const Glib::ustring& font)
    : PropertyBase(name), value_(0), value_string_(font)
  {}

  void set_value_in_object(Glib::Object& object) const
  {
    if(value_string_.size())
    {
      Glib::PropertyProxy<Glib::ustring> proxy(&object, get_name());
      proxy.set_value(value_string_);
    }
    else
    {
      Glib::PropertyProxy_Boxed<Pango::FontDescription> proxy(&object, get_name());
      proxy.set_value(value_);
    }
  }

protected:
  Pango::FontDescription value_;
  Glib::ustring value_string_;
};


//We now define some specific properties.
//Some of these are unusual, so we define them manually.
//Others are regular so we define them with a macro:


class font : public Property<Pango::FontDescription>  //Used by CanvasText.
{
public:
  font(const Pango::FontDescription& v)
  : Property<Pango::FontDescription>("font-desc", v)
  {}

  font(const Glib::ustring& v)
  : Property<Pango::FontDescription>("font", v)
  {}
};

template<>
class Property< Glib::RefPtr<Gdk::Pixmap> >  : public PropertyBase
{
public:
  Property(const char* name, const Glib::RefPtr<Gdk::Pixmap>& value)
  : PropertyBase(name), value_(value)
  {}

  void set_value_in_object(Glib::Object& object) const
  {
    Glib::PropertyProxy_RefPtr<Gdk::Pixmap> proxy(&object, get_name());
    proxy.set_value(value_);
  }

protected:
  Glib::RefPtr<Gdk::Pixmap> value_;
};

class fill_color : public Property<Gdk::Color>
{
public:
  fill_color(const Gdk::Color& v)
  : Property<Gdk::Color>("fill_color_gdk",v)
  {}

  fill_color(const Glib::ustring& v)
  : Property<Gdk::Color>("fill_color",v)
  {}
};

class outline_color : public Property<Gdk::Color>
{
public:
  outline_color(const Gdk::Color& v)
  : Property<Gdk::Color>("outline_color_gdk", v)
  {}

  outline_color(const Glib::ustring& v)
  : Property<Gdk::Color>("outline_color", v)
  {}
};


// GNOMEMM_PROPERTY(C++ name, C property name, C++ type)
#define GNOMEMM_PROPERTY(N,N2,T) \
class N : public Property<T> \
{ \
public: \
  N(const T& v) \
  : Property<T>(#N2, v) \
  {} \
};


// CanvasLine
GNOMEMM_PROPERTY(arrow_shape_a,arrow_shape_a,double)
GNOMEMM_PROPERTY(arrow_shape_b,arrow_shape_b,double)
GNOMEMM_PROPERTY(arrow_shape_c,arrow_shape_c,double)
GNOMEMM_PROPERTY(cap_style,cap_style,GdkCapStyle)
GNOMEMM_PROPERTY(first_arrowhead,first_arrowhead,bool)
GNOMEMM_PROPERTY(join_style,join_style,GdkJoinStyle)
GNOMEMM_PROPERTY(last_arrowhead,last_arrowhead,bool)
GNOMEMM_PROPERTY(line_stype,line_style,GdkLineStyle)
GNOMEMM_PROPERTY(smooth,smooth,bool)
GNOMEMM_PROPERTY(spline_step,spline_step,guint)

// CanvasText
GNOMEMM_PROPERTY(clip,clip,bool)
GNOMEMM_PROPERTY(clip_height,clip_height,double)
GNOMEMM_PROPERTY(clip_width,clip_width,double)
GNOMEMM_PROPERTY(justification,justification,GtkJustification)
GNOMEMM_PROPERTY(text_height,text_height,double)
GNOMEMM_PROPERTY(text_width,text_width,double)
GNOMEMM_PROPERTY(x_offset,x_offset,double)
GNOMEMM_PROPERTY(y_offset,y_offset,double)
//FIXME: fontset

// CanvasWidget
GNOMEMM_PROPERTY(size_pixels,size_pixels,bool)

// CanvasImage, CanvasWidget
GNOMEMM_PROPERTY(height,height,double)
GNOMEMM_PROPERTY(width,width,double)

// CanvasRect, CanvasEllipse
GNOMEMM_PROPERTY(x1,x1,double)
GNOMEMM_PROPERTY(x2,x2,double)
GNOMEMM_PROPERTY(y1,y1,double)
GNOMEMM_PROPERTY(y2,y2,double)

// CanvasImage, CanvasText, CanvasWidget
GNOMEMM_PROPERTY(anchor,anchor,GtkAnchorType)

// CanvasPolygon, CanvasRect, CanvasEllipse
GNOMEMM_PROPERTY(outline_stipple,outline_stipple,Glib::RefPtr<Gdk::Pixmap>)

// CanvasLine, CanvasPolygon, CanvasRect, CanvasEllipse
GNOMEMM_PROPERTY(width_pixels,width_pixels,guint)
GNOMEMM_PROPERTY(width_units,width_units,double)

// CanvasGroup, CanvasImage, CanvasText, CanvasWidget
GNOMEMM_PROPERTY(x,x,double)
GNOMEMM_PROPERTY(y,y,double)

// CanvasLine, CanvasPolygon, CanvasRect, CanvasEllipse, CanvasText
GNOMEMM_PROPERTY(fill_stipple,fill_stipple,Glib::RefPtr<Gdk::Pixmap>)

} /* namespace Properties */
} /* namespace Canvas */
} /* namespace Gnome */

#endif /* _LIBGNOMECANVASMM_PROPERTY_H_ */

