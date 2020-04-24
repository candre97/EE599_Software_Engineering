#ifndef SNAKE_HELPER_H
#define SNAKE_HELPER_H

#include <ncurses.h>
#include <list> 
#include <chrono>
#include <string>

///////////////////////////////////////////////
// Snake Helper
//////////////////////////////////////////////

// MACROS
#define INIT_SNAKE_LEN   5
#define FOOD_CHAR        ACS_CKBOARD
#define SNAKE_CHAR       ACS_DIAMOND

// snake variables
std::list<std::pair<int,int>> _sl;  // snake location
std::pair<int,int> _fl;             // food location  
int _width = 0;   // of window
int _height = 0;  // of window
int _score = 0;   // score
int _dir = KEY_RIGHT;     // direction of travel

// game variables
int game_over = 0; // control for end of game
int update_freqs[3] = {100, 65, 50};  // miliseconds
int difficulty = 0;
int high_score = 0; 

// whats in this square?
enum square {
  empty = 0,
  food = 1,
  wall = 2,
  snake = 3
};

// keep track of colors
enum colors {
  snake_color = 1,
  food_color = 2, 
  blank_color = 3,
  b_and_w = 4
};

// initialize the snake
void InitSnake(int h, int w); 

// create food at some random point in the window
// displays this to the window
void CreateFood();

// Display the final score, called at the end of the game
void DisplayScore(); 

void NewHighScore(); 
/* called every time the snake moves to a new square to check for:
// 1. Snake bit himself
// 2. Snake hit wall
// 3. Snake ate food */
int CheckHeadPos(); // check where the head is now

// pop_back & push front depending on direction of travel
// displays this to the window
void MoveSnake(); 



#endif