// CanvasEvents.cc
// This program tries to sample the event handling inside the canvas
// (c) Agustin Ferrin Pozuelo <ferrin@arrakis.es>
// Note that you have to click 2^N times over the canvas,
// It took me 5.60 seconds to have 64 valid events! I'm Termclickator
#include <gtkmm/window.h>
#include <gtkmm/main.h>
#include <libgnomecanvasmm.h>
#include <stdio.h>


guint32 etime=0;
guint	status=0;
enum {CE=0,CEA=1,CBE=2,IE=3,IEA=4,CBEA=5,N=6};
enum {ENDING_STATUS=(1<<N)};
gchar record[N+1],stmask[N+1];
gchar* cname[N]={"canvas_event","canvas_event_after"
		,"canvas_button_press_event"
		,"item_button_press_event","item_button_press_event_after"
		,"canvas_button_press_event_after"};

static bool event_explorer(GdkEvent* e, guint caller)
{
  GdkEventButton* b;
  // Ignore all but button-press events:
  if(e->type != GDK_BUTTON_PRESS)
  return TRUE;
	  
  b = &(e->button);
  if(b->time != etime) // if new event
  {
    gint i;
    if(etime != 0) // if not first, inc status and show last record
    {
      for(i=0;i<N;i++)stmask[i]= (status & (1<<i)) ? '1': '0';
      stmask[N]=0;
      printf("  Event mask / Events reached %s/%s\n",stmask,record);
      if((++status)>=ENDING_STATUS) exit(0);
    }
		
    for(i=0;i<N;i++)record[i]='0'; record[N]=0;
    etime=b->time;
    printf("New event (%u) at time %X\n", status, (guint)etime);
  }
	
  record[caller]='1';
  printf("  %-30s() is returning ", cname[caller]);
	
  if(status & (1 << caller))
  {
    printf("TRUE\n");
    return true;
  }
  else
  {
    printf("FALSE\n");
    return false;
  }
}

static void event_explorer_notify(GdkEvent* e, guint caller)
{
  event_explorer_notify(e, caller);
}

static bool button_event_stub(GdkEventButton *b, guint caller)
{
  return event_explorer((GdkEvent *) b, caller);
}

static void button_event_stub_notify(GdkEventButton *b, guint caller)
{
  return button_event_stub_notify(b, caller);
}

int main(int argc, char* argv[])
{
  using SigC::bind;
  using SigC::slot;
	
  Gnome::Canvas::init();
  Gtk::Main canvasmain(argc, argv);
  
  Gtk::Window window(GTK_WINDOW_TOPLEVEL);
	
  Gnome::Canvas::Canvas *canvas = manage(new Gnome::Canvas::Canvas());

  Gnome::Canvas::Rect* item = manage(new Gnome::Canvas::Rect(
    *canvas->root(),
    (gdouble) -1000, (gdouble) -1000,
    (gdouble) 1000, (gdouble) 1000) );
  *item << Gnome::Canvas::Properties::fill_color("black");

  //Connect canvas signals:
  canvas->signal_event().connect_notify(bind(slot(&event_explorer_notify),CE));
  canvas->signal_event().connect(bind(slot(&event_explorer),CEA));
  canvas->signal_button_press_event().connect_notify(bind(slot(&button_event_stub_notify),CBE));
  canvas->signal_button_press_event().connect(bind(slot(&button_event_stub),CBEA));
	
  item->signal_event().connect_notify(bind(slot(&event_explorer_notify),IE));
  item->signal_event().connect(bind(slot(&event_explorer),IEA));
	
  window.add(*canvas);
  canvas->show();

  canvasmain.run(window);
  return 0;
}

