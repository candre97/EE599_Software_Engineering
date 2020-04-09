#include "src/lib/solution.h"
#include <iostream>
#include <ncurses.h>
#include <string>
#include <unistd.h>

int main() {
  Solution solution;

  initscr();
  move(10,10); 
  addch('C'); 
  //refresh(); // Print it on to the real screen
  getch();   // Wait for user input
  endwin();
  return 0;
}