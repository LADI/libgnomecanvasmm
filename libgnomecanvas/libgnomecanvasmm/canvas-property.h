#ifndef _LIBGNOMECANVASMM_CANVAS_PROPERTY_H_
#define _LIBGNOMECANVASMM_CANVAS_PROPERTY_H_

//#include <gtk/gtkpacker.h> //For GtkAnchorType.

#include <gdkmm/color.h>
#include <gdkmm/pixmap.h>
#include <pangomm/fontdescription.h>

namespace Gnome
{

namespace Canvas
{

namespace CanvasHelpers {

template <class T>
struct Property
{
  const char* name_;
  T arg_;
  Property(const char* name, const T& arg)
    : name_(name), arg_(arg)
    {}
  const T& arg() const {return arg_; }
};

struct Properties
{
  template <class O, class T>
  static void apply(O& object, const Property<T>& property)
    { object.set(property.name_,property.arg(),0); }
};


template <class O, class T>
O& operator << (O& object, const Property<T>& property)
{
  Properties::apply(object,property);
  return object;
}

/********* specializations *********/

//Colors can be specified with a string or a Gdk::Color.
//FIXME: rgb constructor?
template<>
struct Property<Gdk::Color>
{
  const char* name_;
  Glib::ustring color_;
  Gdk::Color arg_;
  Property(const char* name, const Gdk::Color& arg)
    : name_(name), color_(), arg_(arg)
    {}
  Property(const char* name, const Glib::ustring& color)
    : name_(name), color_(color), arg_(0)
    {}
  const void* arg() const
  {
    return (color_.size() == 0) ? (void*)(arg_.gobj()) : (void*)(color_.c_str());
  }
};

//Font can be specified with a string or a Pango::FontDescription.
template<>
struct Property<Pango::FontDescription>
{
  const char* name_;
  Pango::FontDescription arg_;
  Glib::ustring strfont_;

  Property(const char* name,const Pango::FontDescription& arg)
    : name_(name), arg_(arg)
  {}

  Property(const char* name,const Glib::ustring& font)
    : name_(name), arg_(0), strfont_(font)
  {}

  const void* arg() const
  {
    return (strfont_.size() == 0) ? (void*)(arg_.gobj()) : (void*)(strfont_.c_str());
  }
};

struct font : public Property<Pango::FontDescription>  //Used by CanvasText.
{
  font(const Pango::FontDescription& v)
  : Property<Pango::FontDescription>("font_gdk", v)
  {}

  font(const Glib::ustring& v)
  : Property<Pango::FontDescription>("font", v)
  {}
};

template<>
struct Property< Glib::RefPtr<Gdk::Pixmap> >
{
  const char* name_;
  Glib::RefPtr<Gdk::Pixmap> arg_;
  Property(const char* name,const Glib::RefPtr<Gdk::Pixmap>& arg)
    : name_(name), arg_(arg)
  {}

  GdkPixmap* arg() const
  {
    return ( arg_ ? arg_->gobj() : 0 );
  }
};

struct fill_color : public Property<Gdk::Color>
{
  fill_color(const Gdk::Color& v): Property<Gdk::Color>("fill_color_gdk",v) {}
  fill_color(const Glib::ustring& v): Property<Gdk::Color>("fill_color",v) {}
};

struct outline_color : public Property<Gdk::Color>
{
  outline_color(const Gdk::Color& v)
  : Property<Gdk::Color>("outline_color_gdk", v)
  {}

  outline_color(const Glib::ustring& v)
  : Property<Gdk::Color>("outline_color", v)
  {}
};


#define GNOMEMM_PROPERTY(N,N2,T) \
struct N : public Property<T> { N(const T& v): Property<T>(#N2,v) {}};


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

} /* namespace CanvasHelpers */
} /* namespace Canvas */
} /* namespace Gnome */

#endif /* _LIBGNOMECANVASMM_PROPERTY_H_ */

