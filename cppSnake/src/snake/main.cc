#include "src/lib/solution.h"
#include "src/lib/snake.h"
#include <chrono>
#include <ctime>
#include <iomanip> // put_time
#include <iostream>
#include <ncurses.h>
#include <sstream> // stringstream

int main() {
  Solution solution;
  bool end_of_game = false;
  initscr();
  cbreak(); 
  noecho(); // suppress automatic echo of typed input
  keypad(stdscr, TRUE); // enable input of backspace, delete, arrow keys
  start_color(); 
  
  /////////////////////////////////////////////////
  // Initialize Game Board
  //////////////////////////////////////////////////
  box(stdscr, 0 , 0); 
  int h, w;
  getmaxyx(stdscr, h, w);
  Snake* snk = new Snake(h,w); 
  snk->CreateFood(); 
  //WINDOW* win = newwin(170,170,0,0); 
  
  //solution.drawcircle(20, 10, 5);
  //solution.drawcircle(20, 17, 5);
  //wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
  
  refresh(); // Print it on to the real screen

  // addch(ACS_CKBOARD);
  
  refresh();

  /////////////////////////////////////////////////
  // Game loop
  //////////////////////////////////////////////////
  int input; 
  while(!end_of_game) {
    input = getch(); 
    switch(input) {
      case KEY_UP:
        break;
      case KEY_DOWN:
        break; 
      case KEY_LEFT:
        break;
      case KEY_RIGHT:
        break;
      case 'q':
        end_of_game = true;
        break;
    } 
  }

  while(getch() != 'q');    // Wait for user input to quit
  endwin();
  std::cout << "H: " << h << std::endl <<  "W: " << w << std::endl; 

  std::cout << "Snake position: ";
  auto it = snk->_snake_loc.begin(); 
  for(it; it != snk->_snake_loc.end(); it++) {
    std::cout << "{" <<  it->first << ", " << it->second << "}, ";
  }
  std::cout << std::endl; 

  std::cout << "Food position: "; 
  std::cout << snk->_food_loc.first << "," << snk->_food_loc.second << std::endl; 

  return EXIT_SUCCESS;
}