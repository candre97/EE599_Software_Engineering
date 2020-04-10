#ifndef SNAKE_H
#define SNAKE_H

#include <map>
#include <ncurses.h>
#include <string>
#include <unistd.h>
#include <vector>
#include <list> 
#include <cstdlib>
#include <ctime> 

#define INIT_SNAKE_LEN   5
#define FOOD_CHAR        ACS_CKBOARD
#define SNAKE_CHAR       ACS_DIAMOND

class Snake {
public:
  Snake(int h, int w);  // constructor that draws the snake in starting position
  void CreateFood(); // create some new food on the Map
  void DisplayScore(); // display the score
  void MoveSnake(); // does the heavy lifting of moving the snake
  int CheckHeadPos(); // check where the head is now
  void EraseSnake(); 
  void DrawSnake(); 

  std::vector<std::pair<int,int>> _snake_loc;
  std::pair<int,int> _food_loc;  
  int _width;   // of window
  int _height;  // of window
  int _score;   // score
  int _dir;     // direction of travel
}; 

#endif