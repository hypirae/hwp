#include "ApplicationWindow.h"

/**
 * Constructor
 *
 * Creates a new instance of `ApplicationWindow` which initializes
 * ncurses when called. This class should only be used once within
 * the application and should only appear in the main function.
 */
ApplicationWindow::ApplicationWindow () : Window()
{
  // initialize ncurses
  initscr ();

  // set the screen to stdscr
  this->screen = stdscr;

  // configure ncurses
  noecho ();             // Don't echo input
  cbreak ();             // Don't buffer input
  raw ();                // Don't generate signals
  keypad (this->screen, TRUE); // Enable special keys
}

/**
 * Deconstructor
 *
 * Destroys the instance of `ApplicationWindow` and cleans up ncurses.
 * This function should only be called once at the end of the application
 * as it calls `endwin()` which will close the ncurses window.
 */
ApplicationWindow::~ApplicationWindow ()
{
  // end ncurses
  endwin ();
}