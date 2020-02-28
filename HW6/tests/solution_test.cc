#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

// test given in homework handout
TEST(RearrangeVect, LastIdx) {
  Solution sol; 
  std::vector<int> actual = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6}; 
  int i=9; 
  sol.RearrangeVect(actual,i); 
  std::vector<int> expected = {5, 2, 3, 6, 9, 7, 11, 12, 14, 10};
  ASSERT_EQ(actual.size(), expected.size()); 
  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(actual[i], expected[i]); 
  }
}
TEST(RearrangeVect, MiddleIdx) {
  Solution sol; 
  std::vector<int> actual = {1,2,3,66,33,12,54,102,1002}; 
  int i=4; 
  sol.RearrangeVect(actual,i);  
  std::vector<int> expected = {1, 2, 3, 12, 33, 66, 54, 102, 1002};
  ASSERT_EQ(actual.size(), expected.size()); 
  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(actual[i], expected[i]); 
  }
}
TEST(RearrangeVect, FirstIdx) {
  Solution sol; 
  std::vector<int> actual = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6}; 
  int i=0; 
  sol.RearrangeVect(actual,i); 
  std::vector<int> expected = {7, 5, 2, 3, 6, 9, 11, 12, 14, 10};
  ASSERT_EQ(actual.size(), expected.size()); 
  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(actual[i], expected[i]); 
  }
}
TEST(RearrangeVect, OutOfRange) {
  Solution sol; 
  std::vector<int> actual = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6}; 
  int i=10; 
  sol.RearrangeVect(actual,i); 
  std::vector<int> expected = {};
  ASSERT_EQ(actual.size(), expected.size()); 
  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(actual[i], expected[i]); 
  }
}


