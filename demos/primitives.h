/* primitives.hh
 *
 * Copyright (C) 2002 The libgnomecanvasmm Development Team
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

#ifndef __PRIMITIVES_HH
#define __PRIMITIVES_HH

#include <libgnomecanvasmm/canvas.h>
#include <libgnomecanvasmm/canvas-group.h>
#include <libgnomecanvasmm/canvas-rect.h>
#include <libgnomecanvasmm/canvas-ellipse.h>
#include <libgnomecanvasmm/canvas-line.h>
#include <libgnomecanvasmm/canvas-text.h>
#include <libgnomecanvasmm/canvas-polygon.h>
#include <libgnomecanvasmm/canvas-widget.h>
#include <libgnomecanvasmm/pixbuf.h>
#include <gtkmm/label.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/adjustment.h>
#include <gtkmm/button.h>
#include <gtkmm/scrollbar.h>
#include <gtkmm/frame.h>
#include <gtkmm/table.h>
#include <gtkmm/box.h>

namespace Gtk
{
    class Adjustment;
}

class Primitives : public Gtk::VBox
{
public:
    Primitives (bool aa);

protected:
    void zoomChanged (Gnome::Canvas::Canvas* canvas,
                      Gtk::Adjustment* adj);
    bool keyPress (GdkEventKey *event, Gnome::Canvas::Canvas* canvas);
    bool itemEvent (GdkEvent* event, Gnome::Canvas::Item* item);

    void setupHeading (Gnome::Canvas::Group& root,
                       const Glib::ustring& text,
                       int pos);
    void setupDivisions (Gnome::Canvas::Group& root);
    void setupRectangles (Gnome::Canvas::Group& root);
    void setupEllipses (Gnome::Canvas::Group& root);
    void plantFlower (Gnome::Canvas::Group& root,
                      double x, double y);
    void setupImages (Gnome::Canvas::Group& root);
    Gnome::Canvas::Group* makeAnchor (Gnome::Canvas::Group& root, 
                                      double x, double y);
    void setupTexts (Gnome::Canvas::Group& root);
    void polishDiamond (Gnome::Canvas::Group& root);
    void makeHilbert (Gnome::Canvas::Group& root);
    void setupLines (Gnome::Canvas::Group& root);
    void setupPolygons (Gnome::Canvas::Group& root);
    void setupWidgets (Gnome::Canvas::Group& root);
};


#endif //__PRIMITIVES_HH
