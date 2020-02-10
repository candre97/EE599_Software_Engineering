#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

Solution solution;

TEST(HelloWorldShould, ReturnHelloWorld) {
  std::string actual = solution.PrintHelloWorld();
  std::string expected = "**** Hello World ****";
  EXPECT_EQ(expected, actual);
}

//////////////////////////////////////////////////
// Tests for Question 2
//////////////////////////////////////////////////
TEST(VectSum, BasicTest) {
  std::vector<int> inputs = {3,7,11,15}; 
  std::vector<int> actual = solution.VectSum(inputs, 10);
  std::vector<int> expected = {0,1}; 
  EXPECT_EQ(expected.size(), actual.size());

  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]); 
  }
}

TEST(VectSum, NoResult) {
  std::vector<int> inputs = {3,7,11,15}; 
  std::vector<int> actual = solution.VectSum(inputs, 180);
  std::vector<int> expected = {}; 
  EXPECT_EQ(expected.size(), actual.size());

  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]); 
  }
}

TEST(VectSum, TwoSameIndex) {
  std::vector<int> inputs = {3,7,11,15}; 
  std::vector<int> actual = solution.VectSum(inputs, 6);
  std::vector<int> expected = {0,0}; 
  EXPECT_EQ(expected.size(), actual.size());

  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]); 
  }
}

//////////////////////////////////////////////////
// Tests for Question 4
//////////////////////////////////////////////////

// straight from the handout
TEST(CheckBrackets, BasicTest) {
  std::string ex1,ex2,ex3,ex4,ex5,ex6; 
  ex1 = "(a+b)";
  ex2 = "(a+b)[c*d]{5g+h}"; 
  ex3 = "(a+b]";
  ex4 = "{2k+[5j]}";
  ex5 = "{2k++[5--*j]}"; 
  EXPECT_EQ(solution.CheckBrackets(ex1), true);
  EXPECT_EQ(solution.CheckBrackets(ex2), true);
  EXPECT_EQ(solution.CheckBrackets(ex3), false);
  EXPECT_EQ(solution.CheckBrackets(ex4), true);
  EXPECT_EQ(solution.CheckBrackets(ex5), true);
}

TEST(CheckBrackets, EqualNumButWrong) {
  std::string ex1; 
  ex1 = ")a+b(";
  EXPECT_EQ(solution.CheckBrackets(ex1), false);
}

TEST(CheckBrackets, MoreComplex) {
  std::string ex1; 
  ex1 = "(()a+b())";
  EXPECT_EQ(solution.CheckBrackets(ex1), true);
}

