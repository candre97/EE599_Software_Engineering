#include "solution.h"

// runtime: O(n)
std::vector<int> Solution::KeepEvens(std::vector<int>& v) {
  auto IsEven = [](int i) { return ((i % 2) == 0); };
  std::vector<int> ret(v.size());
  auto it = std::copy_if(v.begin(), v.end(), ret.begin(), IsEven);
  ret.resize(std::distance(ret.begin(),it)); 
  return ret;
}

// runtime: O(n)
std::vector<int> Solution::SquareNums(std::vector<int>& v) {
  auto SquareNum = [](int i) { return i*i; };
  std::vector<int> ret(v.size());
  std::transform(v.begin(), v.end(), ret.begin(), SquareNum); 
  return ret; 
}

int Solution::SumVect(std::vector<int>& v) {
  int retval = std::accumulate(v.begin(), v.end(), 0); 
  return retval; 
} 
