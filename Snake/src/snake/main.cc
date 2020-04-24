#include <ncurses.h>
#include <iostream>
//#include <ncurses.h>
#include <string>
#include <unistd.h>
#include <list>
#include <thread>
#include <chrono>
//#include <mutex>

///////////////////////////////////////////////
// Snake Helper
//////////////////////////////////////////////

// MACROS
#define INIT_SNAKE_LEN   5
#define FOOD_CHAR        ACS_CKBOARD
#define SNAKE_CHAR       ACS_DIAMOND
#define CHECK_INPUT      1

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

///////////////////////////////////////////////
// Thread For Moving Snake
//////////////////////////////////////////////
void UpdateSnake() {
  while(!game_over) {
    MoveSnake(); 
    std::this_thread::sleep_for(std::chrono::milliseconds(update_freqs[difficulty-1] - (2*_score))); 
  }
}

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
