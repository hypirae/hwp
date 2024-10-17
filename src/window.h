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
 * @x The current x coordinate of the cursor.
 * @y The current y coordinate of the cursor.
 * @buffer The buffer of the window.
 * @shadow The shadow buffer of the window.
 *
 * @note: the window is a simple buffer with dimensions.
 */
typedef struct hwp_window
{
  short height;
  short width;
  short x;
  short y;
  HWPBUFFER *current;
  HWPBUFFER *shadow;
} HWPWINDOW;

// forward declarations
HWPWINDOW *hwpwindow_alloc (short height, short width, short x, short y);
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
 * @param x current x coordinate of the cursor.
 * @param y current y coordinate of the cursor.
 *
 * @return A pointer to the newly allocated window.
 *
 * @note: the allocated window will have a buffer and shadow buffer.
 */
HWPWINDOW *
hwpwindow_alloc (short height, short width, short x, short y)
{
  HWPWINDOW *window = malloc (sizeof (HWPWINDOW));

  window->height = height;
  window->width = width;
  window->x = x;
  window->y = y;
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
  window->x = 0;
  window->y = 0;

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
  for (size_t i = 0; i < window->current->size; i++)
    {
      if (window->x >= window->width)
        {
          window->x = 0;
          window->y++;
        }

      if (window->y >= window->height)
        {
          break;
        }

      mvaddch (window->y, window->x, window->current->data[i]);
      window->x++;
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