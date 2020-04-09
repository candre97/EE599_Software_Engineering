#include "snake.h"

void Snake::CreateFood() {
  std::srand(std::time(nullptr)); 
  int col = std::rand() % (_width - 8); 
  int row = std::rand() % (_height - 8); 
  move(row,col); 
  addch(FOOD_CHAR); 
  _food_loc = std::make_pair(row,col); 
}

Snake::Snake(int h, int w) {
  _height = h; 
  _width = w; 
  int row = (int ) _height / 4; 
  int col = (int ) _width / 4;
  for(int i = 0; i < INIT_SNAKE_LEN; i++) {
    // if(!i) {

    // }
    addch(SNAKE_CHAR); 
    auto p = std::make_pair(row,col); 
    _snake_loc.push_back(p); 
    col++;
    move(row,col); 
  }
}

