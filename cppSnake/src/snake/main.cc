#include "src/lib/solution.h"
#include <chrono>
#include <ctime>
#include <iomanip> // put_time
#include <iostream>
#include <ncurses.h>
#include <sstream> // stringstream

int main() {
  Solution solution;

  initscr();
  cbreak(); 
  noecho();
  solution.drawcircle(20, 10, 5);
  refresh(); // Print it on to the real screen
  getch();   // Wait for user input
  getch(); 
  endwin();

  return EXIT_SUCCESS;
}