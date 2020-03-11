#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <iostream> 
#include <queue>
#include <map>
#include <set>
#include <algorithm> 

class Graph {
public:
  Graph(std::map<int, std::set<int>> &vertices) :
  v_(vertices) {}
  std::map<int, std::set<int>> v_;
  std::map<int,int> BFSDistances(int root);
  std::map<int, std::vector<int>> BFSPath(int root);
  std::set<int> GetRoots(); 
  std::vector<int> TopoSort();
  std::map<int,int> GetDegrees(); 
  
  // would rather pass in graph using constructor
  std::vector<bool> ContainedInPath(); 
  int FindMinInGraphButNotInVisited(const std::map<int, bool> visited);
  std::vector<std::vector<int>> ShortestPaths(int from, int to); 
};




#endif