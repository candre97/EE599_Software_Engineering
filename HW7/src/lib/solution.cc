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
          if(paths[n].size() > p.size() + 1) {
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


std::vector<bool> Graph::ContainedInPath() {

}
std::vector<std::vector<int>> Graph::ShortestPaths(int from, int to) {
  std::map<int, int> marks;
  std::map<int, std::vector<std::vector<int>>> mp_map; 
  std::queue<int> q;
  int root = from; 
  mp_map[root] = {{from}}; 
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
            vect.push_back(cur);
            mp_map[n].push_back(vect);
          }
        }
        else {
          if(mp_map[n][0].size() > paths[0].size() + 1) {
            mp_map[n].clear();
            for(auto& vect : paths) {
              vect.push_back(cur);
              mp_map[n].push_back(vect);  
            }
          }
          if(mp_map[n].size() == paths[0].size() + 1) {
            for(auto& vect : paths){
              vect.push_back(cur); 
              mp_map[n].push_back(vect); 
            }
          }
        }
        marks[n] = 1;
        q.push(n);
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

/*
// supports Multiple equal shortest paths
// Runtime: Same at BFS: O(V + E)
std::vector<std::vector<int>> Graph::ShortestPaths(int from, int to) {
  std::map<int, int> marks;
  std::map<int, std::vector<std::vector<int>>> paths = {{from, {}}}; 
  std::queue<int> q;
  q.push(from);
  marks[from] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    std::vector<std::vector<int>> p = paths[cur]; 
    for (auto &n : v_[cur]) {
      if (!marks[n]) {
        if(paths.count(n) == 0) { // no path, append whatever
          //paths[n] = p; 
          for(int i = 0; i < p.size(); i++) {
            std::vector<int> p1 = p[i]; 
            p1.push_back(cur); 
            paths[n].push_back(p1); 
          }
        }
        else { // current path exists
          // current path is longer, replace completely
          if(paths[n][0].size() > p[0].size() + 1) {
            paths[n].clear();
            paths[n] = p;
            for(auto& vect : paths[n]) {
              vect.push_back(cur); 
            }
          }
          // equal path, append to list of paths
          if(paths[n][0].size() == p[0].size() + 1) {
            for(int i = 0; i < p.size(); i++) {
              p[i].push_back(cur); 
              paths[n].push_back(p[i]); 
            }
          } 
        }
        marks[n] = 1;
        q.push(n);
      }
    }
  }
  for(auto it = paths.begin(); it != paths.end(); it++) {
    for(auto& vect : it->second) {
      vect.push_back(it->first); 
    }
  }
  return paths[to]; 
}
*/