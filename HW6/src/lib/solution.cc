#include "solution.h"

// question 6
// runtime: O(n) ~= O(2n)
void Solution::RearrangeVect(std::vector<int>& v, int idx) {
  if(idx >= v.size()) {
    std::cout << "idx out of range" << std::endl; 
    v.clear();
    return; 
  }
  int val = v[idx];
  std::vector<int> lt = {}; 
  std::vector<int> gt = {};
  for(auto n : v) {
    if(n > val) {
      gt.push_back(n);
    }
    else if(n < val){
      lt.push_back(n); 
    }
  }
  auto it = std::copy(lt.begin(), lt.end(), v.begin()); 
  *it = val;
  it++; 
  std::copy(gt.begin(), gt.end(), it); 
}
