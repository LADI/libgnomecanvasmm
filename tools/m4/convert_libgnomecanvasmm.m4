_CONVERSION(`GnomeCanvas*',`Canvas*',`Glib::wrap($3)')
_CONVERSION(`GnomeCanvasItem*',`Item*',`Glib::wrap($3)')
_CONVERSION(`GnomeCanvasGroup*',`Group*',`Glib::wrap($3)')
_CONVERSION(`GnomeCanvasItem*',`Group*',`Glib::wrap(GNOME_CANVAS_GROUP($3))')
_CONVERSION(`Group&',`GnomeCanvasGroup*',`($3).gobj()')

_CONVERSION(`Gtk::TextIter&',`GtkTextIter*',__FR2P)
_CONVERSION(`const Gtk::TextIter&',`const GtkTextIter*',__FR2P)
_CONVERSION(`GtkTextBuffer*',`Glib::RefPtr<Gtk::TextBuffer>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<Gtk::TextBuffer>&',`GtkTextBuffer*',__CONVERT_REFPTR_TO_P)

# GTKMM_CONVERSION(void*,Gdk_Pixmap,`Gdk_Pixmap((GdkPixmap*)$3)')
# GTKMM_CONVERSION(void*,Gdk_Color,`Gdk_Color(*(GdkColor*)$3)')
# GTKMM_CONVERSION(char*,const Glib::ustring&,,`$3.c_str()')
