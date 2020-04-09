#include "snake.h"

// initialize and draw the first food
void Snake::CreateFood() {
  std::srand(std::time(nullptr)); 
  int col = std::rand() % (_width - 8); 
  int row = std::rand() % (_height - 8); 
  move(row,col); 
  addch(FOOD_CHAR); 
  _food_loc = std::make_pair(row,col); 
}

// initialize and draw the snake
Snake::Snake(int h, int w) {
  _score = 0;
  _height = h; 
  _width = w; 
  int row = (int ) _height / 4; 
  int col = (int ) _width / 4 + INIT_SNAKE_LEN;
  for(int i = 0; i < INIT_SNAKE_LEN; i++) {
    addch(SNAKE_CHAR); 
    auto p = std::make_pair(row,col); 
    _snake_loc.push_back(p); 
    col--;
    move(row,col); 
  }
}

// display the score, for the end of the game
void Snake::DisplayScore() {
  // clear snake
  for(auto p : _snake_loc) {
    move(p.first, p.second); 
    addch(' '); 
  }
  move(_food_loc.first, _food_loc.second); 
  addch(' '); 

  std::string score = "Your Score: " + std::to_string(_score); 
  mvwprintw(stdscr, _height/2 - 3, _width/2-5, "%s", score.c_str());

  std::string quit = "Press q to quit"; 
  mvwprintw(stdscr, _height/2 + 3, _width/2-5, "%s", quit.c_str());
  while(getch() != 'q');    // Wait for user input to quit
}

// new head position given by the
void Snake::MoveSnake() {
  
  auto it = _snake_loc.end(); 
  it--; 
  for(it; it != _snake_loc.begin(); it--) {

  }

  switch (_dir)
  {
  case KEY_LEFT:
    /* code */
    break;
  case KEY_RIGHT:
    /* code */
    break;
  case KEY_UP:
    /* code */
    break;
  case KEY_DOWN:
    /* code */
    break;
  default:
    break;
  }
}

int Snake::CheckHeadPos(){
  int ret = 0;

} 