#include "src/lib/Graph.h"
#include "gtest/gtest.h"
#include <vector>

// test given in HW handout, tests a good amount of corner cases
TEST(DFS, GivenTest) {
  std::map<int, std::set<int>> vertices{
    {0, {1, 2, 5}},
    {1, {0, 2, 3}},
    {2, {0, 1, 3}},
    {3, {2, 4, 6}},
    {4, {3}},
    {5, {0}},
    {6, {3}}
  };
  Graph g(vertices);
  std::vector<int> actual = g.NonRecDFS(0); 
  std::vector<int> expected = {0, 5, 2, 3, 6, 4, 1};
  ASSERT_EQ(actual.size(), expected.size()); 
  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(actual[i], expected[i]); 
  }
}

TEST(DFS, DoesNotVisitAll) {
  std::map<int, std::set<int>> vertices{
    {0, {1}},
    {1, {2, 3}},
    {2, {0}},
    {3, {4, 6}},
    {4, {}},
    {5, {6}},
    {6, {}}
  };
  Graph g(vertices);
  std::vector<int> actual = g.NonRecDFS(0); 
  std::vector<int> expected = {0, 1, 3, 6, 4, 2};
  ASSERT_EQ(actual.size(), expected.size()); 
  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(actual[i], expected[i]); 
  }
}


// test given in HW handout, tests a good amount of corner cases
TEST(DFSAll, GivenTest) {
  // Print Hellow world!
  std::map<int, std::set<int>> vertices{
    {0, {1}},
    {1, {2, 3}},
    {2, {0}},
    {3, {4, 6}},
    {4, {}},
    {5, {6}},
    {6, {}}
  };
  Graph g(vertices);
  std::vector<int> actual = g.DFSAll(); 
  std::vector<int> expected = {0, 1, 3, 6, 4, 2, 5};
  ASSERT_EQ(actual.size(), expected.size()); 
  for(int i = 0; i < actual.size(); i++) {
    EXPECT_EQ(actual[i], expected[i]); 
  }
}
