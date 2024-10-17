#include <stdio.h>
#include <stdlib.h>

#include "window.h"

int
main (void)
{
    // allocate a new window
    HWPWINDOW *window = hwpwindow_alloc (10, 10, 0, 0);

    // add some text to the window and shadow buffer
    hwpbuffer_append (window->buffer, "Hello, World!", 13);
    hwpbuffer_append (window->shadow, "Goodbye, World!", 15);

    // print the window and shadow buffer
    printf ("Window Buffer:\n%s\n\n", window->buffer->data);
    printf ("Shadow Buffer:\n%s\n", window->shadow->data);

    // deallocate the window
    hwpwindow_dealloc (window);

    return EXIT_SUCCESS;
}