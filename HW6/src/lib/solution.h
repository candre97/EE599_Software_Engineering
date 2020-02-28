#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <map>
#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>

class Solution {
public:
  // question 6
  void RearrangeVect(std::vector<int>& v, int idx); 
  void Partition (std::vector<int> v, int low, int high); 
};

#endif