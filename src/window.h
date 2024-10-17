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
  HWPBUFFER *buffer;
  HWPBUFFER *shadow;
} HWPWINDOW;

// forward declarations
HWPWINDOW *hwpwindow_alloc (short height, short width, short x, short y);
void hwpwindow_dealloc (HWPWINDOW *window);

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
HWPWINDOW*
hwpwindow_alloc (short height, short width, short x, short y)
{
  HWPWINDOW *window = malloc (sizeof (HWPWINDOW));

    window->height = height;
    window->width = width;
    window->x = x;
    window->y = y;
    window->buffer = hwpbuffer_alloc (height * width);
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
      if (window->buffer)
        {
          hwpbuffer_dealloc (window->buffer);
        }

      if (window->shadow)
        {
          hwpbuffer_dealloc (window->shadow);
        }

      free (window);
    }
}
#endif