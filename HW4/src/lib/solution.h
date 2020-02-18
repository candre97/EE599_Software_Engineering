#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm> 
#include <iterator>

class Solution {
public:
  
  // Question 1
  std::vector<int> KeepEvens(const std::vector<int>& v); 
  std::vector<int> SquareNums(const std::vector<int>& v); 
  int SumVect(const std::vector<int>& v); 

  // Question 5
  std::vector<int> QueueSort(const std::vector<int>& v); 

  // Question 6
  int FindKthLargest(std::vector<int>& v, int k); 

};

#endif