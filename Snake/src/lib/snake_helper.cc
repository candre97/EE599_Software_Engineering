// #include "snake_helper.h"

// // initialize the snake
// void InitSnake(int h, int w) {
//   _score = 0;
//   _height = h; 
//   _width = w; 
//   int row = (int ) _height / 4; 
//   int col = (int ) (_width / 4) + INIT_SNAKE_LEN;
//   for(int i = 0; i < INIT_SNAKE_LEN; i++) {
//     move(row,col); 
//     addch(SNAKE_CHAR); 
//     auto p = std::make_pair(row,col); 
//     _sl.push_back(p); 
//     col--;
//   }
// }

// // create food at some random point in the window
// // displays this to the window
// void CreateFood() {
//   std::srand(std::time(nullptr)); 
//   int col = std::rand() % (_width - 8); 
//   int row = std::rand() % (_height - 8); 
//   move(row,col); 
//   addch(FOOD_CHAR); 
//   _fl = std::make_pair(row,col); 
// }

// // Display the final score, called at the end of the game
// void DisplayScore() {
//   // clear snake
//   for(auto p : _sl) {
//     move(p.first, p.second); 
//     addch(' '); 
//   }
//   // clear food
//   move(_fl.first, _fl.second); 
//   addch(' '); 

//   // End of game output Screen
//   std::string score = "Your Score: " + std::to_string(_score); 
//   mvwprintw(stdscr, _height/2 - 3, _width/2-5, "%s", score.c_str());
//   std::string quit = "Press any key to quit"; 
//   mvwprintw(stdscr, _height/2 + 3, _width/2-8, "%s", quit.c_str());
//   getch();   // Wait for user input to quit
// }

// // Called to set the snakes direction of travel based on user input
// // void SetDir(int in_dir) {
// //   _dir = in_dir; 
// // }

// /* called every time the snake moves to a new square to check for:
// // 1. Snake bit himself
// // 2. Snake hit wall
// // 3. Snake ate food 
//   runtime: O(length)
//    4. else the square is empty
// */
// int CheckHeadPos() {
//   auto head = _sl.front(); 
//   if(head == _fl) {
//     return food; 
//   }
//   else if(head.first == 0 || head.second == 0 || 
//           head.first > _height-2 || head.second > _width-2) {
//     return wall; 
//   }
//   auto itr = _sl.begin(); 
//   itr++; 
//   for(itr; itr != _sl.end(); itr++) {
//     if(*itr == head) {
//       return snake; 
//     }
//   }
//   return empty; 
// }

// // pop_back & push front depending on direction of travel
// // displays this to the window
// void MoveSnake() {
//   _sl.pop_back(); 
//   auto p = _sl.front(); 
//   switch (_dir)
//   {
//   case KEY_LEFT:
//     /* code */
//     p.second--;
//     break;
//   case KEY_RIGHT:
//     /* code */
//     p.second++;
//     break;
//   case KEY_UP:
//     /* code */
//     p.first--;
//     break;
//   case KEY_DOWN:
//     /* code */
//     p.first++;
//     break;
//   default:
//     break;
//   }
//   _sl.push_front(p); 
// }

