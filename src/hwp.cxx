#include <iostream>

#include "ApplicationWindow.h"

int
main (void)
{
  ApplicationWindow window;

  window.putAt ("Hello, World!", 0, 0);
  window.refresh ();
  window.pause ();

  return 0;
}