#include "solution.h"

// runtime: O(n)
std::vector<int> Solution::KeepEvens(const std::vector<int>& v) {
  auto IsEven = [](int i) { return ((i % 2) == 0); };
  std::vector<int> ret(v.size());
  auto it = std::copy_if(v.begin(), v.end(), ret.begin(), IsEven);
  ret.resize(std::distance(ret.begin(),it)); 
  return ret;
}

// runtime: O(n)
std::vector<int> Solution::SquareNums(const std::vector<int>& v) {
  auto SquareNum = [](int i) { return i*i; };
  std::vector<int> ret(v.size());
  std::transform(v.begin(), v.end(), ret.begin(), SquareNum); 
  return ret; 
}

int Solution::SumVect(const std::vector<int>& v) {
  int retval = std::accumulate(v.begin(), v.end(), 0); 
  return retval; 
} 

// Question 5
// runtime (n logn)
std::vector<int> Solution::QueueSort(const std::vector<int>& v) {
  std::vector<int> ret;
  std::priority_queue<int> pq; 
  for(auto n : v) {
    pq.push(n); 
  }
  while(pq.size() > 0) {
    ret.insert(ret.begin(), pq.top()); 
    pq.pop(); 
  }
  return ret; 
}