#include <stdio.h>
#include <stdlib.h>

#include "window.h"

int
main (void)
{
  HWPWINDOW *window = hwpwindow_alloc (1, 20, 0, 0);

  // start draw functions
  hwpwindow_init ();

  hwpbuffer_append (window->shadow, "Hello, World!", 13);
  hwpwindow_flip (window);
  hwpwindow_paint (window);

  getch ();

  hwpbuffer_clear (window->shadow);
  hwpbuffer_append (window->shadow, "Goodbye, World!", 15);
  hwpwindow_flip (window);
  hwpwindow_paint (window);

  getch ();

  // end draw functions
  hwpwindow_deinit ();

  // cleanup
  hwpwindow_dealloc (window);

  return EXIT_SUCCESS;
}