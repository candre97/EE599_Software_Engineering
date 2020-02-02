#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <array>
#include <set>
#include <iostream>
#define DEBUG         1


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
  void RemoveDupsNoSet(std::vector<int> &v); 
  void RemoveDups(std::vector<int> &v); 
  void ReverseOrder(std::vector<int> &v); 
  void RemoveOdds(std::vector<int> &v); 
  std::vector<int> ConcatVect(std::vector<int> &v1, std::vector<int> &v2);
  std::vector<int> UnionVect(std::vector<int> &v1, std::vector<int> &v2); 

  // question 4
  void SwapByRef(int &i1, int &i2); 
  void SwapPtrs(int *i1, int *i2); 

  // question 5
  void SwapCharByIdx(std::string &str, unsigned int idx1, unsigned int idx2); 
  void ReverseStr(std::string &str); 
  void ToLower(std::string &str); 

  // question 6
  bool FindPalindrome(str::string &str); 
  bool FindApproxPalindrome(std::string &str); 
};



#endif