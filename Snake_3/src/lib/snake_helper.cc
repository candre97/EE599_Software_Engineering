#include "snake_helper.h"
#include <map>
#include <ncurses.h>



///////////////////////////////////////////////
// Snake Helper Functions
//////////////////////////////////////////////
// initialize the snake
void InitSnake(int h, int w) {
  _score = 0;
  _height = h; 
  _width = w; 
  _sl.clear(); 
  int row = (int ) _height / 4; 
  int col = (int ) (_width / 4) + INIT_SNAKE_LEN;
  attron(COLOR_PAIR(snake_color)); // Change color
  for(int i = 0; i < INIT_SNAKE_LEN; i++) {
    move(row,col); 
    addch(SNAKE_CHAR); 
    auto p = std::make_pair(row,col); 
    _sl.push_back(p); 
    col--;
  }
  refresh(); 
}

// create food at some random point in the window
// displays this to the window
void CreateFood() {
  std::srand(std::time(nullptr)); 
  int col = std::rand() % (_width - 8) + 2; 
  int row = std::rand() % (_height - 8) + 2; 
  move(row,col); 
  attron(COLOR_PAIR(food_color)); // Change color
  addch(FOOD_CHAR); 
  _fl = std::make_pair(row,col); 
}

// Display the final score, called at the end of the game
void NewHighScore() {
  // clear screen
  attron(COLOR_PAIR(b_and_w));
  clear(); 
  std::string score = "NEW HIGH SCORE: " + std::to_string(high_score); 
  mvwprintw(stdscr, _height/2, _width/2-5, "%s", score.c_str());
}

// Display the final score, called at the end of the game
void DisplayScore() {
  // clear screen
  attron(COLOR_PAIR(b_and_w));
  clear(); 
  std::string score = "Your Score: " + std::to_string(_score); 
  mvwprintw(stdscr, _height/2 - 3, _width/2-5, "%s", score.c_str());
  std::string quit = "Press any key"; 
  mvwprintw(stdscr, _height/2 + 3, _width/2-6, "%s", quit.c_str());
}

void AddSegmentFront() {
  // add some snake length!!
  auto p = _sl.front(); 
  switch (_dir)
  { //row, h, 1st
    // col, w, 2nd
    case KEY_LEFT:
      /* code */
      p.second = std::max(0,p.second-1); 
      break;
    case KEY_RIGHT:
      /* code */
      p.second = std::min(p.second+1, _width); 
      break;
    case KEY_UP:
      /* code */
      p.first = std::max(0, p.first-1);
      break;
    case KEY_DOWN:
      /* code */
      p.first = std::min(p.first+1, _height); 
      break;
    default:
      break;
  }
  _sl.push_front(p); 

  // draw the updated position
  int row = _sl.front().first; 
  int col = _sl.front().second; 
  attron(COLOR_PAIR(snake_color));
  move(row,col); 
  addch(SNAKE_CHAR); 
  refresh(); 
}


/* called every time the snake moves to a new square to check for:
// Snake bit himself
// Snake hit wall
// Snake ate food 
  runtime: O(length)
   else the square is empty
*/
int CheckHeadPos() {
  auto head = _sl.front(); 
  if(head == _fl) {
    _score++; 
    CreateFood(); 
    AddSegmentFront(); 
    AddSegmentFront(); 
    return food; 
  }
  else if(head.first < 1 || head.second < 1 || 
          head.first > _height-2 || head.second > _width-2) {
    game_over = wall; 
    // DisplayScore();
    // getch(); 
    return wall; 
  }
  auto itr = _sl.begin(); 
  itr++; 
  for(itr; itr != _sl.end(); itr++) {
    if(*itr == head) {
      game_over = snake;
      // DisplayScore();
      // getch(); 
      return snake; 
    }
  }
  return empty; 
}

// pop_back & push front depending on direction of travel
// displays this to the window
void MoveSnake() {
  int row = _sl.back().first; 
  int col = _sl.back().second; 
  move(row,col); 
  attron(COLOR_PAIR(blank_color)); // Change color
  addch(' '); 
  _sl.pop_back(); 
  AddSegmentFront(); 
  int res = CheckHeadPos(); 
  if(res == wall) {
    clear(); 
    DisplayScore(); 
    getch();
  }
  else if(res == snake) {
    clear(); 
    DisplayScore();
    getch();
  }
}
