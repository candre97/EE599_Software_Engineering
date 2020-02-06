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
  ASSERT_EQ(expected.size(), actual.size());

  for(int i = 0; i < actual.size(); i++) {
    ASSERT_EQ(expected[i], actual[i]); 
  }
}

TEST(VectSum, NoResult) {
  std::vector<int> inputs = {3,7,11,15}; 
  std::vector<int> actual = solution.VectSum(inputs, 180);
  std::vector<int> expected = {}; 
  ASSERT_EQ(expected.size(), actual.size());

  for(int i = 0; i < actual.size(); i++) {
    ASSERT_EQ(expected[i], actual[i]); 
  }
}

TEST(VectSum, TwoSameIndex) {
  std::vector<int> inputs = {3,7,11,15}; 
  std::vector<int> actual = solution.VectSum(inputs, 6);
  std::vector<int> expected = {0,0}; 
  ASSERT_EQ(expected.size(), actual.size());

  for(int i = 0; i < actual.size(); i++) {
    ASSERT_EQ(expected[i], actual[i]); 
  }
}
