#include "solution.h"

std::string Solution::PrintHelloWorld() { 
  return "**** Hello World ****"; 
}

std::vector<int> Solution::VectSum(std::vector<int> v, int sum) {
  std::vector<int> retval;
  for(int i = 0; i < v.size(); i++) {
    for(int j = i; j < v.size(); j++) {
      if(sum == v[i] + v[j]) {
        retval = {i,j}; 
        return retval; 
      }
    }
  }
  return retval; 
}
