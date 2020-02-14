#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

///////////////////////////////////////
// Question 1
///////////////////////////////////////

// KeepEvens Tests
TEST(KeepEvens, BasicTest) {
  Solution solution;
  std::vector<int> in = {1,2,3,4,5,6,7,8,9};
  std::vector<int> actual = solution.KeepEvens(in); 
  std::vector<int> expected = {2,4,6,8};  
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(KeepEvens, AllOdds) {
  Solution solution;
  std::vector<int> in = {1,3,5,7,9};
  std::vector<int> actual = solution.KeepEvens(in); 
  std::vector<int> expected = {};  
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(KeepEvens, AllEvens) {
  Solution solution;
  std::vector<int> in = {2,4,6,8,10,20};
  std::vector<int> actual = solution.KeepEvens(in); 
  std::vector<int> expected = {2,4,6,8,10,20};  
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}

// SquareNums Tests
TEST(SquareNums, BasicTest) {
  Solution solution;
  std::vector<int> in = {2,4,6,8,10,20};
  std::vector<int> actual = solution.SquareNums(in); 
  std::vector<int> expected = {4,16,36,64,100,400};  
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}

TEST(SquareNums, NegativeNumbers) {
  Solution solution;
  std::vector<int> in = {-2,-4,-6,-8,-10,-20};
  std::vector<int> actual = solution.SquareNums(in); 
  std::vector<int> expected = {4,16,36,64,100,400};  
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}

// SumVect
TEST(SumVect, BasicTest) {
  Solution solution;
  std::vector<int> in = {2,4,6,8,10,20};
  int actual = solution.SumVect(in); 
  int expected = 50;  
  EXPECT_EQ(actual, expected);
}
TEST(SumVect, NegativeNumbers) {
  Solution solution;
  std::vector<int> in = {-2,-4,-6,-8,-10,-20};
  int actual = solution.SumVect(in); 
  int expected = -50;  
  EXPECT_EQ(actual, expected);
}
TEST(SumVect, EmptyVect) {
  Solution solution;
  std::vector<int> in = {};
  int actual = solution.SumVect(in); 
  int expected = 0;  
  EXPECT_EQ(actual, expected);
}

