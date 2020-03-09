#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

// QUESTION 3 tests!!
// test given in hw handout
TEST(BFSDistances, StartAt1) {
  std::map<int, std::set<int>> vertices {
    {1, {2, 3}},
    {2, {1, 3, 4, 5}},
    {3, {1, 2, 4}},
    {4, {2, 3, 4}}
  };
  Graph g(vertices);
  std::map<int,int> actual = g.BFSDistances(1); 
  std::map<int,int> expected = {
    {1, 0},
    {2, 1},
    {3, 1},
    {4, 2},
    {5, 2}
  };
  ASSERT_EQ(actual.size(),expected.size()); 
  for(int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual[i+1], expected[i+1]); 
  }
}
TEST(BFSDistances, StartAt2) {
  std::map<int, std::set<int>> vertices {
    {1, {2, 3}},
    {2, {1, 3, 4, 5}},
    {3, {1, 2, 4}},
    {4, {2, 3, 4}}
  };
  Graph g(vertices);
  std::map<int,int> actual = g.BFSDistances(2); 
  std::map<int,int> expected = {
    {1, 1},
    {2, 0},
    {3, 1},
    {4, 1},
    {5, 1}
  };
  ASSERT_EQ(actual.size(),expected.size()); 
  for(int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual[i+1], expected[i+1]); 
  }
}
TEST(BFSDistances, StartAt4) {
  std::map<int, std::set<int>> vertices {
    {1, {2, 3}},
    {2, {1, 3, 4, 5}},
    {3, {1, 2, 4}},
    {4, {2, 3, 4}}
  };
  Graph g(vertices);
  std::map<int,int> actual = g.BFSDistances(4); 
  std::map<int,int> expected = {
    {1, 2},
    {2, 1},
    {3, 1},
    {4, 0},
    {5, 2}
  };
  ASSERT_EQ(actual.size(),expected.size()); 
  for(int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual[i+1], expected[i+1]); 
  }
}
// made a bigger more complicated graph
TEST(BFSDistances, BiggerGraphStartAt1) {
  std::map<int, std::set<int>> vertices {
    {1, {2, 3}},
    {2, {1,4,11}},
    {3, {1, 11}},
    {4, {2, 5}},
    {5, {4,6}},
    {6, {5,7,9}},
    {7, {6,8}},
    {8, {7,9}},
    {9, {6,8,10}},
    {10, {9,11}},
    {11, {2,3,10}}
  };
  Graph g(vertices);
  std::map<int,int> actual = g.BFSDistances(1); 
  std::map<int,int> expected = {
    {1, 0},
    {2, 1},
    {3, 1},
    {4, 2},
    {5, 3},
    {6, 4},
    {7, 5},
    {8, 5},
    {9, 4},
    {10, 3},
    {11, 2}
  };
  ASSERT_EQ(actual.size(),expected.size()); 
  for(int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual[i+1], expected[i+1]); 
  }
}
TEST(BFSDistances, BiggerGraphStartAt10) {
  std::map<int, std::set<int>> vertices {
    {1, {2, 3}},
    {2, {1,4,11}},
    {3, {1, 11}},
    {4, {2, 5}},
    {5, {4,6}},
    {6, {5,7,9}},
    {7, {6,8}},
    {8, {7,9}},
    {9, {6,8,10}},
    {10, {9,11}},
    {11, {2,3,10}}
  };
  Graph g(vertices);
  std::map<int,int> actual = g.BFSDistances(10); 
  std::map<int,int> expected = {
    {1, 3},
    {2, 2},
    {3, 2},
    {4, 3},
    {5, 3},
    {6, 2},
    {7, 3},
    {8, 2},
    {9, 1},
    {10, 0},
    {11, 1}
  };
  ASSERT_EQ(actual.size(),expected.size()); 
  for(int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual[i+1], expected[i+1]); 
  }
}

// Tests for getting the path
TEST(BFSPath, BiggerGraphStartAt1) {
  std::map<int, std::set<int>> vertices {
    {1, {2, 3}},
    {2, {1,4,11}},
    {3, {1, 11}},
    {4, {2, 5}},
    {5, {4,6}},
    {6, {5,7,9}},
    {7, {6,8}},
    {8, {7,9}},
    {9, {6,8,10}},
    {10, {9,11}},
    {11, {2,3,10}}
  };
  Graph g(vertices);
  std::map<int, std::vector<int>> actual = g.BFSPath(1);  
  std::map<int, std::vector<int>> expected = {
    {1, {1}},
    {2, {1,2}},
    {3, {1,3}},
    {4, {1,2,4}},
    {5, {1,2,4,5}},
    {6, {1,2,4,5,6}},
    {7, {1,2,4,5,6,7}},
    {8, {1,2,11,10,9,8}},
    {9, {1,2,11,10,9}},
    {10, {1,2,11,10}},
    {11, {1,2,11}}
  };
  ASSERT_EQ(actual.size(),expected.size()); 
  for(int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual[i+1], expected[i+1]); 
  }
}
TEST(BFSPath, BiggerGraphStartAt10) {
  std::map<int, std::set<int>> vertices {
    {1, {2, 3}},
    {2, {1,4,11}},
    {3, {1, 11}},
    {4, {2, 5}},
    {5, {4,6}},
    {6, {5,7,9}},
    {7, {6,8}},
    {8, {7,9}},
    {9, {6,8,10}},
    {10, {9,11}},
    {11, {2,3,10}}
  };
  Graph g(vertices);
  std::map<int, std::vector<int>> actual = g.BFSPath(10);  
  std::map<int, std::vector<int>> expected = {
    {1, {10,11,2,1}},
    {2, {10,11,2}},
    {3, {10,11,3}},
    {4, {10,11,2,4}},
    {5, {10,9,6,5}},
    {6, {10,9,6}},
    {7, {10,9,6,7}},
    {8, {10,9,8}},
    {9, {10,9}},
    {10, {10}},
    {11, {10,11}}
  };
  ASSERT_EQ(actual.size(),expected.size()); 
  for(int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual[i+1], expected[i+1]); 
  }
}
// Tests for getting the path
TEST(BFSPath, SmallGraphStartAt1) {
  std::map<int, std::set<int>> vertices {
    {1, {2, 3}},
    {2, {1, 3, 4, 5}},
    {3, {1, 2, 4}},
    {4, {2, 3, 4}}
  };
  Graph g(vertices);
  std::map<int, std::vector<int>> actual = g.BFSPath(1);  
  std::map<int, std::vector<int>> expected = {
    {1, {1}},
    {2, {1,2}},
    {3, {1,3}},
    {4, {1,2,4}},
    {5, {1,2,5}}
  };
  ASSERT_EQ(actual.size(),expected.size()); 
  for(int i = 0; i < expected.size(); i++) {
    EXPECT_EQ(actual[i+1], expected[i+1]); 
  }
}

/////////////////////////////////////////
// Question 4
/////////////////////////////////////////
// Tests for GetRoots
TEST(GetRoots, GivenGraph) {
  std::map<int, std::set<int>> vertices {
    {0, {}}, 
    {1, {0}},
    {2, {1}},
    {3, {1}},
    {4, {}},
    {5, {2,4}},
    {6, {3,4}},
    {7, {5,6}}
  };
  Graph g(vertices);
  std::set<int> actual = g.GetRoots();  
  std::set<int> expected = {7}; 
  ASSERT_EQ(actual.size(),expected.size()); 
  auto a = actual.begin(); 
  auto e = expected.begin(); 
  while(a != actual.end()) {
    EXPECT_EQ(*a, *e); 
    a++;
    e++;
  } 
}
TEST(GetRoots, TwoRoots) {
  std::map<int, std::set<int>> vertices {
    {0, {}}, 
    {1, {0}},
    {2, {1}},
    {3, {1}},
    {4, {}},
    {5, {2,4}},
    {6, {3,4}},
    {7, {5,6}},
    {8, {5}}
  };
  Graph g(vertices);
  std::set<int> actual = g.GetRoots();  
  std::set<int> expected = {7,8}; 
  ASSERT_EQ(actual.size(),expected.size()); 
  auto a = actual.begin(); 
  auto e = expected.begin(); 
  while(a != actual.end()) {
    EXPECT_EQ(*a, *e); 
    a++;
    e++;
  } 
}
// Tests for TopoSort
TEST(TopoSort, GivenGraph) {
  std::map<int, std::set<int>> vertices {
    {0, {}}, 
    {1, {0}},
    {2, {1}},
    {3, {1}},
    {4, {}},
    {5, {2,4}},
    {6, {3,4}},
    {7, {5,6}}
  };
  Graph g(vertices);
  std::vector<int> actual = g.TopoSort();  
  std::vector<int> expected = {7, 5, 6, 2, 3, 4, 1, 0}; 
  ASSERT_EQ(actual.size(),expected.size()); 
  auto a = actual.begin(); 
  auto e = expected.begin(); 
  while(a != actual.end()) {
    EXPECT_EQ(*a, *e); 
    a++;
    e++;
  } 
}
TEST(TopoSort, TwoRoots) {
  std::map<int, std::set<int>> vertices {
    {0, {}}, 
    {1, {0}},
    {2, {1}},
    {3, {1}},
    {4, {}},
    {5, {2,4}},
    {6, {3,4}},
    {7, {5,6}},
    {8, {5}}
  };
  Graph g(vertices);
  std::vector<int> actual = g.TopoSort();  
  std::vector<int> expected = {7, 8, 6, 5, 3, 2, 4, 1, 0}; 
  ASSERT_EQ(actual.size(),expected.size()); 
  auto a = actual.begin(); 
  auto e = expected.begin(); 
  while(a != actual.end()) {
    EXPECT_EQ(*a, *e); 
    a++;
    e++;
  } 
}

