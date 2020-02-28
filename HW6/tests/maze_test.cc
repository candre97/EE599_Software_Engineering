#include "src/lib/Maze.h"
#include "gtest/gtest.h"
#include <vector>

TEST(MazeSolver, Ex1) {
  std::vector<std::vector<int>> in1 = {
    {1, 1, 0, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1,}
  };
  Maze* m = new Maze(in1); 
  auto s = std::make_pair(0,0); 
  auto f = std::make_pair(4,4);
  EXPECT_TRUE(m->SearchMaze(s, f));
}
TEST(MazeSolver, Ex2) {
  std::vector<std::vector<int>> in2 = {
      {1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1},
      {0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0},
      {1, 1, 1, 1, 1}
  };
  Maze* m2 = new Maze(in2); 
  auto s2 = std::make_pair(1,2); 
  auto f2 = std::make_pair(4,4);
  EXPECT_FALSE(m2->SearchMaze(s2, f2));  
}
TEST(MazeSolver, InvalidStart) {
  std::vector<std::vector<int>> in1 = {
    {1, 1, 0, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1,}
  };
  Maze* m = new Maze(in1); 
  auto s = std::make_pair(0,4); 
  auto f = std::make_pair(4,4);
  EXPECT_FALSE(m->SearchMaze(s, f));
}
TEST(MazeSolver, LinearMaze) {
  std::vector<std::vector<int>> in1 = {
    {1, 1, 1, 1, 1},
  };
  Maze* m = new Maze(in1); 
  auto s = std::make_pair(0,0); 
  auto f = std::make_pair(0,4);
  EXPECT_TRUE(m->SearchMaze(s, f));
}
TEST(MazeSolver, StartAtFinish) {
  std::vector<std::vector<int>> in1 = {
    {1, 1, 0, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1,}
  };
  Maze* m = new Maze(in1); 
  auto s = std::make_pair(1,4); 
  auto f = std::make_pair(1,4);
  EXPECT_TRUE(m->SearchMaze(s, f));
}
TEST(MazeSolver, SmallerMaze) {
  std::vector<std::vector<int>> in1 = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 1}
  };
  Maze* m = new Maze(in1); 
  auto s = std::make_pair(0,0); 
  auto f = std::make_pair(3,3);
  EXPECT_TRUE(m->SearchMaze(s, f));
}

