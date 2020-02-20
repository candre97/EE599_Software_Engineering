#include "src/lib/BST.h"
#include "gtest/gtest.h"
#include <vector>

// Question 1
TEST(MaxDepth, BasicTest) {
  BST* b = new BST();
  b->push(8); 
  b->push(3); 
  b->push(10); 
  b->push(5); 
  b->push(2); 
  b->push(14); 
  b->push(4); 
  b->push(7); 
  b->push(12); 
  int depth = b->MaxDepthRec(b->GetRoot());
  EXPECT_EQ(depth, 4); 
}
TEST(MaxDepth, LineBST) {
  BST* b = new BST();
  b->push(8); 
  b->push(9); 
  b->push(10); 
  b->push(11); 
  b->push(12); 
  b->push(13); 
  b->push(14); 
  b->push(15); 
  b->push(16); 
  int depth = b->MaxDepthRec(b->GetRoot());
  EXPECT_EQ(depth, 9); 
}
TEST(MaxDepth, EmptyBST) {
  BST* b = new BST();
  int depth = b->MaxDepthRec(b->GetRoot());
  EXPECT_EQ(depth, 0); 
}

// Question 2
TEST(InOrderRec, BasicTest) {
  BST* b = new BST();
  b->push(8); 
  b->push(3); 
  b->push(10); 
  b->push(5); 
  b->push(2); 
  b->push(14); 
  b->push(4); 
  b->push(7); 
  b->push(12); 
  std::vector<int> actual = b->InOrderRec(b->GetRoot()); 
  std::vector<int> expected = {2, 3, 4, 5, 7, 8, 10, 12, 14}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(InOrderRec, LineBST) {
  BST* b = new BST();
  b->push(8); 
  b->push(9); 
  b->push(10); 
  b->push(11); 
  b->push(12); 
  b->push(13); 
  b->push(14); 
  b->push(15); 
  b->push(16);
  std::vector<int> actual = b->InOrderRec(b->GetRoot()); 
  std::vector<int> expected = {8, 9, 10, 11, 12, 13, 14, 15, 16}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(InOrderRec, EmptyBST) {
  BST* b = new BST();
  std::vector<int> actual = b->InOrderRec(b->GetRoot()); 
  std::vector<int> expected = {}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}

// Tests for Question 2 part 2 -- non recursive
TEST(InOrderNonRec, BasicTest) {
  BST* b = new BST();
  b->push(8); 
  b->push(3); 
  b->push(10); 
  b->push(5); 
  b->push(2); 
  b->push(14); 
  b->push(4); 
  b->push(7); 
  b->push(12); 
  std::vector<int> actual = b->InOrderNonRec(); 
  std::vector<int> expected = {2, 3, 4, 5, 7, 8, 10, 12, 14}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(InOrderNonRec, LineBST) {
  BST* b = new BST();
  b->push(8); 
  b->push(9); 
  b->push(10); 
  b->push(11); 
  b->push(12); 
  b->push(13); 
  b->push(14); 
  b->push(15); 
  b->push(16);
  std::vector<int> actual = b->InOrderNonRec(); 
  std::vector<int> expected = {8, 9, 10, 11, 12, 13, 14, 15, 16}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(InOrderNonRec, EmptyBST) {
  BST* b = new BST();
  std::vector<int> actual = b->InOrderNonRec(); 
  std::vector<int> expected = {}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
