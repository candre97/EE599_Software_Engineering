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
  std::cout << "} ";
  std::cout << "------------------" << std::endl; 
}

int main() {
  Solution sol; 
  std::vector<int> v = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6}; 
  //std::vector<int> v = {1,2,3,66,33,12,54,102,1002}; 
  int i=0; 
  sol.RearrangeVect(v,i); 
  
  PrintVect(v); 


  return EXIT_SUCCESS;
}