_CONVERSION(`GnomeCanvas*',`Canvas*',`Glib::wrap($3)')
_CONVERSION(`GnomeCanvasItem*',`Item*',`Glib::wrap($3)')
_CONVERSION(`GnomeCanvasGroup*',`Group*',`Glib::wrap($3)')
_CONVERSION(`GnomeCanvasItem*',`Group*',`Glib::wrap(GNOME_CANVAS_GROUP($3))')

# GTKMM_CONVERSION(void*,Gdk_Pixmap,`Gdk_Pixmap((GdkPixmap*)$3)')
# GTKMM_CONVERSION(void*,Gdk_Color,`Gdk_Color(*(GdkColor*)$3)')
# GTKMM_CONVERSION(char*,const Glib::ustring&,,`$3.c_str()')
