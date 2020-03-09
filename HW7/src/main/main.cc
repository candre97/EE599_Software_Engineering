#include "src/lib/solution.h"
#include <iostream>
#include <map>
#include <vector>

int main() {
  std::map<int, std::set<int>> in {
    {0, {1,4,5}}, 
    {1, {0,2,3}},
    {2, {1,3,8}},
    {3, {1,2}},
    {4, {0}},
    {5, {0,6}},
    {6, {5,7,8}},
    {7, {6,8}},
    {8, {2,6,7}}
  };
  
  Graph g(in);
  //std::vector<std::vector<int>> rs = g.ShortestPaths(0,8); 
  std::map<int, std::vector<int>> actual = g.BFSPath(0);  
  
  for(auto it = actual.begin(); it != actual.end(); it++) {
    std::cout << it->first << ": "; 
    for(auto n : it->second) {
      std::cout << n << ", "; 
    }
    std::cout << std::endl; 
  }
  
  
  /*std::cout << "vect: " << std::endl; 
  for(auto vect : rs) {
    std::cout << "{";
    for(auto n : vect) {
      std::cout << n << ", "; 
    }
    std::cout << "}" << std::endl; 
  }*/

  
  return EXIT_SUCCESS; 
}