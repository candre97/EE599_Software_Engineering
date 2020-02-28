#include "src/lib/solution.h"
#include "src/lib/Graph.h"
#include "src/lib/Maze.h"
#include <iostream>
#include <map>
#include <vector>

void PrintVect(std::vector<int> v) {
  std::cout << "------------------" << std::endl; 
  std::cout << "{ ";
  for(auto n : v) {
    std::cout << n << ", "; 
  }
  std::cout << "{ ";
  std::cout << "------------------" << std::endl; 
}

int main() {
  // Print Hellow world!
  std::vector<std::vector<int>> in1 = {
    {1, 1, 0, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1,}
  };
  
  Maze* m = new Maze(in1); 
  auto s = std::make_pair(0,0); 
  auto f = std::make_pair(4,4);
  bool ret = m->SearchMaze(s, f); 
  std::cout << ret << std::endl; 

std::vector<std::vector<int>> in2 = {
      {1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1},
      {0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0},
      {1, 1, 1, 1, 1}
  };

  Maze* m2 = new Maze(in2); 
  auto s2 = std::make_pair(1,2); 
  auto f2 = std::make_pair(4,4);
  bool ret2 = m2->SearchMaze(s2, f2); 
  std::cout << ret2 << std::endl; 
  
  return EXIT_SUCCESS;
}