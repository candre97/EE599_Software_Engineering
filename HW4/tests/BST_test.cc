#include "src/lib/BST.h"
#include "gtest/gtest.h"

///////////////////////////////////////
// BST.h tests!!
// Tests Required: push, find, erase
///////////////////////////////////////

TEST(BSTConstructor, BasicTest) {
  BST* b = new BST();
  std::vector<int> actual = b->BFS(b->GetRoot()); 
  std::vector<int> expected = {}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}

//////////////////////////////////
// Tests for Push
//////////////////////////////////
TEST(BSTPush, BasicTest) {
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
  std::vector<int> actual = b->BFS(b->GetRoot()); 
  std::vector<int> expected = {8, 3, 10, 2, 5, 14, 4, 7, 12}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(BSTPush, DuplicatePush) {
  BST* b = new BST();
  b->push(8); 
  b->push(8); 
  b->push(8); 
  b->push(8); 
  std::vector<int> actual = b->BFS(b->GetRoot()); 
  std::vector<int> expected = {8}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(BSTPush, HardTest) {
  BST* b = new BST();
  b->push(8);
  b->push(3);
  b->push(100);
  b->push(50);
  b->push(-2);
  b->push(14);
  b->push(40);
  b->push(72);
  b->push(12);
  std::vector<int> actual = b->BFS(b->GetRoot()); 
  std::vector<int> expected = {8, 3, 100, -2, 50, 14, 72, 12, 40}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}

//////////////////////////////////
// Tests for Find
//////////////////////////////////
TEST(BSTFind, BasicTest) {
  BST* b = new BST;
  b->push(8); 
  b->push(3); 
  b->push(10); 
  b->push(5); 
  b->push(2); 
  b->push(14); 
  b->push(4); 
  b->push(7); 
  b->push(12); 
  EXPECT_EQ(b->find(102), false);
  EXPECT_EQ(b->find(8), true);
  EXPECT_EQ(b->find(10), true);
  EXPECT_EQ(b->find(14), true);
}
TEST(BSTFind, EmptyTest) {
  BST* b = new BST;
  EXPECT_EQ(b->find(102), false);
  EXPECT_EQ(b->find(8), false);
  EXPECT_EQ(b->find(10), false);
  EXPECT_EQ(b->find(14), false);
}
//////////////////////////////////
// Tests for Erase
//////////////////////////////////
TEST(BSTErase, ThoroughTest) {
  BST* b = new BST;   
  std::vector<int> actual; 
  std::vector<int> expected; 
  bool ret = false; 
  b->push(8); 
  b->push(3); 
  b->push(10); 
  b->push(5); 
  b->push(2); 
  b->push(14); 
  b->push(4); 
  b->push(7); 
  b->push(12); 

  // erase node with 1 child
  ret = b->erase(10); 
  EXPECT_TRUE(ret); 
  actual.clear();
  expected.clear(); 
  actual = b->BFS(b->GetRoot()); 
  expected = {8, 3, 14, 2, 5, 12, 4, 7}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
  // erase node with 2 kids
  ret = b->erase(3); 
  EXPECT_TRUE(ret); 
  actual.clear();
  expected.clear(); 
  actual = b->BFS(b->GetRoot()); 
  expected = {8, 4, 14, 2, 5, 12, 7};
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
  // erase a leaf node
  ret = b->erase(7); 
  EXPECT_TRUE(ret); 
  actual.clear();
  expected.clear(); 
  actual = b->BFS(b->GetRoot()); 
  expected = {8, 4, 14, 2, 5, 12};
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(BSTErase, EraseRoot) {
  BST* b = new BST;   
  std::vector<int> actual; 
  std::vector<int> expected; 
  bool ret = false; 
  b->push(8); 
  // erase node with 1 child
  ret = b->erase(8); 
  EXPECT_TRUE(ret); 
  actual.clear();
  expected.clear(); 
  actual = b->BFS(b->GetRoot()); 
  expected = {}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(BSTErase, EmptyTest) {
  BST* b = new BST;   
  std::vector<int> actual; 
  std::vector<int> expected; 
  bool ret = false; 
  // erase node with 1 child
  ret = b->erase(8); 
  EXPECT_FALSE(ret); 
  actual.clear();
  expected.clear(); 
  actual = b->BFS(b->GetRoot()); 
  expected = {}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(BSTErase, NotInBST) {
  BST* b = new BST;   
  std::vector<int> actual; 
  std::vector<int> expected; 
  bool ret = false; 
  b->push(8); 
  b->push(3); 
  b->push(10); 
  b->push(5); 
  b->push(2); 
  b->push(14); 
  b->push(4); 
  b->push(7); 
  b->push(12); 

  ret = b->erase(88); 
  EXPECT_FALSE(ret); 
  actual.clear();
  expected.clear(); 
  actual = b->BFS(b->GetRoot()); 
  expected = {8, 3, 10, 2, 5, 14, 4, 7, 12};
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}