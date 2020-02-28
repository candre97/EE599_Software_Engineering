#include "Graph.h"

// Note: use vector of bool to store whether you've visited the node already
// runtime: O(N + E) = O(Nodes + Edges)
std::vector<int> Graph::NonRecDFS(int root) {
  std::vector<int> ret;
  std::stack<int> s; 
  std::vector<bool> visited(v_.size()); 

  for(int i = 0; i < visited.size(); i++) {
    visited[i] = false; 
  }

  // add root
  ret.push_back(root); 
  s.push(root); 
  visited[root] = true; 

  while(!s.empty()) {
    int t = s.top(); 
    s.pop(); 
    std::set<int> neighbors = v_[t]; 
    if(!visited[t]) {
      ret.push_back(t); 
      visited[t] = true;
    }
    
    for(std::set<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
      if(!visited[*it]) {
        s.push(*it); 
      }
    } 
  }
  return ret; 
}

// runtime: O(n log n)
// note optimized from the vector find function where 
// that was going to be runtime of O(n^2) 
std::vector<int> Graph::DFSAll() {
  auto it = v_.begin(); 
  std::vector<int> ret = NonRecDFS(it->first); 
  std::set<int> s(ret.begin(), ret.end()); 
  // iterator through map, check for missing keys in ret
  while(it != v_.end()) {
    if(s.find(it->first) == s.end()) {
      ret.push_back(it->first); 
    }
    it++;
  }
  return ret; 
}