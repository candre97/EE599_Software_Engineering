#include "src/lib/MaxHeap.h"
#include "gtest/gtest.h"

///////////////////////////////////////
// MaxHeap.h tests!!
///////////////////////////////////////

// MaxHeap(); // default constructor
TEST(Constructor, BasicTest) {
  MaxHeap* m = new MaxHeap();
  std::vector<int> actual = m->GetData(); 
  std::vector<int> expected = {}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}

// MaxHeap(std::vector<int>& v); // for testing purposes
TEST(ParameterizedConstructor, BasicTest) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  std::vector<int> actual = m->GetData(); 
  std::vector<int> expected = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5}; 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}

// int GetParentIndex(int i); // *GT*
TEST(GetParentIndex, BasicTest) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(0, m->GetParentIndex(1));
  EXPECT_EQ(3, m->GetParentIndex(7));
  EXPECT_EQ(5, m->GetParentIndex(12));
}
TEST(GetParentIndex, ParentOfRoot) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(-1, m->GetParentIndex(0));
}
TEST(GetParentIndex, OutOfRange) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(-1, m->GetParentIndex(-2));
  EXPECT_EQ(-1, m->GetParentIndex(20));
}

// int GetLeftIndex(int i); // *GT*
TEST(GetLeftIndex, BasicTest) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(1, m->GetLeftIndex(0));
  EXPECT_EQ(13, m->GetLeftIndex(6));
  EXPECT_EQ(5, m->GetLeftIndex(2));
}
TEST(GetLeftIndex, LeftOfLeaf) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(-1, m->GetLeftIndex(7));
  EXPECT_EQ(-1, m->GetLeftIndex(8));
  EXPECT_EQ(-1, m->GetLeftIndex(12));
}
TEST(GetLeftIndex, OutOfRange) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(-1, m->GetLeftIndex(-1));
  EXPECT_EQ(-1, m->GetLeftIndex(34));
  EXPECT_EQ(-1, m->GetLeftIndex(22));
}

// int GetRightIndex(int i); // *GT*
TEST(GetRightIndex, BasicTest) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(2, m->GetRightIndex(0));
  EXPECT_EQ(12, m->GetRightIndex(5));
  EXPECT_EQ(6, m->GetRightIndex(2));
}
TEST(GetRightIndex, RightOfLeaf) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(-1, m->GetRightIndex(7));
  EXPECT_EQ(-1, m->GetRightIndex(8));
  EXPECT_EQ(-1, m->GetRightIndex(12));
}
TEST(GetRightIndex, OutOfRange) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(-1, m->GetRightIndex(-1));
  EXPECT_EQ(-1, m->GetRightIndex(34));
  EXPECT_EQ(-1, m->GetRightIndex(22));
}

// int GetLargestChildIndex(int i); // *GT*
TEST(GetLargestChildIndex, BasicTest) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(1, m->GetLargestChildIndex(0));
  EXPECT_EQ(11, m->GetLargestChildIndex(5));
  EXPECT_EQ(5, m->GetLargestChildIndex(2));
}
TEST(GetLargestChildIndex, OutOfRange) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(-1, m->GetLargestChildIndex(-10));
  EXPECT_EQ(-1, m->GetLargestChildIndex(11));
  EXPECT_EQ(-1, m->GetLargestChildIndex(9));
}

// int top(); // GT
TEST(Top, BasicTest) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  EXPECT_EQ(m->top(), 103); 
}
TEST(Top, EmptyHeap) {
  MaxHeap* m = new MaxHeap;
  EXPECT_EQ(m->top(), INT_MIN); 
}

// void push(int v); // GT
TEST(Push, ThoroughTest) {
  MaxHeap* m = new MaxHeap;
  m->push(100);
  EXPECT_EQ(m->top(), 100);
  m->push(90);  
  EXPECT_EQ(m->top(), 100);
  m->push(80);  
  EXPECT_EQ(m->GetRight(0), 80);
  m->push(800);  
  EXPECT_EQ(m->top(), 800);
}
TEST(Push, HardTest) {
  std::vector<int> in = {5,3,19,20,41,32,11,23,43,54,88,90,89,96,103};
  MaxHeap* m = new MaxHeap;
  for(int i = 0; i < in.size(); i ++) {
    m->push(in[i]);
  }
  std::vector<int> expected = {103,54,96,23,43,88,90,3,20,19,41,5,32,11,89}; 
  std::vector<int> actual  = m->GetData(); 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}

// void pop(); // GT
TEST(Pop, BasicTest) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  m->pop(); 
  std::vector<int> expected = {96, 90, 89, 23, 88, 54, 43, 5, 11, 32, 41, 20, 19, 3};
  std::vector<int> actual  = m->GetData(); 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}
TEST(Pop, MultiPop) {
  std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
  MaxHeap* m = new MaxHeap(in);
  m->pop(); 
  m->pop(); 
  m->pop();
  std::vector<int> expected = {89, 88, 54, 23, 41, 20, 43, 5, 11, 32, 3, 19};
  std::vector<int> actual  = m->GetData(); 
  EXPECT_EQ(actual.size(), expected.size());
  for(int i = 0; i < actual.size(); i++) {
      EXPECT_EQ(expected[i],actual[i]); 
  }
}