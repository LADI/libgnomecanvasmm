// -*- c++ -*-
/* $Id$ */

/* canvas-property.cc
 *
 * Copyright (C) 2002 The Free Software Foundation
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

#include <libgnomecanvasmm/canvas-property.h>

#include <iostream>

namespace Gnome
{

namespace Canvas
{

namespace Properties
{

PropertyBase::PropertyBase(const char* name)
: name_(name)
{}

PropertyBase::~PropertyBase()
{}

const char* PropertyBase::get_name() const
{
  return name_;
}

/////////////////////////////
// Property<Gdk::Color>

Property<Gdk::Color>::Property(const char* name, const Gdk::Color& value) :
  PropertyBase(name),
  value_(value),
  value_gobj_used_(true),
  value_string_used_(false),
  value_rgba_(0)
{}

Property<Gdk::Color>::Property(const char* name, const Glib::ustring& color) :
  PropertyBase(name),
  value_gobj_used_(false),
  value_string_(color),
  value_string_used_ (true),
  value_rgba_(0)
{}

Property<Gdk::Color>::Property(const char* name, const guint& rgba_color) :
  PropertyBase(name),
  value_gobj_used_(false),
  value_string_used_(false),
  value_rgba_(rgba_color)
{}

void Property<Gdk::Color>::set_value_in_object(Glib::Object& object) const
{
  //Set the appropriate property name with the appropriately-typed value:
  if(value_string_used_) {
    
    std::cerr << "setting " << get_name () << " from string "
	      << value_string_ << std::endl;
    
    Glib::PropertyProxy<Glib::ustring> proxy(&object, get_name());
    if (value_string_ == "")
      proxy.reset_value ();
    else
      proxy.set_value(value_string_);

  } else if(value_gobj_used_) {
    
    Glib::PropertyProxy<Gdk::Color> proxy(&object, get_name());
    proxy.set_value(value_);

  } else {
    
    std::cerr << "setting " << get_name () << " from RGBA" << std::endl;
      
    Glib::PropertyProxy<guint> proxy(&object, get_name());
    proxy.set_value(value_rgba_);
  }
}

/////////////////////////////
// Property<Pango::FontDescription>
Property<Pango::FontDescription>::Property(const char* name, const Pango::FontDescription& value) :
  PropertyBase(name),
  value_(value)
{}

Property<Pango::FontDescription>::Property(const char* name, const Glib::ustring& font) :
  PropertyBase(name),
  value_(0),
  value_string_(font)
{}

void Property<Pango::FontDescription>::set_value_in_object(Glib::Object& object) const
{
  if(value_string_.size())
  {
    Glib::PropertyProxy<Glib::ustring> proxy(&object, get_name());
    proxy.set_value(value_string_);
  }
  else
  {
    Glib::PropertyProxy<Pango::FontDescription> proxy(&object, get_name());
    proxy.set_value(value_);
  }
}


} /* namespace Properties */
} /* namespace Canvas */
} /* namespace Gnome */
