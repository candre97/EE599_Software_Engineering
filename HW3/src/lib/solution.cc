#include "solution.h"

std::string Solution::PrintHelloWorld() { 
  return "**** Hello World ****"; 
}

// Question 2
// runtime: O(n^2) = O(n^2 - n)
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

// Question 4
// runtime: O(n)
bool Solution::CheckBrackets(std::string s) {
  if(s[0] == '}' || s[0] == ')' ||s[0] == ']') {
    return false; 
  }
  std::stack<char> curly_s, bracket_s, paren_s; 
  std::set<char> l = {'(',')','[',']','{','}',}; 
  for(int i = 0; i < s.length(); i++) {
    char c = s[i]; 
    if(std::find(l.begin(), l.end(), c) == l.end()) {
      continue; 
    }
    if(c == '(') {
      paren_s.push(c);
    }
    else if(c == '[') {
      bracket_s.push('[');
    }
    else if(c == '{') {
      curly_s.push('{'); 
    }
    else if(c == ')') {
      if(paren_s.empty()){
        return false; 
      }
      paren_s.pop();
    }
    else if(c == ']') {
      if(bracket_s.empty()){
        return false; 
      }
      bracket_s.pop();
    }
    else if(c == '}') {
      if(curly_s.empty()){
        return false; 
      }
      curly_s.pop(); 
    }
  }
  if(curly_s.empty() && bracket_s.empty() && paren_s.empty()) {
    return true; 
  }
  else {
    return false; 
  }
}