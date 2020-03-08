#include "Maze.h"

// runtime O(1)
Maze::Maze(const std::vector<std::vector<int>>& m) {
  // if(m[0].size() != m.size()) {
  //   std::cout << "please give me a square maze" << std::endl; 
  //  }
  m_ = m; 
}

// helper function to check if a square is a valid move. 
// using the recursive approach because its much easier to visualize 
// square is the index of potential move
// runtime: O(1)
bool Maze::ValidMove(const std::pair<int,int>& square, const std::vector<std::vector<bool>>& searched) {
  int row = std::get<0>(square);
  int col = std::get<1>(square);
  int num_rows = m_.size(); 
  int num_cols = m_[row].size(); 

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
// runtime: O(N + E) = O(Nodes + Edges)
bool Maze::DFSMazeSolver(std::vector<std::vector<bool>>& searched, std::stack<std::pair<int,int>>& s, 
                          std::pair<int,int>& start, std::pair<int,int>& finish) {
  
  int row = std::get<0>(start);
  int col = std::get<1>(start);
  searched[row][col] = true; 

  if(!m_[row][col]) { 
    // you are somehow on an invalid square, maybe because of illegal starting point
    return false; 
  }

  if(start == finish) {
    // std::cout the path
    std::cout << "Path found! Follow this path (from finish to start): " << std::endl;
    while(!s.empty()) {
      auto p = s.top();
      s.pop(); 
      std::cout << "{" << std::get<0>(p) << ", " << std::get<1>(p) << "}" << std::endl; 
    }
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
      std::cout << "No Path Found!" << std::endl;
      return false; 
    }
    auto p = s.top(); 
    s.pop(); 
    return DFSMazeSolver(searched,s,p,finish); 
  }
  return false; // stupid complaining compiler
}

// calls recursive solution with matrix of bools all false and empty stack of matrix points
// runtime: O(N + E)
// runtime of creating this vect<vect<bool>> is O(Nodes)
bool Maze::SearchMaze(std::pair<int,int>& start, std::pair<int,int>& finish) {
  int row_s = std::get<0>(start);
  int col_s = std::get<1>(start);
  int row_f = std::get<0>(finish);
  int col_f = std::get<1>(finish);
  int num_rows = m_.size(); 
  int num_cols = m_[0].size(); 
  // check for invalid starting position
  if(row_s >= num_rows || col_s >= num_cols || row_s < 0 || col_s < 0) {
    return false;
  }
  if(row_f >= num_rows || col_f >= num_cols || row_f < 0 || col_f < 0) {
    return false;
  }
  std::vector<std::vector<bool>> b;
  std::vector<bool> temp = {}; 
  for(int i = 0; i < m_.size(); i++) {
    temp = {};
    for(int j = 0; j < m_[i].size(); j++) {
      temp.push_back(false); 
    }
    b.push_back(temp); 
  }
  std::stack<std::pair<int,int>> s; 
  return DFSMazeSolver(b, s, start, finish); 
}
