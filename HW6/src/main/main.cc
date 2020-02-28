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
  std::vector<std::vector<int>> in = {
    {1, 1, 0, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1,}
  };

  std::vector<std::vector<bool>> b(5);
  for(int i=0; i<b.size(); i++)
  {
    for(int j=0; j<b[0].size();j++)
    std::cout << b[i][j] << " ";
    std::cout << "\n";
  }
  PrintVect(in[0]); 

  return EXIT_SUCCESS;
}