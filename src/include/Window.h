#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <memory>
#include <string>

#include <ncurses.h>

class Window
{
public:
  Window ();
  Window (WINDOW *screen);
  ~Window ();

  // screen attributes
  int getScreenWidth ();
  int getScreenHeight ();

  // screen functions
  void clear ();
  void refresh ();

  // cursor functions
  void move (size_t x, size_t y);

  // string I/O
  std::string get (size_t len);
  void put (const std::string &str);
  std::string getAt (size_t x, size_t y, size_t len);
  void putAt (const std::string &str, size_t x, size_t y);

  // character I/O
  int getChar ();
  void putChar (int ch);
  int getCharAt (size_t x, size_t y);
  void putCharAt (int ch, size_t x, size_t y);

protected:
  WINDOW *screen; // ncurses stdscr
};

#endif