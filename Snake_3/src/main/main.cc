#include "src/lib/snake_helper.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <list>
#include <thread>
#include <chrono>
#include <ncurses.h>

// game Macros
#define CHECK_INPUT      1

///////////////////////////////////////////////
// Thread For Moving Snake
//////////////////////////////////////////////
void UpdateSnake() {
  while(!game_over) {
    MoveSnake(); 
    std::this_thread::sleep_for(std::chrono::milliseconds(update_freqs[difficulty-1] - (2*_score))); 
  }
}

///////////////////////////////////////////////
// Thread For Getting Input
//////////////////////////////////////////////
void GetInput() {
  while(!game_over) {
#if CHECK_INPUT
    int in = getch(); 
    //_dir = in; 
    switch(in) {
      case KEY_UP:
        if(_dir != KEY_DOWN) {
          _dir = KEY_UP; 
        }
        break;
      case KEY_DOWN:
        if(_dir != KEY_UP) {
          _dir = KEY_DOWN; 
        }
        break; 
      case KEY_LEFT:
        if(_dir != KEY_RIGHT) {
          _dir = KEY_LEFT; 
        }
        break;
      case KEY_RIGHT:
        if(_dir != KEY_LEFT) {
          _dir = KEY_RIGHT; 
        }
        break;
      case 'q':
        game_over = true;
        break;
    }
  
#else
  _dir = getch(); 
#endif
  }
}

int main(int argc, char *argv[])  {

  char again = 'y'; 

  do
  {
    if(argc == 1) { // no previous high score 
      std::cout << "Welcome to the retro C++ Snake Game" << std::endl << std::endl; 
      std::this_thread::sleep_for(std::chrono::milliseconds(1500));
      std::cout << "For best results make your Terminal FULL SCREEN!" << std::endl << std::endl; 
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    else if (argc == 2) {
      char* p;
      long converted = strtol(argv[1], &p, 10);
      if (*p) {
        // conversion failed because the input wasn't a number
        std::cout << "Couldn't load previous high score" << std::endl; 
      }
      else {
        // use converted
        high_score = converted; 
        std::cout << "Loaded Previous High Score: " << high_score << std::endl; 
      }
    }
    std::cout << "Please select from the following levels of difficulty: " << std::endl;
    std::cout << "\t1) Novice" << std::endl; 
    std::cout << "\t2) Intermediate" << std::endl; 
    std::cout << "\t3) Snake Charmer" << std::endl; 
    std::cout << "Enter a number (1,2,3) to select your level of difficulty: " << std::endl; 
    std::cout << "> "; 
    std::cin >> difficulty;
    if(difficulty > 3 || difficulty < 1) {
      std::cout << "Invalid Selection" << std::endl << std::endl; 
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      std::cout << "Please select a valid option... " << std::endl; 
    }
  } while (difficulty > 3 || difficulty < 1);
  
  // screen initialization
  initscr();
  cbreak(); 
  noecho(); // suppress automatic echo of typed input
  keypad(stdscr, TRUE); // enable input of backspace, delete, arrow keys
  curs_set(0); // make cursor invisible

  // color initialization
  start_color(); // start color
  init_pair(snake_color, COLOR_YELLOW, COLOR_GREEN);
  init_pair(food_color, COLOR_RED, COLOR_BLACK);
  init_pair(blank_color, COLOR_BLACK, COLOR_BLACK);
  init_pair(b_and_w, COLOR_WHITE, COLOR_BLACK);
  if (has_colors() == FALSE) {
    endwin();
    std::cout << "Your terminal does not support color" << std::endl; 
    exit(1);
  }
  // create box outline of playing area
  clear(); 
  box(stdscr, 0 , 0); 
  refresh();
  int h, w;
  getmaxyx(stdscr, h, w);
  InitSnake(h,w); 
  CreateFood(); 
  refresh();
  
  // sleep for 1 second, then start the game
  std::this_thread::sleep_for(std::chrono::seconds(1)); 
  _dir = KEY_RIGHT; 

  refresh();
  std::thread m(UpdateSnake); 
  m.detach(); 

  std::thread in(GetInput);
  in.join();  // main thread stops here until input thread is done... 
  getch(); 
  
  if(_score > high_score) {
    std::cout << "NEW HIGH SCORE: " << _score  << std::endl << std::endl; 
    high_score = _score;
    NewHighScore(); 
    getch(); 
  }
  clear(); 
  endwin();

  std::cout << std::endl << "Current High Score: " << high_score << std::endl;; 
  std::cout << "Want to play again? [y/n]: ";
  std::cin >> again;  
  
  if(again == 'y') {
    std::string com = "cd ~/Documents/Spring_2020/EE599/Homeworks/EE599_Software_Engineering/Snake; ./bazel-bin/src/snake/main " + std::to_string(high_score); 
    system(com.c_str()); 
  }
  else {
    std::cout << std::endl << "Thanks for playing the C++ Snake Game!" << std::endl; 
    std::cout << "High Score for the Day: " << high_score << std::endl; 
    std::cout << "Goodbye!" << std::endl << std::endl; 
  }

  return 0;
}
