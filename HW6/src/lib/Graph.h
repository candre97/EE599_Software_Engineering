#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <iostream>
#include <iterator> 
#include <algorithm>

struct Vertex {
  Vertex(int v, std::set<int> a) : vertex_number(v), adjacents(a) {}
  int vertex_number;
  std::set<int> adjacents;
};

class Graph {
  public:
    Graph(std::map<int, std::set<int>> &vertices) :
    v_(vertices) {}
    std::map<int, std::set<int>> v_; 

    // going to assume that vertices are index ordered when passed in
    // just as they are in the example
    std::vector<int> NonRecDFS(int root); 
    std::vector<int> DFSAll();
}; 


#endif

