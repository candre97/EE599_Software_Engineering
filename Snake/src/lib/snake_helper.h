// #ifndef SNAKE_HELPER_H
// #define SNAKE_HELPER_H

// #include <map>
// #include <ncurses.h>
// #include <string>
// #include <unistd.h>
// #include <vector>
// #include <list>
// #include <ctime>
// #include <algorithm>
// #include <iterator>

// // MACROS
// #define INIT_SNAKE_LEN   5
// #define FOOD_CHAR        ACS_CKBOARD
// #define SNAKE_CHAR       ACS_DIAMOND

// // variables
// std::list<std::pair<int,int>> _sl;  // snake location
// std::pair<int,int> _fl;             // food location  
// int _width = 0;   // of window
// int _height = 0;  // of window
// int _score = 0;   // score
// int _dir = 0;     // direction of travel

// enum square {
//   empty = 0,
//   food = 1,
//   wall = 2,
//   snake = 3
// };

// ///////////////////////////////////////////
// // Functions
// ///////////////////////////////////////////

// // initialize the snake
// void InitSnake(int h, int w); 

// // create food at some random point in the window
// // displays this to the window
// void CreateFood();

// // Display the final score, called at the end of the game
// //void DisplayScore(); 

// // Called to set the snakes direction of travel based on user input
// // void SetDir(int in_dir); // does the heavy lifting of moving the snake

// /* called every time the snake moves to a new square to check for:
// // 1. Snake bit himself
// // 2. Snake hit wall
// // 3. Snake ate food */
// //int CheckHeadPos(); // check where the head is now

// // pop_back & push front depending on direction of travel
// // displays this to the window
// //void MoveSnake(); 

// #endif