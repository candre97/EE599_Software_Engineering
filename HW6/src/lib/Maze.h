#ifndef MAZE_H
#define MAZE_H

#include <map>
#include <string>
#include <vector>
#include <stack>
#include <utility> 
#include <iostream>

class Maze {
public:
  Maze(const std::vector<std::vector<int>>& m);
  bool ValidMove(const std::pair<int,int>& square, const std::vector<std::vector<bool>>& searched);
  bool DFSMazeSolver(std::vector<std::vector<bool>>& searched, std::stack<std::pair<int,int>>& s, 
                          std::pair<int,int>& start, std::pair<int,int>& finish); 
  bool SearchMaze(std::pair<int,int>& start, std::pair<int,int>& finish);  
private: 
  std::vector<std::vector<int>> m_; 
};

#endif