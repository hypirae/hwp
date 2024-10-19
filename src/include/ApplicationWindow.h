#ifndef __APPLICATIONWINDOW_H__
#define __APPLICATIONWINDOW_H__

#include <memory>
#include <string>

#include <ncurses.h>

#include "Window.h"

class ApplicationWindow : public Window
{
public:
  ApplicationWindow ();
  ~ApplicationWindow ();

  // screen functions
  void
  pause ()
  {
    wgetch (this->screen);
  }
};
#endif