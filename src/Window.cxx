#include "Window.h"

/**
 * Constructor
 *
 * This function initializes the window.
 */
Window::Window () { this->screen = NULL; }

/**
 * Constructor
 *
 * This function initializes the window.
 *
 * @param screen The screen to initialize the window with.
 */
Window::Window (WINDOW *screen) : screen (screen)
{
  if (this->screen == NULL)
    {
      this->screen = initscr ();
    }
}

/**
 * Destructor
 *
 * This function cleans up the window.
 */
Window::~Window ()
{
  if (this->screen != NULL)
    {
      if (this->screen != stdscr)
        {
          delwin (this->screen);
        }
    }
}

/**
 * Gets the screen width
 *
 * @return int
 */
int
Window::getScreenWidth ()
{
  return getcurx (this->screen);
}

/**
 * Gets the screen height
 *
 * @return int
 */
int
Window::getScreenHeight ()
{
  return getcury (this->screen);
}

/**
 * Gets the screen width
 *
 * @return int
 */
void
Window::clear ()
{
  wclear (this->screen);
}

/**
 * Refreshes the screen
 *
 * @return void
 */
void
Window::refresh ()
{
  wrefresh (this->screen);
}

/**
 * Moves the cursor to the specified position
 *
 * @param size_t x
 * @param size_t y
 * @return void
 */
void
Window::move (size_t x, size_t y)
{
  wmove (this->screen, y, x);
}

/**
 * Gets a string of characters from the current cursor position.
 *
 * This function retrieves a string of characters from the current cursor
 * position.
 *
 * @param len The length of the string to retrieve.
 * @return The string of characters retrieved.
 */
std::string
Window::get (size_t len)
{
  std::string str;

  str.reserve (len);

  for (size_t i = 0; i < len; i++)
    {
      str.push_back (wgetch (this->screen));
    }

  return str;
}

/**
 * Puts a string of characters at the current cursor position.
 *
 * This function puts a string of characters at the current cursor position.
 *
 * @param str The string of characters to put at the current cursor position.
 */
void
Window::put (const std::string &str)
{
  waddstr (this->screen, str.c_str ());
}

/**
 * Gets a string of characters at a given position.
 *
 * This function retrieves a string of characters at a given position.
 *
 * @param x The x position to get the string of characters from.
 * @param y The y position to get the string of characters from.
 * @param len The length of the string to retrieve.
 * @return The string of characters retrieved.
 */
std::string
Window::getAt (size_t x, size_t y, size_t len)
{
  std::string str;

  str.reserve (len);

  for (size_t i = 0; i < len; i++)
    {
      str.push_back (mvwinch (this->screen, y, x + i));
    }

  return str;
}

/**
 * Puts a string of characters at a given position.
 *
 * This function puts a string of characters at a given position.
 *
 * @param str The string of characters to put at the given position.
 * @param x The x position to put the string of characters at.
 * @param y The y position to put the string of characters at.
 */
void
Window::putAt (const std::string &str, size_t x, size_t y)
{
  mvwaddstr (this->screen, y, x, str.c_str ());
}

/**
 * Gets a character at the current cursor position.
 *
 * This function retrieves the character at the current cursor position.
 *
 * @return The character at the current cursor position.
 */
int
Window::getChar ()
{
  return wgetch (this->screen);
}

/**
 * Puts a character at the current cursor position.
 *
 * This function puts a character at the current cursor position.
 *
 * @param ch The character to put at the current cursor position.
 */
void
Window::putChar (int ch)
{
  waddch (this->screen, ch);
}

/**
 * Gets a character at a given position.
 *
 * This function retrieves the character at a given position.
 *
 * @param x The x position to get the character from.
 * @param y The y position to get the character from.
 * @return The character at the given position.
 */
int
Window::getCharAt (size_t x, size_t y)
{
  return mvwinch (this->screen, y, x);
}

/**
 * Puts a character at a given position.
 *
 * This function puts a character at a given position.
 *
 * @param ch The character to put at the given position.
 * @param x The x position to put the character at.
 * @param y The y position to put the character at.
 */
void
Window::putCharAt (int ch, size_t x, size_t y)
{
  mvwaddch (this->screen, y, x, ch);
}