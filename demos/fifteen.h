/* fifteen.hh
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

#ifndef __FIFTEEN_HH
#define __FIFTEEN_HH

#include <libgnomecanvasmm/canvas.h>
#include <libgnomecanvasmm/canvas-rect.h>
#include <libgnomecanvasmm/canvas-group.h>
#include <libgnomecanvasmm/canvas-text.h>
#include <gtkmm/frame.h>
#include <gtkmm/alignment.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <vector>

namespace Gnome
{
    namespace Canvas
    {
        class Canvas;
        class Group;
        class Text;
    }
}

class Fifteen : public Gtk::VBox
{
public:
    Fifteen ();
    
protected:
    void scramble (void);
    Glib::ustring getPieceColor (int piece);
    bool pieceEvent (GdkEvent* event,
                     Gnome::Canvas::Group* item,
                     Gnome::Canvas::Text* text);

    Gnome::Canvas::Canvas* m_canvas;
    std::vector<Gnome::Canvas::Group*> m_board;
};


#endif //__FIFTEEN_HH
