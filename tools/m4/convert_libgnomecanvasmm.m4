# _CONVERSION(GnomeCanvasItem*,Gnome::CanvasGroup*,,`Gtk::wrap(GNOME_CANVAS_GROUP($3))')
# _CONVERSION(GnomeCanvas*,Gnome::Canvas*,,`Gtk::wrap($3)')

_CONVERSION(GnomeCanvasGroup*,`Gnome::CanvasGroup*',,`Gtk::wrap($3)')
_CONVERSION(GnomeCanvasItem*,`Gnome::CanvasItem*',,`Gtk::wrap($3)')
