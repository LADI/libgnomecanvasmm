_PUSH()
divert(-1)
dnl
dnl  Macros for creating Canvas Item properties
dnl

define(`CANVAS_PROPERTY',`dnl
void set_$1`'($3);
ifelse($5,,,`dnl
  $5 get_$1`'() const;
')dnl
_PUSH(SECTION_CC)
void __NAMESPACE__::__CPPNAME__::set_$1`'($3 o)
{
  set("$2",_CONVERT($3,$4,o),0);
}

ifelse($5,,,`dnl
$5 __NAMESPACE__::__CPPNAME__::get_$1`'() const
{
  GtkArg arg;
  arg.name = "$2";
  //TODO: gtk_object_getv(const_cast<GtkObject*>(this->Gtk::Object::gobj()),1,&arg);
  return _CONVERT($6,$5,arg.d.$7);
}

')dnl
_POP()
')

_CONVERSION(`const Glib::RefPtr<Gdk::Pixmap>&',`void*',`(void*)(($3)->gobj())')
_CONVERSION(`void*',`Glib::RefPtr<Gdk::Pixmap>',`Gdk::Pixmap::wrap_specific_type((GdkPixmap*)($3), true)')
_CONVERSION(`const Glib::RefPtr<Gdk::Pixmap>&',`GdkWindow*',`(GdkWindow*)(($3)->gobj())')

_CONVERSION(`void*',`Gdk::Color',`Glib::wrap((GdkColor*)($3), true)')

_CONVERSION(int,GdkCapStyle,`$2($3)')
_CONVERSION(int,GdkJoinStyle,`$2($3)')
_CONVERSION(int,GdkLineStyle,`$2($3)')
_CONVERSION(int,GtkAnchorType,`$2($3)')

_CONVERSION(`const CanvasPoints&',`GnomeCanvasPoints*',`$3.gobj()')

_POP()
