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

///////////////////////////////////
// Tests for Question 1
///////////////////////////////////

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

///////////////////////////////////
// Question 2 in main.cc
///////////////////////////////////

///////////////////////////////////
// Tests for Question 3
///////////////////////////////////

TEST(RemoveDups, BasicTest) {
  std::vector<int> v = {1,2,2,4,1,3,4}; 
  solution.RemoveDups(v); 
  std::vector<int> expected = {1,2,3,4};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(RemoveDups, AllDups) {
  std::vector<int> v = {1,1,1,1,1,1,1}; 
  solution.RemoveDups(v); 
  std::vector<int> expected = {1};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(RemoveDupsNoSet, BasicTestNoSet) {
  std::vector<int> v = {1,2,2,4,1,3,4}; 
  solution.RemoveDupsNoSet(v); 
  std::vector<int> expected = {2,1,3,4};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(RemoveDupsNoSet, AllDupsNoSet) {
  std::vector<int> v = {1,1,1,1,1,1}; 
  solution.RemoveDupsNoSet(v); 
  std::vector<int> expected = {1};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(ReverseOrder, BasicTest) {
  std::vector<int> v = {1,2,3,4,5}; 
  solution.ReverseOrder(v); 
  std::vector<int> expected = {5,4,3,2,1};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(ReverseOrder, OneElement) {
  std::vector<int> v = {1}; 
  solution.ReverseOrder(v); 
  std::vector<int> expected = {1};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(ReverseOrder, TwoElements) {
  std::vector<int> v = {1,3}; 
  solution.ReverseOrder(v); 
  std::vector<int> expected = {3,1};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(RemoveOdds, BasicTest) {
  std::vector<int> v = {1,1,2,3,8,5,6}; 
  solution.RemoveOdds(v); 
  std::vector<int> expected = {2,8,6};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(RemoveOdds, AllOdds) {
  std::vector<int> v = {1,1,1,3,3,3,5,5,5}; 
  solution.RemoveOdds(v); 
  std::vector<int> expected = {};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(ConcatVect, BasicTest) {
  std::vector<int> v1 = {1,2,3}; 
  std::vector<int> v2 = {3,5,6}; 
  std::vector<int> v = solution.ConcatVect(v1,v2); 
  std::vector<int> expected = {1,2,3,3,5,6};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(ConcatVect, EmptyV1) {
  std::vector<int> v1 = {1,2,3}; 
  std::vector<int> v2 = {}; 
  std::vector<int> v = solution.ConcatVect(v1,v2); 
  std::vector<int> expected = {1,2,3};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(UnionVect, BasicTest) {
  std::vector<int> v1 = {1,2,3,4,5}; 
  std::vector<int> v2 = {1,4,5,7,9,10}; 
  std::vector<int> v = solution.UnionVect(v1,v2); 
  std::vector<int> expected = {1,4,5};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

TEST(UnionVect, EmptyV1) {
  std::vector<int> v1 = {1,2,3}; 
  std::vector<int> v2 = {}; 
  std::vector<int> v = solution.UnionVect(v1,v2); 
  std::vector<int> expected = {};
  EXPECT_EQ(v.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], v[i]);
  }
}

//////////////////////////
// Tests for Question 4
//////////////////////////

TEST(Swap, BasicByRef) {
  int i1 = 1;
  int i1o = 1; 
  int i2 = 2;
  int i2o = 2; 
  solution.SwapByRef(i1, i2); 
  EXPECT_EQ(i1,i2o); 
  EXPECT_EQ(i2,i1o); 
}

TEST(Swap, BasicByPtrs) {
  int i1 = 1;
  int i1o = 1; 
  int i2 = 2;
  int i2o = 2; 
  solution.SwapPtrs(&i1, &i2); 
  EXPECT_EQ(i1,i2o); 
  EXPECT_EQ(i2,i1o); 
}

///////////////////////////////////
// Tests for Question 5
///////////////////////////////////

TEST(SwapByIdx, BasicTest) {
  std::string actual = "TEST"; 
  solution.SwapCharByIdx(actual, 0, 1); 
  std::string expected = "ETST"; 
  EXPECT_EQ(actual, expected); 
}

TEST(SwapByIdx, SameIndex) {
  std::string actual = "TEST"; 
  solution.SwapCharByIdx(actual, 0, 0); 
  std::string expected = "TEST"; 
  EXPECT_EQ(actual, expected); 
}

TEST(SwapByIdx, Error) {
  std::string actual = "TEST"; 
  solution.SwapCharByIdx(actual, 9, 1); 
  std::string expected = "ERROR"; 
  EXPECT_EQ(actual, expected); 
}

TEST(ReverseStr, BasicTest) {
  std::string actual = "EE599"; 
  solution.ReverseStr(actual); 
  std::string expected = "995EE"; 
  EXPECT_EQ(actual, expected); 
}

TEST(ReverseStr, EmptyTest) {
  std::string actual = ""; 
  solution.ReverseStr(actual); 
  std::string expected = "ERROR"; 
  EXPECT_EQ(actual, expected); 
}

TEST(ToLowerStr, BasicTest) {
  std::string actual = "EE599"; 
  solution.ToLower(actual); 
  std::string expected = "ee599"; 
  EXPECT_EQ(actual, expected); 
}

TEST(ToLowerStr, EmptyTest) {
  std::string actual = ""; 
  solution.ToLower(actual); 
  std::string expected = "ERROR"; 
  EXPECT_EQ(actual, expected); 
}

///////////////////////////////////
// Tests for Question 6
///////////////////////////////////

TEST(Palindrome, BasicTest) {
  std::string in1 = "racecar"; 
  bool actual = solution.FindPalindrome(in1); 
  bool expected = true; 
  EXPECT_EQ(actual, expected); 
}

TEST(PalindromeSentence, BasicTest) {
  std::string in1 = "A man, a plan, a canal, Panama!"; 
  bool actual = solution.FindApproxPalindrome(in1); 
  bool expected = true; 
  EXPECT_EQ(actual, expected); 
}

///////////////////////////////////
// Tests for Question 7
///////////////////////////////////


TEST(StringMapper, BasicTest) {
  std::string from = "add"; 
  std::string to = "egg"; 
  std::map<char,char> actual = solution.MapStrings(from,to); 
  std::map<char, char> expected = {{'a', 'e'}, {'d', 'g'}};
  EXPECT_EQ(actual.size(), expected.size()); 

  std::map<char,char>::const_iterator it_e = expected.begin(); 
  for(std::map<char,char>::const_iterator it_a = actual.begin();
   it_a != actual.end(); it_a++) {
    EXPECT_EQ(it_a->first, it_e->first); 
    EXPECT_EQ(it_a->second, it_e->second); 
    it_e++;
  }
}

TEST(StringMapper, AnotherTest) {
  std::string from = "aabbccdd"; 
  std::string to = "eeffgghh"; 
  std::map<char,char> actual = solution.MapStrings(from,to); 
  std::map<char, char> expected = {{'a', 'e'}, {'b', 'f'}, {'c','g'}, {'d','h'}};
  EXPECT_EQ(actual.size(), expected.size()); 
  
  std::map<char,char>::const_iterator it_e = expected.begin(); 
  for(std::map<char,char>::const_iterator it_a = actual.begin();
   it_a != actual.end(); it_a++) {
    EXPECT_EQ(it_a->first, it_e->first); 
    EXPECT_EQ(it_a->second, it_e->second); 
    it_e++;
  }
}

TEST(StringMapper, EmptyTest) {
  std::string from = "aabbccdd"; 
  std::string to = "eeffgghi"; 
  std::map<char,char> actual = solution.MapStrings(from,to); 
  std::map<char, char> expected;
  EXPECT_EQ(actual.size(), expected.size()); 

  std::map<char,char>::const_iterator it_e = expected.begin(); 
  for(std::map<char,char>::const_iterator it_a = actual.begin();
   it_a != actual.end(); it_a++) {
    EXPECT_EQ(it_a->first, it_e->first); 
    EXPECT_EQ(it_a->second, it_e->second); 
    it_e++;
  }
}

///////////////////////////////////
// Tests for Question 8
///////////////////////////////////

TEST(RearrangeVect, BasicTestOdd) {
  std::vector<int> v = {637, 231, 123, 43, 69, 43, 900, 10, 7, 21, 99, 0, 500}; 
  std::vector<int> actual = solution.RearrangeVector(v); 
  std::vector<int> expected = { 43, 43, 21,10, 7, 0, 69, 900, 637, 500, 231, 123, 99 };
  EXPECT_EQ(actual.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]);
  }
}

TEST(RearrangeVect, SmallVectOdd) {
  std::vector<int> v = {3,2,1}; 
  std::vector<int> actual = solution.RearrangeVector(v); 
  std::vector<int> expected = { 1,2,3};
  EXPECT_EQ(actual.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]);
  }
}

TEST(RearrangeVect, BasicTestEven) {
  std::vector<int> v = {637, 231, 123, 43, 43, 900, 10, 7, 21, 99, 0, 500}; 
  std::vector<int> actual = solution.RearrangeVector(v); 
  std::vector<int> expected = { 43, 43, 21,10, 7, 0, 900, 637, 500, 231, 123, 99 };
  EXPECT_EQ(actual.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]);
  }
}

TEST(RearrangeVect, SmallVectEven) {
  std::vector<int> v = {1,2,3,4}; 
  std::vector<int> actual = solution.RearrangeVector(v); 
  std::vector<int> expected = {2,1,4,3};
  EXPECT_EQ(actual.size(), expected.size()); 

  for(int i = 0; i < v.size(); i++) {
    EXPECT_EQ(expected[i], actual[i]);
  }
}

    