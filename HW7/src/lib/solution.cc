#include "solution.h"


////////////////////////////////////////////////
// Question 3
////////////////////////////////////////////////

// Runtime: Same at BFS: O(V + E)
std::map<int,int> Graph::BFSDistances(int root) {
  std::map<int, int> marks;
  std::map<int, int> distances; 
  distances[root] = 0;
  std::queue<int> q;
  q.push(root);
  marks[root] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    int dist = distances[cur]; 
    for (auto &n : v_[cur]) {
      if (!marks[n]) {
        if(distances.count(n) == 0) {
          distances[n] = dist + 1;
        }
        else {
          distances[n] = std::min(distances[n], dist+1); 
        }
        marks[n] = 1;
        q.push(n);
      }
    }
  }
  return distances; 
}

// Runtime: Same at BFS: O(V + E)
std::map<int,std::vector<int>> Graph::BFSPath(int root) {
  std::map<int, int> marks;
  std::map<int, std::vector<int>> paths; 
  std::queue<int> q;
  q.push(root);
  marks[root] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    std::vector<int> p = paths[cur]; 
    for (auto &n : v_[cur]) {
      if (!marks[n]) {
        if(paths.count(n) == 0) {
          paths[n] = p; 
          paths[n].push_back(cur); 
        }
        else {
          if(paths[n].size() > p.size()) {
            paths[n] = p;
            paths[n].push_back(cur); 
          }
        }
        marks[n] = 1;
        q.push(n);
      }
    }
  }
  for(auto it = paths.begin(); it != paths.end(); it++) {
    paths[it->first].push_back(it->first); 
  }
  return paths; 
}

////////////////////////////////////////////////
// Question 4
////////////////////////////////////////////////
// runtime: O(n)
std::set<int> Graph::GetRoots() {
  std::set<int> roots;
  auto map_it = v_.begin(); 
  for(map_it; map_it != v_.end(); map_it++) {
    roots.insert(map_it->first); 
  }
  // go through all values, remove from set
  for(map_it = v_.begin(); map_it != v_.end(); map_it++) {
    for(auto n : map_it->second) {
      roots.erase(n); 
    }
  }
  return roots; 
}

// runtime: O(V + E)
std::map<int,int> Graph::GetDegrees() {
  std::map<int,int> deg; 
  for(auto it = v_.begin(); it != v_.end(); it++) {
    deg[it->first] = 0; 
  }
  for(auto it = v_.begin(); it != v_.end(); it++) {
    for(auto n : it->second) {
      deg[n]++; 
    }
  }
  return deg; 
}

// Using Kahn's Algorithm
// runtime: O(V+E)
std::vector<int> Graph::TopoSort() {
  int n = v_.size(); 
  // count the incoming degrees
  std::map<int,int> deg = GetDegrees(); 
  // queue up the roots
  std::queue<int> q; 
  for(auto it = v_.begin(); it != v_.end(); it++) {
    if(deg[it->first] == 0) {
      q.push(it->first); 
    }
  }
  std::vector<int> ret; 
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    ret.push_back(cur); 
    // loop through the children of cur
    for(auto it = v_[cur].begin(); it != v_[cur].end(); it++) {
      deg[*it]--;
      if(deg[*it] == 0) {
        q.push(*it); 
      }
    }
  }
  return ret;
}


////////////////////////////////////////////////
// Question 5
////////////////////////////////////////////////


// O(V+E)
std::vector<bool> Graph::ContainedInPath() {
  std::vector<bool> ret(v_.size()); 
  auto itr = v_.end(); 
  itr--; 
  std::vector<std::vector<int>> paths = ShortestPaths(v_.begin()->first, itr->first); 
  for(auto vect : paths) {
    for(auto node : vect) {
      ret[node] = true; 
    }
  }
  return ret;
}

// runtime: same as BFS: O(V+E)
std::vector<std::vector<int>> Graph::ShortestPaths(int root, int to) {
  std::map<int, int> marks;
  std::map<int, std::vector<std::vector<int>>> mp_map; 
  std::queue<int> q;
  mp_map[root] = {{root}}; 
  q.push(root);
  marks[root] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    
    std::vector<std::vector<int>> paths = mp_map[cur]; 
    for (auto &n : v_[cur]) { // check all neighbors
      if (!marks[n]) {
        if(mp_map.count(n) == 0 ) {
          for(auto& vect : paths) {
            if(vect[vect.size()-1] != cur) {
              vect.push_back(cur);
            }
            mp_map[n].push_back(vect);
          }
        }
        else {
          if(mp_map[n][0].size() > paths[0].size()) {
            mp_map[n].clear();
            //std::cout << "new path found" << std::endl;
            for(auto& vect : paths) {
              if(vect[vect.size()-1] != cur) {
                vect.push_back(cur);
              }
              mp_map[n].push_back(vect);  
            }
          }
          else if(mp_map[n][0].size() == paths[0].size()) {
            for(auto& vect : paths){
              //std::cout << "equal path found, n= " << n << std::endl;
              if(vect[vect.size()-1] != cur) {
                vect.push_back(cur);
              }
              mp_map[n].push_back(vect); 
            }
          }
        }
        q.push(n);
        marks[cur] = 1; 
      }
      
    }
  }
  for(auto it = mp_map.begin(); it != mp_map.end(); it++) {
    for(auto& vect : it->second) {
      vect.push_back(it->first); 
    }
  }
  return mp_map[to]; 
}
