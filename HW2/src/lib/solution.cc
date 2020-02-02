#include "solution.h"

std::string Solution::PrintHelloWorld() { 
  return "**** Hello World ****"; 
}

///////////////////////////////
// question 1
////////////////////////////////
/* 
Write several functions with the same name Add using function overloading to satisfy the
following requirements:
● All three functions take 2 parameters as the input.
● If both inputs are integers perform addition and return the result.
● If both inputs are string, concatenate both the strings and return the output.
● If the first input is an integer and the second input is a string or vice-versa your code
should return a string that will hold the concatenated value of both the inputs.
*/

// Function 1.1:
// inputs: 2 ints
// outputs: 1 int
// runtime: O(1)
int Solution::Add(int a, int b) {
  return (int) a + b; 
}

// Function 1.2:
// inputs: 2 strings
// outputs: 1 string
// runtime: O(len(a) + len(b)) = O(n)
std::string Solution::Add(std::string &a, std::string &b) {
  return a + b; 
}

// Function 1.3:
// inputs: 1 string, 1 int
// outputs: 1 string
// runtime: O(len(a) + len(str(b)) + TODO: find runtime of to_string()) = O(n)
std::string Solution::Add(std::string &a, int b) {
  return a + std::to_string(b); 
}

// Function 1.4:
// inputs:  1 int, 1 string
// outputs: 1 string
// runtime: O(len(b) + len(str(a)) + O(1)) = O(n)
std::string Solution::Add(int a, std::string &b) {
  return std::to_string(a) + b; 
}

////////////////////////////////////////////
// Question 3
///////////////////////////////////////////

// Function 3.1:
// inputs:  1 vector (by reference)
// outputs: void -- changes input vector
// runtime: O(n^2)
void Solution::RemoveDupsNoSet(std::vector<int> &v) {
  for(int i = 0; i < v.size(); i++) {
    if(std::count(v.begin(), v.end(), v[i]) > 1) {
      v.erase(v.begin() + i); 
#if DEBUG
      std::cout << "rm dup " << v[i] << " at index " << i << std::endl;
#endif
      i--; 
    } 
  }
}

// Function 3.2:
// inputs:  1 vector (by reference)
// outputs: void -- changes input vector
// runtime: O(n + nlogn) => O(nlogn)
void Solution::RemoveDups(std::vector<int> &v) {
  std::set<int> s(v.begin(), v.end()); 
  v.assign(s.begin(), s.end()); 
}

// Function 3.3:
// inputs:  1 vector (by reference)
// outputs: void -- changes input vector
// runtime: O(n/2) => O(n)
void Solution::ReverseOrder(std::vector<int> &v) {
  int middle = (int) (v.size() / 2); 
  for(int i = 0; i < middle; i++) {
    std::swap(v[i], v[v.size() - 1 - i]); 
  }
}

// Function 3.4:
// inputs:  1 vector (by reference)
// outputs: void -- changes input vector
// runtime: O(n)
void Solution::RemoveOdds(std::vector<int> &v) {
  for(int i = 0; i < v.size(); i++) {
    if(v[i] % 2) {
      v.erase((v.begin() + i)); 
      i--; 
    }
  }
}

// Function 3.5:
// inputs:  2 vectors (by reference)
// outputs: 1 vector of ints
// runtime: O(n1 + n2) = O(n)
std::vector<int> Solution::ConcatVect(std::vector<int> &v1, std::vector<int> &v2) {
  std::vector<int> retval; 
  for(auto n : v1) {
    retval.push_back(n); 
  }
  for(auto n : v2) {
    retval.push_back(n); 
  }
  return retval; 
}

// Function 3.4:
// inputs:  2 vectors (by reference)
// outputs: 1 vector of ints
// runtime: O(n1 * n2) = O(n^2)
std::vector<int> Solution::UnionVect(std::vector<int> &v1, std::vector<int> &v2) {
  std::vector<int> retval;
  for(auto n : v1) {
    if(std::find(v2.begin(), v2.end(), n) != std::end(v2)) {
      retval.push_back(n); 
    }
  }
  return retval;  
}

////////////////////////////////////////////
// Question 4
///////////////////////////////////////////

// Function 4.1: Swap using references
// inputs:  2 ints (by reference)
// outputs: none
// runtime: O(1)
void Solution::SwapByRef(int &i1, int &i2) {
  int temp = i1; 
  i1 = i2; 
  i2 = temp; 
} 
 

// Function 4.2: Swap using pointers
// inputs:  2 int (by reference)
// outputs: none
// runtime: O(1)
void Solution::SwapPtrs(int *i1, int *i2) {
  int temp = *i1;  
  *i1 = *i2; 
  *i2 = temp; 
}

////////////////////////////////////////////
// Question 5
///////////////////////////////////////////

// Function 5.1: Swap values at indeces in a string
// inputs:  1 str, 2 int
// outputs: none
// runtime: O(1)
void Solution::SwapCharByIdx(std::string &str, unsigned int idx1, unsigned int idx2) {
  if(str.length() == 0 || idx1 > str.length() || idx2 > str.length()) {
    str = "ERROR";
    return; 
  }
  std::swap(str[idx1], str[idx2]); 
}

// Function 5.2: reverse a string
// inputs:  1 str
// outputs: none
// runtime: O(n/2) => O(n)
void Solution::ReverseStr(std::string &str) {
  if(str.length() == 0) {
    str = "ERROR";
    return; 
  }
  int middle = (int) (str.length() / 2); 
  for(int i = 0; i < middle; i++) {
    std::swap(str[i], str[str.length() - 1 - i]); 
  }
}

// Function 5.3: Lowercase a string
// inputs:  1 str
// outputs: none
// runtime: O(n)
void Solution::ToLower(std::string &str) {
  if(str.length() == 0) {
    str = "ERROR";
    return; 
  }

  char temp; 
  for(int i = 0; i < str.length(); i++) {
    temp = str[i]; 
    if(temp >= 'A' && temp <= 'Z'){
      str[i] += 32; 
    }
  }
}

////////////////////////////////////////////
// Question 6
///////////////////////////////////////////

// Function 6.1: basic palindrome
// inputs:  1 str
// outputs: bool if its a palindrome
// runtime: O(str.len())
bool Solution::FindPalindrome(str::string &str) {
  int middle = (int) (str.length() / 2); 
  for(int i = 0; i < middle; i++) {
    if(str[i] != str[str.length() - 1 - i]) {
      return false;
    }
  }
  return true; 
}

bool Solution::FindApproxPalindrome(std::string &str) {

}