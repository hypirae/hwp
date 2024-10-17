#include <stdio.h>
#include <stdlib.h>

#include "window.h"

int
main (void)
{
  int width, height;
  HWPWINDOW *window;
  const char *fmt = "Window dimensions: %dx%d";
  int len;
  char *str;

  // start draw functions
  hwpwindow_init ();

  // get the size of the terminal
  // and allocate a window
  getmaxyx (stdscr, height, width);
  window = hwpwindow_alloc (height, width);

  // display the dimensions of the window
  len = asprintf (&str, fmt, window->height, window->width);
  hwpbuffer_append (window->shadow, str, len);
  hwpwindow_flip (window);
  hwpwindow_paint (window);

  // wait for user input
  getch ();

  // end draw functions
  hwpwindow_deinit ();

  // cleanup
  free (str);
  hwpwindow_dealloc (window);

  return EXIT_SUCCESS;
}