// This example was started by Guillaume Laurent.
// It has become a place to dump code that tests parts of the
// gnomemm canvas code. Little thought has been given to the
// actual on-screen output.

#include <libgnomecanvasmm.h>

class CanvasExample : public Gnome::Canvas::Canvas
{
public:
  CanvasExample();
  virtual ~CanvasExample();

protected:
  Gnome::Canvas::CanvasGroup m_canvasgroup;
  Gnome::Canvas::CanvasLine *m_line;
  Gnome::Canvas::CanvasEllipse *m_ellipse;
  Gnome::Canvas::CanvasRect *m_rect;
  //  Gnome::Canvas::CanvasImage *m_image;
  Gnome::Canvas::CanvasText *m_text;
};

CanvasExample::CanvasExample()
  : m_canvasgroup(*(root()), 0, 0)
{
  // create some elements there
  Gnome::Canvas::CanvasPoints m_points;

  m_points.push_back(Gnome::Art::Point(0, 0));
  m_points.push_back(Gnome::Art::Point(100, 0));
  m_points.push_back(Gnome::Art::Point(0, 100));
  m_points.push_back(Gnome::Art::Point(100, 100));

  // we want to use the stream like interface
  using namespace Gnome::Canvas;

  m_line = new Gnome::Canvas::CanvasLine(m_canvasgroup,m_points);
  *m_line << CanvasHelpers::fill_color("red")
          << CanvasHelpers::width_units(4.0)
          << CanvasHelpers::cap_style(GDK_CAP_ROUND);

  m_ellipse = new Gnome::Canvas::CanvasEllipse(m_canvasgroup, 0, 0, 100, 100);
  *m_ellipse << CanvasHelpers::fill_color("blue");

  m_rect = new Gnome::Canvas::CanvasRect(m_canvasgroup, 10, 10, 50, 100);
  *m_rect << CanvasHelpers::width_pixels(2)
          << CanvasHelpers::fill_color("white");

  //m_image = new Gnome::Canvas::CanvasImage(m_canvasgroup, 0, 0, Gdk_Imlib::Image("example.png"));
  //The width and height are set from the information in the image file.

  m_text = new Gnome::Canvas::CanvasText(m_canvasgroup, 10, 10, "Some Text");
  *m_text << CanvasHelpers::font("-Adobe-Helvetica-Medium-R-Normal--*-100-*-*-*-*-*-*")
          << CanvasHelpers::fill_color("blue"); //Changes the color of the text.
}

CanvasExample::~CanvasExample()
{
  delete m_line;
  delete m_ellipse;
  delete m_rect;
//  delete m_image;
  delete m_text;
}


//MainWin:

class MainWin : public Gtk::Window
{
public:
  MainWin(const std::string& title);

protected:
  //Member widgets:
  CanvasExample m_canvas;
};

MainWin::MainWin(const std::string& title)
: Gtk::Window(GTK_WINDOW_TOPLEVEL)
{
  set_title (title);
  add(m_canvas);

  show_all();
}

//main():

int main(int argc, char *argv[])
{
  Gnome::Canvas::init();
  Gtk::Main app(argc, argv);

  MainWin mainwin("Gnome::Canvas Example");
  app.run(mainwin);

  return 0;
}
