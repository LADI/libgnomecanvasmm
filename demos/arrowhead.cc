/* arrowhead.cc
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

#include "arrowhead.h"

#include <libgnomecanvasmm/canvas.h>
#include <libgnomecanvasmm/canvas-rect.h>
#include <libgnomecanvasmm/canvas-group.h>
#include <libgnomecanvasmm/canvas-text.h>
#include <libgnomecanvasmm/canvas-line.h>
#include <gtkmm/frame.h>
#include <gtkmm/alignment.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>

#include <stdio.h>

#define LEFT    50.0
#define RIGHT  350.0
#define MIDDLE 150.0

DragBox::DragBox (Gnome::Canvas::Group& root)
: Gnome::Canvas::Rect (root)
{
    property_fill_color () = "white";
    property_outline_color () = "black";
    property_width_pixels () = 0;
}


void
DragBox::moveDragBox (double x, double y)
{
    property_x1 () = x - 5.0;
    property_y1 () = y - 5.0;
    property_x2 () = x + 5.0;
    property_y2 () = y + 5.0;
}


bool 
DragBox::on_event (GdkEvent* event)
{
    Gnome::Canvas::Rect::on_event (event);

    switch (event->type) {
    case GDK_ENTER_NOTIFY:
        property_fill_color () = "red";
        break;
        
    case GDK_LEAVE_NOTIFY:
        if (!(event->crossing.state & GDK_BUTTON1_MASK)) {
            property_fill_color () = "white";
        }
        break;
        
    case GDK_BUTTON_PRESS:
        grab (GDK_POINTER_MOTION_MASK | GDK_BUTTON_RELEASE_MASK,
              Gdk::Cursor (GDK_FLEUR),
              event->button.time);
        break;
        
    case GDK_BUTTON_RELEASE:
        ungrab (event->button.time);
        break;
        
    default:
        break;
    }
    
    return false;    
}


Dimension::Dimension (Gnome::Canvas::Group& root, GtkAnchorType anchor)
    : m_line (NULL),
      m_text (NULL)
{
    m_line = manage (new Gnome::Canvas::Line (root));
    m_line->property_fill_color () = "black";
    m_line->property_first_arrowhead () = true;
    m_line->property_last_arrowhead () = true;
    m_line->property_arrow_shape_a () = 5.0;
    m_line->property_arrow_shape_b () = 5.0;
    m_line->property_arrow_shape_c () = 3.0;

    m_text = manage (new Gnome::Canvas::Text (root));
    m_text->property_fill_color () = "black";
    m_text->property_font () = "Sans 12";
    m_text->property_anchor () = anchor;
}


void 
Dimension::setDimension (double x1, double y1, 
                         double x2, double y2, 
                         double tx, double ty, 
                         int dim)
{
    Gnome::Canvas::Points points;
    points.push_back (Gnome::Art::Point (x1, y1));
    points.push_back (Gnome::Art::Point (x2, y2));
    m_line->property_points ().set_value (points);

    char buf[100];
    sprintf (buf, "%d", dim);
    m_text->property_text () = buf;
    m_text->property_x () = tx;
    m_text->property_y () = ty;
}


Arrowhead::Arrowhead ()
    : Gtk::VBox (false, 4),
      m_width (2),
      m_shape_a (8),
      m_shape_b (10),
      m_shape_c (3),
      m_big_arrow (NULL),
      m_outline (NULL),
      m_width_drag_box (NULL),
      m_shape_a_drag_box (NULL),
      m_shape_b_c_drag_box (NULL),
      m_width_arrow (NULL),
      m_shape_a_arrow (NULL),
      m_shape_b_arrow (NULL),
      m_shape_c_arrow (NULL),
      m_width_info (NULL),
      m_shape_a_info (NULL),
      m_shape_b_info (NULL),
      m_shape_c_info (NULL),
      m_sample1 (NULL),
      m_sample2 (NULL),
      m_sample3 (NULL)
{
    set_border_width (4);
    
    Gtk::Label* label 
        = manage (new Gtk::Label ("This demo allows you to edit arrowhead shapes.  Drag the little boxes\n"
                                  "to change the shape of the line and its arrowhead.  You can see the\n"
                                  "arrows at their normal scale on the right hand side of the window."));
    pack_start (*label, false, false);

    Gtk::Alignment* alignment 
        = manage (new Gtk::Alignment (0.5, 0.5, 0.0, 0.0));
    pack_start (*alignment, true, true, 0);

    Gtk::Frame* frame = manage (new Gtk::Frame ());
    frame->set_shadow_type (GTK_SHADOW_IN);
    alignment->add (*frame);

    Gnome::Canvas::Canvas* canvas = manage (new Gnome::Canvas::Canvas ());
    canvas->set_size_request (500, 350);
    canvas->set_scroll_region (0, 0, 500, 350);
    frame->add (*canvas);

    // Big arrow
    Gnome::Canvas::Points points;
    points.push_back (Gnome::Art::Point (LEFT, MIDDLE));
    points.push_back (Gnome::Art::Point (RIGHT, MIDDLE));
    m_big_arrow = manage (new Gnome::Canvas::Line (*canvas->root (), points));
    m_big_arrow->property_fill_color () = "mediumseagreen";
    m_big_arrow->property_width_pixels () = 2 * 10;
    m_big_arrow->property_last_arrowhead () = true;

    // Arrow outline
    m_outline = manage (new Gnome::Canvas::Line (*canvas->root ()));
    m_outline->property_fill_color () = "black";
    m_outline->property_width_pixels () = 2;
    m_outline->property_cap_style () = GDK_CAP_ROUND;
    m_outline->property_join_style () = GDK_JOIN_ROUND;

    // Drag boxes
    m_width_drag_box = manage (new DragBox (*canvas->root ()));
    m_width_drag_box->signal_event ()
        .connect (bind (slot (*this, &Arrowhead::widthEvent),
                        m_width_drag_box));
    m_shape_a_drag_box = manage (new DragBox (*canvas->root ()));
    m_shape_a_drag_box->signal_event ()
        .connect (bind (slot (*this, &Arrowhead::shapeAEvent),
                        m_shape_a_drag_box));
    m_shape_b_c_drag_box = manage (new DragBox (*canvas->root ()));
    m_shape_b_c_drag_box->signal_event ()
        .connect (bind (slot (*this, &Arrowhead::shapeBCEvent),
                        m_shape_b_c_drag_box));

    // Dimension
    m_width_arrow = new Dimension (*canvas->root (), GTK_ANCHOR_E);
    m_shape_a_arrow = new Dimension (*canvas->root (), GTK_ANCHOR_N);
    m_shape_b_arrow = new Dimension (*canvas->root (), GTK_ANCHOR_N);
    m_shape_c_arrow = new Dimension (*canvas->root (), GTK_ANCHOR_W);

    // Info
    m_width_info = createInfo (*canvas->root (), LEFT, 260);
    m_shape_a_info = createInfo (*canvas->root (), LEFT, 280);
    m_shape_b_info = createInfo (*canvas->root (), LEFT, 300);
    m_shape_c_info = createInfo (*canvas->root (), LEFT, 320);

    // Division line
    points.clear ();
    points.push_back (Gnome::Art::Point (RIGHT + 50, 0.0));
    points.push_back (Gnome::Art::Point (RIGHT + 50, 1000.0));
    Gnome::Canvas::Line* division
        = manage (new Gnome::Canvas::Line (*canvas->root (), points));
    division->property_fill_color () = "black";
    division->property_width_pixels () = 2;

    // Sample arrows
    m_sample1 = createSampleArrow (*canvas->root (), 
                                   RIGHT + 100, 30, 
                                   RIGHT + 100, MIDDLE - 30);
    m_sample2 = createSampleArrow (*canvas->root (), 
                                   RIGHT + 70, MIDDLE, 
                                   RIGHT + 130, MIDDLE);
    m_sample3 = createSampleArrow (*canvas->root (), 
                                   RIGHT + 70, MIDDLE + 30, 
                                   RIGHT + 130, MIDDLE + 120);

    setArrowShape ();
}


Arrowhead::~Arrowhead ()
{
    delete m_width_arrow;
    delete m_shape_a_arrow;
    delete m_shape_b_arrow;
    delete m_shape_c_arrow;
}


Gnome::Canvas::Text*
Arrowhead::createInfo (Gnome::Canvas::Group& root, double x, double y)
{
    Gnome::Canvas::Text* text = manage (new Gnome::Canvas::Text (root));
    text->property_x () = x;
    text->property_y () = y;
    text->property_fill_color () = "black";
    text->property_font () = "Sans 14";
    text->property_anchor () = GTK_ANCHOR_NW;
    
    return text;
}


Gnome::Canvas::Line*
Arrowhead::createSampleArrow (Gnome::Canvas::Group& root, 
                              double x1, double y1,
                              double x2, double y2)
{
    Gnome::Canvas::Points points;
    points.push_back (Gnome::Art::Point (x1, y1));
    points.push_back (Gnome::Art::Point (x2, y2));
    Gnome::Canvas::Line* sample
        = manage (new Gnome::Canvas::Line (root, points));
    sample->property_fill_color () = "black";
    sample->property_first_arrowhead () = true;
    sample->property_last_arrowhead () = true;
    
    return sample;
}


void
Arrowhead::setArrowShape (void)
{
    // Big arrow
    m_big_arrow->property_width_pixels () = 10 * m_width;
    m_big_arrow->property_arrow_shape_a () = 10 * m_shape_a;
    m_big_arrow->property_arrow_shape_b () = 10 * m_shape_b;
    m_big_arrow->property_arrow_shape_c () = 10 * m_shape_c;
    
    // Outline
    Gnome::Canvas::Points points;
    points.push_back (Gnome::Art::Point (RIGHT - 10 * m_shape_a,
                                         MIDDLE));
    points.push_back (Gnome::Art::Point (RIGHT - 10 * m_shape_b,
                                         MIDDLE - 10 * (m_shape_c + m_width / 2.0)));
    points.push_back (Gnome::Art::Point (RIGHT,
                                         MIDDLE));
    points.push_back (Gnome::Art::Point (points[1].get_x (),
                                         MIDDLE + 10 * (m_shape_c + m_width / 2.0)));
    points.push_back (points.front ());
    m_outline->property_points ().set_value (points);

    // Drag boxes
    m_width_drag_box->moveDragBox (LEFT, 
                                   MIDDLE - 10 * m_width / 2.0);
    m_shape_a_drag_box->moveDragBox (RIGHT - 10 * m_shape_a, 
                                     MIDDLE);
    m_shape_b_c_drag_box->moveDragBox (RIGHT - 10 * m_shape_b,
                                       MIDDLE - 10 * (m_shape_c + m_width / 2.0));

    // Dimension
    m_width_arrow
        ->setDimension (LEFT - 10,
                        MIDDLE - 10 * m_width / 2.0,
                        LEFT - 10,
                        MIDDLE + 10 * m_width / 2.0,
                        LEFT - 15,
                        MIDDLE,
                        m_width);
    m_shape_a_arrow
        ->setDimension (RIGHT - 10 * m_shape_a,
                        MIDDLE + 10 * (m_width / 2.0 + m_shape_c) + 10,
                        RIGHT,
                        MIDDLE + 10 * (m_width / 2.0 + m_shape_c) + 10,
                        RIGHT - 10 * m_shape_a / 2.0,
                        MIDDLE + 10 * (m_width / 2.0 + m_shape_c) + 15,
                        m_shape_a);
    m_shape_b_arrow
        ->setDimension (RIGHT - 10 * m_shape_b,
                        MIDDLE + 10 * (m_width / 2.0 + m_shape_c) + 35,
                        RIGHT,
                        MIDDLE + 10 * (m_width / 2.0 + m_shape_c) + 35,
                        RIGHT - 10 * m_shape_b / 2.0,
                        MIDDLE + 10 * (m_width / 2.0 + m_shape_c) + 40,
                        m_shape_b);
    m_shape_c_arrow
        ->setDimension (RIGHT + 10,
                        MIDDLE - 10 * m_width / 2.0,
                        RIGHT + 10,
                        MIDDLE - 10 * (m_width / 2.0 + m_shape_c),
                        RIGHT + 15,
                        MIDDLE - 10 * (m_width / 2.0 + m_shape_c / 2.0),
                        m_shape_c);

    // Info
    char buf[100];
    sprintf (buf, "width: %d", m_width);
    m_width_info->property_text () = buf;
    
    sprintf (buf, "arrow_shape_a: %d", m_shape_a);
    m_shape_a_info->property_text () = buf;
    
    sprintf (buf, "arrow_shape_b: %d", m_shape_b);
    m_shape_b_info->property_text () = buf;
    
    sprintf (buf, "arrow_shape_c: %d", m_shape_c);
    m_shape_c_info->property_text () = buf;

    // Sample arrows
    m_sample1->property_width_pixels () = m_width;
    m_sample1->property_arrow_shape_a () = m_shape_a;
    m_sample1->property_arrow_shape_b () = m_shape_b;
    m_sample1->property_arrow_shape_c () = m_shape_c;

    m_sample2->property_width_pixels () = m_width;
    m_sample2->property_arrow_shape_a () = m_shape_a;
    m_sample2->property_arrow_shape_b () = m_shape_b;
    m_sample2->property_arrow_shape_c () = m_shape_c;

    m_sample3->property_width_pixels () = m_width;
    m_sample3->property_arrow_shape_a () = m_shape_a;
    m_sample3->property_arrow_shape_b () = m_shape_b;
    m_sample3->property_arrow_shape_c () = m_shape_c;
}


bool
Arrowhead::widthEvent (GdkEvent* event,
                       Gnome::Canvas::Item* item)
{
    if ((event->type != GDK_MOTION_NOTIFY) 
        || !(event->motion.state & GDK_BUTTON1_MASK)) {
        return false;
    }
    
    int width = (int) (MIDDLE - event->motion.y) / 5;
    if (width < 0) {
        return false;
    }
    
    m_width = width;
    setArrowShape ();    

    return false;    
}


bool
Arrowhead::shapeAEvent (GdkEvent* event,
                        Gnome::Canvas::Item* item)
{
    if ((event->type != GDK_MOTION_NOTIFY) 
        || !(event->motion.state & GDK_BUTTON1_MASK)) {
        return false;
    }
    
    int shape_a = (int) (RIGHT - event->motion.x) / 10;
    if ((shape_a < 0) || (shape_a > 30)) {
        return false;
    }
    
    m_shape_a = shape_a;
    setArrowShape ();

    return false;   
}


bool
Arrowhead::shapeBCEvent (GdkEvent* event,
                         Gnome::Canvas::Item* item)
{
    if ((event->type != GDK_MOTION_NOTIFY) 
        || !(event->motion.state & GDK_BUTTON1_MASK)) {
        return false;
    }
    
    bool change = false;
    
    int shape_b = (int) (RIGHT - event->motion.x) / 10;
    if ((shape_b >= 0) && (shape_b <= 30)) {
        m_shape_b = shape_b;
        change = true;
    }
    
    int shape_c = (int) ((MIDDLE - 5 * m_width) - event->motion.y) / 10;
    if (shape_c >= 0) {
        m_shape_c = shape_c;
        change = true;
    }
    
    if (change == true) {
        setArrowShape ();
    }
    
    return false;    
}
