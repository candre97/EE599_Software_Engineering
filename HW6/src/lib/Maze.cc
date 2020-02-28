#include "Maze.h"

Maze::Maze(const std::vector<std::vector<int>>& m) {
  // if(m[0].size() != m.size()) {
  //   std::cout << "please give me a square maze" << std::endl; 
  //  }
  m_ = m; 
}

// helper function to check if a square is a valid move. 
// square is the index of potential move
bool Maze::ValidMove(const std::pair<int,int>& square, const std::vector<std::vector<bool>>& searched) {
  int row = std::get<0>(square);
  int col = std::get<1>(square);
  int num_rows = m_.size(); 
  int num_cols = m_[row].size();  // allows for non square mazes!

  // check out of bounds
  if(row >= num_rows || col >= num_cols || row < 0 || col < 0) {
    return false;
  }
  // check if you've already searched there
  else if(searched[row][col]) {
    return false; 
  }
  // check if the sqaure is shaded
  else if(!m_[row][col]) {
    return false;
  }
  // if not shaded and not in there yet, go there!
  return true; 
}

// recursive solution
// start will be where you are currently
// end is base case
bool Maze::DFSMazeSolver(std::vector<std::vector<bool>>& searched, std::stack<std::pair<int,int>>& s, 
                          std::pair<int,int>& start, std::pair<int,int>& finish) {
  
  int row = std::get<0>(start);
  int col = std::get<1>(start);
  searched[row][col] = true; 

  if(start == finish) {
    return true;  // base case
  }
  // search up, down, left, right
  if(ValidMove(std::pair<int,int>(row-1,col), searched)) { // up
    auto p = std::make_pair(row-1,col);
    s.push(p); 
    return DFSMazeSolver(searched,s,p,finish); 
  }
  else if(ValidMove(std::pair<int,int>(row+1,col), searched)) { // down
    auto p = std::make_pair(row+1,col);
    s.push(p); 
    return DFSMazeSolver(searched,s,p,finish); 
  }
  else if(ValidMove(std::pair<int,int>(row,col-1), searched)) { // left
    auto p = std::make_pair(row,col-1);
    s.push(p); 
    return DFSMazeSolver(searched,s,p,finish); 
  }
  else if(ValidMove(std::pair<int,int>(row,col+1), searched)) { // right
    auto p = std::make_pair(row,col+1);
    s.push(p); 
    return DFSMazeSolver(searched,s,p,finish); 
  }
  else { // no valid moves!! 
    // pop from stack, make that your current position, call Maze Solver on last point
    // We are backtracking!
    if(s.empty()) { // nowhere to go and can't go back (we are back at the start, have exhausted all options)
      return false; 
    }
    auto p = s.top(); 
    s.pop(); 
    return DFSMazeSolver(searched,s,p,finish); 
  }
  return false; // stupid complaining compiler
}

// calls recursive solution with matrix of bools all false and empty stack of matrix points
bool Maze::SearchMaze(std::pair<int,int>& start, std::pair<int,int>& finish) {
  std::vector<std::vector<bool>> b;
  for(auto row : m_) {
    for(auto cell : row) {
      
    }
  }

}
