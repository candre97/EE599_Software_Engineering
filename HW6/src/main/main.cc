#include "src/lib/solution.h"
#include "src/lib/Graph.h"
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
  std::map<int, std::set<int>> vertices{
    {0, {1}},
    {1, {2, 3}},
    {2, {0}},
    {3, {4, 6}},
    {4, {}},
    {5, {6}},
    {6, {}}
  };

  Graph g(vertices);

  std::vector<int> ret = g.DFSAll(); 

  PrintVect(ret); 

  return EXIT_SUCCESS;
}