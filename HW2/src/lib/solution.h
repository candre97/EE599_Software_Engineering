#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <array>



class Solution {
public:
  std::string PrintHelloWorld();
  
  int Add(int a, int b);

  // question 1
  std::string Add(std::string &a, std::string &b);

  std::string Add(std::string &a, int b);

  std::string Add(int a, std::string &b); 

  // question 2 in main.cc

  // question 3 
};



#endif