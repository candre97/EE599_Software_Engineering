#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

Solution solution;
/*
TEST(HelloWorldShould, ReturnHelloWorld) {
  std::string actual = solution.PrintHelloWorld();
  std::string expected = "**** Hello World ****";
  EXPECT_EQ(expected, actual);
}
*/

TEST(AddTests, BasicTwoInts) {
  Solution solution;
  int a = 4;
  int b = 10;
  int expected = 14;
  int actual = solution.Add(a,b); 
  EXPECT_EQ(expected, actual);
}

TEST(AddTests, BasicTwoStr) {
  Solution solution;
  std::string a = "**** Hello World ****";
  std::string b = "!!"; 
  std::string actual = solution.Add(a,b);
  std::string expected = "**** Hello World ****!!";
  EXPECT_EQ(expected, actual);
}

TEST(AddTests, BasicIntStr) {
  Solution solution;
  int a = 49;
  std::string b = "ers"; 
  std::string actual = solution.Add(a,b);
  std::string expected = "49ers";
  EXPECT_EQ(expected, actual);
}

TEST(AddTests, BasicStrInt) {
  Solution solution;
  int b = 22;
  std::string a = "I am "; 
  std::string actual = solution.Add(a,b);
  std::string expected = "I am 22";
  EXPECT_EQ(expected, actual);
}

////////////////////////////////////
// More complicated Tests
////////////////////////////////////
TEST(AddTests, NegativeTwoInts) {
  Solution solution;
  int a = -4;
  int b = -10;
  int expected = -14;
  int actual = solution.Add(a,b); 
  EXPECT_EQ(expected, actual);
}

TEST(AddTests, EmptyTwoStr) {
  Solution solution;
  std::string a = "";
  std::string b = ""; 
  std::string actual = solution.Add(a,b);
  std::string expected = "";
  EXPECT_EQ(expected, actual);
}

TEST(AddTests, NegIntEmptyStr) {
  Solution solution;
  int a = -49;
  std::string b = ""; 
  std::string actual = solution.Add(a,b);
  std::string expected = "-49";
  EXPECT_EQ(expected, actual);
}

TEST(AddTests, EmptyStrNegInt) {
  Solution solution;
  int b = -22;
  std::string a = ""; 
  std::string actual = solution.Add(a,b);
  std::string expected = "-22";
  EXPECT_EQ(expected, actual);
}

