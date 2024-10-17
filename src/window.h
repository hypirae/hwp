#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <stdlib.h>
#include <string.h>

#include <ncurses.h>

#include "buffer.h"

/**
 * hwpwindow: A simple window structure.
 *
 * @height The height of the window.
 * @width The width of the window.
 * @buffer The buffer of the window.
 * @shadow The shadow buffer of the window.
 *
 * @note: the window is a simple buffer with dimensions.
 */
typedef struct hwp_window
{
  short height;
  short width;
  HWPBUFFER *current;
  HWPBUFFER *shadow;
} HWPWINDOW;

// forward declarations
HWPWINDOW *hwpwindow_alloc (short height, short width);
void hwpwindow_dealloc (HWPWINDOW *window);
void hwpwindow_flip (HWPWINDOW *window);
void hwpwindow_paint (HWPWINDOW *window);

// these functions set up the terminal through ncurses
void hwpwindow_init (void);
void hwpwindow_deinit (void);

/**
 * hwpwindow_alloc: Allocate a new window with the given dimensions.
 *
 * @param height The height of the window.
 * @param width The width of the window.
 *
 * @return A pointer to the newly allocated window.
 *
 * @note: the allocated window will have a buffer and shadow buffer.
 */
HWPWINDOW *
hwpwindow_alloc (short height, short width)
{
  HWPWINDOW *window = malloc (sizeof (HWPWINDOW));

  window->height = height;
  window->width = width;
  window->current = hwpbuffer_alloc (height * width);
  window->shadow = hwpbuffer_alloc (height * width);

  return window;
}

/**
 * hwpwindow_dealloc: Deallocate the given window.
 *
 * @param window The window to deallocate.
 */
void
hwpwindow_dealloc (HWPWINDOW *window)
{
  if (window)
    {
      if (window->current)
        {
          hwpbuffer_dealloc (window->current);
        }

      if (window->shadow)
        {
          hwpbuffer_dealloc (window->shadow);
        }

      free (window);
    }
}

/**
 * hwpwindow_flip: Flip the shadow buffer to the window buffer.
 *
 * @param window The window to flip.
 * 
 * @note: this function resets the cursor position to the top left corner.
 * @note: this function copies the updated current buffer to the shadow buffer.
 */
void
hwpwindow_flip (HWPWINDOW *window)
{
  HWPBUFFER *temp = window->current;

  window->current = window->shadow;
  window->shadow = temp;

  hwpbuffer_copyInto (window->shadow, window->current);
}

/**
 * hwpwindow_paint: Paint the window to the screen.
 *
 * @param window The window to paint.
 */
void
hwpwindow_paint (HWPWINDOW *window)
{
  int row, col;

  for (row = 0; row < window->height; row++)
    {
      for (col = 0; col < window->width; col++)
        {
          // ignore null characters
          if (window->current->data[row * window->width + col] == '\0')
            {
              continue;
            }
            
          mvaddch (row, col, window->current->data[row * window->width + col]);
        }
    }

  refresh ();
}

/**
 * hwpwindow_init: Initialize the window.
 *
 * @note: this function must be called before any other window functions.
 */
void
hwpwindow_init (void)
{
  initscr ();            // initialize the screen
  cbreak ();             // disable line buffering
  noecho ();             // don't echo input
  keypad (stdscr, TRUE); // enable function keys
}

/**
 * hwpwindow_deinit: Deinitialize the window.
 *
 * @note: this function must be called after all other window functions.
 */
void
hwpwindow_deinit (void)
{
  endwin (); // deinitialize the screen
}

#endif