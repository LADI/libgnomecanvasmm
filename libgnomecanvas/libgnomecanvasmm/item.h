// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _LIBGNOMECANVASMM_ITEM_H
#define _LIBGNOMECANVASMM_ITEM_H


#include <glibmm.h>

// -*- C++ -*-
/* $Id: item.hg,v 1.7 2005/06/09 11:26:34 murrayc Exp $ */

/* item.h
 * 
 * Copyright (C) 1998 EMC Capital Management Inc.
 * Developed by Havoc Pennington <hp@pobox.com>
 *
 * Copyright (C) 1999 The Gtk-- Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gtkmm/object.h>
#include <gdkmm/cursor.h>
#include <libgnomecanvas/gnome-canvas.h>

#include <libgnomecanvasmm/point.h>
#include <libgnomecanvasmm/affinetrans.h>
#include <libgnomecanvasmm/properties.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GnomeCanvasItem GnomeCanvasItem;
typedef struct _GnomeCanvasItemClass GnomeCanvasItemClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gnome
{

namespace Canvas
{ class Item_Class; } // namespace Canvas

} // namespace Gnome
namespace Gnome
{

namespace Canvas
{

class Canvas;
class Group;


class Item : public Gtk::Object
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Item CppObjectType;
  typedef Item_Class CppClassType;
  typedef GnomeCanvasItem BaseObjectType;
  typedef GnomeCanvasItemClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~Item();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Item_Class;
  static CppClassType item_class_;

  // noncopyable
  Item(const Item&);
  Item& operator=(const Item&);

protected:
  explicit Item(const Glib::ConstructParams& construct_params);
  explicit Item(GnomeCanvasItem* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GnomeCanvasItem*       gobj()       { return reinterpret_cast<GnomeCanvasItem*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GnomeCanvasItem* gobj() const { return reinterpret_cast<GnomeCanvasItem*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  virtual bool on_event(GdkEvent* p1);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:

  
public:

  //:  Move an item by the specified amount
  
  /** Moves a canvas item by creating an affine transformation matrix for
   * translation by using the specified values. This happens in item
   * local coordinate system, so if you have nontrivial transform, it
   * most probably does not do, what you want.
   * @param dx Horizontal offset.
   * @param dy Vertical offset.
   */
  void move(double dx, double dy);

  //: Raise an item in the z-order of its parent group by the specified
  //: number of positions.  If the number is zero, then the item will
  //: be made the topmost of its parent group.
  
  /** Raises the item in its parent's stack by the specified number of positions.
   * If the number of positions is greater than the distance to the top of the
   * stack, then the item is put at the top.
   * @param positions Number of steps to raise the item.
   */
  void raise(int positions);

  //: Lower an item in the z-order of its parent group by the specified
  //: number of positions.  If the number is zero, then the item will be
  //: made the bottommost of its parent group.  */
  
  /** Lowers the item in its parent's stack by the specified number of positions.
   * If the number of positions is greater than the distance to the bottom of the
   * stack, then the item is put at the bottom.
   * @param positions Number of steps to lower the item.
   */
  void lower(int positions);

  //: Raise an item to the top of its parent group's z-order.
  
  /** Raises an item to the top of its parent's stack.
   */
  void raise_to_top();

  //: Lower an item to the bottom of its parent group's z-order
  
  /** Lowers an item to the bottom of its parent's stack.
   */
  void lower_to_bottom();

  //: Grab the mouse for the specified item.  Only the events in
  //: event_mask will be reported.  If cursor is non-NULL, it will be
  //: used during the duration of the grab.  Time is a proper X event
  //: time parameter.  Returns the same values as XGrabPointer().
  int grab(unsigned int event_mask, const Gdk::Cursor& cursor, guint32 etime);
  int grab(unsigned int event_mask, guint32 etime);
  

  //: Ungrabs the mouse -- the specified item must be the same that was
  //: passed to gnome_canvas_item_grab().  Time is a proper X event
  //: time parameter. 
  
  /** Ungrabs the item, which must have been grabbed in the canvas, and ungrabs the
   * mouse.
   * @param etime The timestamp for ungrabbing the mouse.
   */
  void ungrab(guint32 etime);

  //: These functions convert from a coordinate system to another.  "w"
  //: is world coordinates and "i" is item coordinates. 
  
  /** Converts a coordinate pair from world coordinates to item-relative
   * coordinates.
   * @param x X coordinate to convert (input/output value).
   * @param y Y coordinate to convert (input/output value).
   */
  void w2i(double& x, double& y);
  
  /** Converts a coordinate pair from item-relative coordinates to world
   * coordinates.
   * @param x X coordinate to convert (input/output value).
   * @param y Y coordinate to convert (input/output value).
   */
  void i2w(double& x, double& y);

  //: Used to send all of the keystroke events to a specific item as well 
  //: as GDK_FOCUS_CHANGE events.
  
  /** Makes the specified item take the keyboard focus, so all keyboard events will
   * be sent to it.  If the canvas widget itself did not have the focus, it grabs
   * it as well.
   */
  void grab_focus();

  //: Fetch the bounding box of the item.  The bounding box may not be 
  //: exactly tight, but the canvas items will do the best they can.
  
  /** Queries the bounding box of a canvas item.  The bounds are returned in the
   * coordinate system of the item's parent.
   * @param x1 Leftmost edge of the bounding box (return value).
   * @param y1 Upper edge of the bounding box (return value).
   * @param x2 Rightmost edge of the bounding box (return value).
   * @param y2 Lower edge of the bounding box (return value).
   */
  void get_bounds(double& x1, double& y1, double& x2, double& y2) const;

  //: Make the item visible
  
  /** Shows a canvas item.  If the item was already shown, then no action is taken.
   */
  void show();
  
  //: Hide the item
  
  /** Hides a canvas item.  If the item was already hidden, then no action is
   * taken.
   */
  void hide();

  //: Apply a relative affine transformation to the item 
  void affine_relative(const Art::AffineTrans &affine);
  

  //: Apply an absolute affine transformation to the item
  void affine_absolute(const Art::AffineTrans &affine);
  

  //: Gets the affine transform that converts from item-relative
  //: coordinates to world coordinates
  Art::AffineTrans get_i2w_affine() const;
  

  //: Gets the affine transform that converts from item-relative
  //: coordinates to canvas pixel coordinates
  Art::AffineTrans get_i2c_affine() const;
  

  /** Changes the parent of the specified item to be the new group.  The item keeps
   * its group-relative coordinates as for its old parent, so the item may change
   * its absolute position within the canvas.
   * @param new_group A canvas group.
   */
  void reparent(Group& new_group);

  /// Returns the canvas we're on.
   Canvas* get_canvas() const;
 
  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void update_vfunc(double* affine, ArtSVP* clip_path, int flags);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void realize_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void unrealize_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void map_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void unmap_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual ArtUta* coverage_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void draw_vfunc(const Glib::RefPtr<Gdk::Drawable>& drawable, int x, int y, int width, int height);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void render_vfunc(GnomeCanvasBuf* buf);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual double point_vfunc(double x, double y, int cx, int cy, GnomeCanvasItem** actual_item);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void bounds_vfunc(double* x1, double* y1, double* x2, double* y2);
#endif //GLIBMM_VFUNCS_ENABLED


  //: Signal: an event ocurred for an item of this type.  The(x, y)
  //: coordinates are in the canvas world coordinate system.
  
  /**
   * @par Prototype:
   * <tt>bool on_my_%event(GdkEvent* p1)</tt>
   */

  Glib::SignalProxy1< bool,GdkEvent* > signal_event();


  Group* get_parent_group();
  const Group* get_parent_group() const;

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Group*> property_parent() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Group*> property_parent() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


protected:

  //- For class children use only
  void item_construct(Group& group);

  //- Unsafe version - can't use a _gtk_string here, C++ doesn't like
  //- classes being passed before ellipses('...') args
  void item_construct(Group& group, const gchar* first_arg_name,
                      va_list ap);

  //- Set arguments - For class children use only
  void set(const gchar* first_arg_name, ...);

  //: Request that the update method eventually get called.  This should be used
  //: only by item implementations.
  
  /** To be used only by item implementations.  Requests that the canvas queue an
   * update for the specified item.
   */
  void request_update();


  /** Resets the bounding box of a canvas item to an empty rectangle.
   */
  void reset_bounds();
  
  /** Sets the svp to the new value, requesting repaint on what's changed. This
   * function takes responsibility for freeing new_svp. This routine also adds the
   * svp's bbox to the item's.
   * @param p_svp A pointer to the existing svp.
   * @param new_svp The new svp.
   */
  void update_svp(ArtSVP **p_svp, ArtSVP *new_svp);
  
  /** Sets the svp to the new value, clipping if necessary, and requesting repaint
   * on what's changed. This function takes responsibility for freeing new_svp.
   * @param p_svp A pointer to the existing svp.
   * @param new_svp The new svp.
   * @param clip_svp A clip path, if non-null.
   */
  void update_svp_clip(ArtSVP **p_svp, ArtSVP *new_svp, ArtSVP *clip_svp);
  
  /** Request redraw of the svp if in aa mode, or the entire item in in xlib mode.
   * @param svp The svp that needs to be redrawn.
   */
  void request_redraw_svp(const ArtSVP* svp);
  
  /** Sets the bbox to the new value, requesting full repaint.
   * @param item The canvas item needing update.
   * @param x1 Left coordinate of the new bounding box.
   * @param y1 Top coordinate of the new bounding box.
   * @param x2 Right coordinate of the new bounding box.
   * @param y2 Bottom coordinate of the new bounding box.
   */
  void update_bbox(int x1, int y1, int x2, int y2);
  

};

} /* namespace Canvas */
} /* namespace Gnome */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gnome::Canvas::Item
   */
  Gnome::Canvas::Item* wrap(GnomeCanvasItem* object, bool take_copy = false);
} //namespace Glib


#endif /* _LIBGNOMECANVASMM_ITEM_H */

