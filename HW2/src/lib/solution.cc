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

// Function 1:
// inputs: 2 ints
// outputs: 1 int
// runtime: O(1)
int Solution::Add(int a, int b) {
  return (int) a + b; 
}

// Function 2:
// inputs: 2 strings
// outputs: 1 string
// runtime: O(len(a) + len(b)) = O(n)
std::string Solution::Add(std::string &a, std::string &b) {
  return a + b; 
}

// Function 3:
// inputs: 1 string, 1 int
// outputs: 1 string
// runtime: O(len(a) + len(str(b)) + TODO: find runtime of to_string()) = O(n)
std::string Solution::Add(std::string &a, int b) {
  return a + std::to_string(b); 
}

// Function 4:
// inputs:  1 int, 1 string
// outputs: 1 string
// runtime: O(len(b) + len(str(a)) + TODO: find runtime of to_string()) = O(n)
std::string Solution::Add(int a, std::string &b) {
  return std::to_string(a) + b; 
}


