/* canvas.cc
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

#include <libgnomecanvasmm/init.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/notebook.h>

#include "primitives.h"
#include "canvas_features.h"
#include "fifteen.h"
#include "arrowhead.h"
#include "richtext.h"

class MainWin 
    : public Gtk::Window
{
public:
    MainWin ();

protected:
};

MainWin::MainWin ()
: Gtk::Window (GTK_WINDOW_TOPLEVEL)
{
    using namespace Gtk::Notebook_Helpers;

    Gtk::Notebook* notebook = manage (new Gtk::Notebook ());
    add (*notebook);

    Primitives* primitives = manage (new Primitives (false));
    notebook->pages ().push_back (TabElem (*primitives, "Primitives"));    
    Primitives* antialias = manage (new Primitives (true));
    notebook->pages ().push_back (TabElem (*antialias, "Antialias"));    
    Arrowhead* arrowhead = manage (new Arrowhead ());
    notebook->pages ().push_back (TabElem (*arrowhead, "Arrowhead"));    
    Fifteen* fifteen = manage (new Fifteen ());
    notebook->pages ().push_back (TabElem (*fifteen, "Fifteen"));    
    Features* features = manage (new Features ());
    notebook->pages ().push_back (TabElem (*features, "Features"));    
    Richtext* richtext = manage (new Richtext ());
    notebook->pages ().push_back (TabElem (*richtext, "Rich Text"));    

    show_all ();
}


int 
main (int argc, char* argv[])
{
    Gnome::Canvas::init ();
    Gtk::Main app (argc, argv);

    MainWin mainwin;
    app.run (mainwin);

    return 0;
}
