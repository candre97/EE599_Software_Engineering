#include "BST.h"

/////////////////////////////////
// HW5
/////////////////////////////////

// question 1
// runtime: O(n)
int BST::MaxDepthRec(TreeNode* root) {
  int l = 0;
  int r = 0; 
  if (root == nullptr) {
    return 0;
  }
  else {
    l = MaxDepthRec(root->left); 
    r = MaxDepthRec(root->right); 
  }
  return std::max(l+1,r+1); 
}

// question 2 -- 
// part 1: recursive version
// runtime: O(n)
std::vector<int> BST::InOrderRec(TreeNode* a) {
  std::vector<int> ret;
  if(a != nullptr) {
    std::vector<int> l = InOrderRec(a->left); 
    ret.insert(ret.end(), l.begin(), l.end()); 
    ret.push_back(a->val); 
    std::vector<int> r = InOrderRec(a->right);
    ret.insert(ret.end(), r.begin(), r.end());
  }
  return ret; 
}

// part 2: non-recursive version 
// runtime: O(n)
std::vector<int> BST::InOrderNonRec() {
  std::vector<int> ret;
  TreeNode* curr = root_; 
  std::stack<TreeNode* > s; 
  while(curr != nullptr || s.size() != 0) {
    while(curr != nullptr) {
      s.push(curr); 
      curr = curr->left; 
    }
    curr = s.top(); 
    s.pop(); 
    ret.push_back(curr->val); 
    curr = curr->right; 
  }
 return ret; 
}

// to call this, insert at root, it will recursively call itself insert at 
// TreeNode* root = Some node (root of a subtree)
// runtime: O(h)
void BST::Insert(TreeNode*& root, int v) {
  if(root == nullptr) {
    root = new TreeNode(v);
  }
  else if (v < root->val) {
    Insert(root->left, v); 
  }
  else if( v > root->val) {
    Insert(root->right, v); 
  }
}

// runtime: O(1)
TreeNode* BST::GetRoot() {
  return root_; 
} 

// runtime: O(1)
BST::BST() {
  root_ = nullptr; 
}

// Inserts elements of initial_values
// one by one into the Tree
// runtime: O(n)
BST::BST(const std::vector<int>& a) {
  for(auto n : a) {
    Insert(root_, n); 
  }
}

// Gives you an array of TreeNodes in order... used for deletion
// runtime: O(n)
void BST::InOrder(TreeNode* a, std::vector<TreeNode*>& t) {
  if(a == nullptr) {
    return; 
  }
  InOrder(a->left, t); 
  t.push_back(a); 
  InOrder(a->right, t);
}

// go around deleting every Node!!
// using in order traversal
// runtime: O(n)
BST::~BST() {
  std::vector<TreeNode* > t; 
  InOrder(root_, t); 
  for(int i = 0; i < t.size(); i++) {
    delete t[i]; 
  }
}

// **GT** Inserts a key inside Tree
// runtime: O(h), h = height of tree
void BST::push(int key) {
  Insert(root_, key); 
}

// runtime: O(h), h = height of tree
bool BST::search(TreeNode* root, int v) {
  if (root == nullptr) {
    return root;
  }
  if (root->val == v) {
    return root;
  }
  if (v < root->val) {
    return search(root->left, v);
  } 
  else // v > root->val
  {
    return search(root->right, v);
  }
}

// **GT** Returns true if key is in the tree
// runtime: O(h), h = height of tree
bool BST::find(int key) {
  return search(root_, key); 
}

// **GT** Removes the key from the tree. If not successful, returns false.
// runtime: O(h), h = height of tree
bool BST::erase(int key) {
  if(!find(key)) {
    return false; // can't find the key to delete
  }
  TreeNode* parent = root_; 
  TreeNode* to_erase = root_; 
  while(to_erase != nullptr) {
    if(to_erase->val == key) {
      break; 
    }
    parent = to_erase;
    if(to_erase->val > key){
      to_erase = to_erase->left; 
    }
    else if(to_erase->val < key) {
      to_erase = to_erase->right; 
    }
  }
  // now we have to delete curr... 
  // case: big mistake... 
  if(to_erase == nullptr) {
    std::cout << "Error between the chair and the keyboard!" << std::endl; 
    return false; 
  }
  // case: curr is a leaf
  else if(to_erase->left == nullptr && to_erase->right == nullptr) {
    if(to_erase == root_) {
      root_ = nullptr; 
    }
    else if(parent->left == to_erase) {
      parent->left = nullptr;
    }
    else if(parent->right == to_erase) {
      parent->right = nullptr;
    }
    delete to_erase;
  }
  // case: only has a right child
  else if(to_erase->left == nullptr && to_erase->right != nullptr) {
    if(to_erase == root_) {
      root_ = to_erase->right; 
    }
    else {
      parent->right = to_erase->right; 
    }
    delete to_erase;
  }
  // case: only has a left child
  else if(to_erase->left != nullptr && to_erase->right == nullptr) {
    if(to_erase == root_) {
      root_ = to_erase->right; 
    }
    else {
      parent->left = to_erase->left; 
    }
    delete to_erase;
  }
  // case: curr has 2 children
  else if(to_erase->left != nullptr && to_erase->right != nullptr) {
    // find a suitable replacement node of middle ish value somewhere down the BST
    TreeNode* rn = to_erase->right; 
    while(rn->left != nullptr) {
      rn = rn->left; 
    }
    int r_val = rn->val;
    erase(r_val); 
    to_erase->val = r_val; 
  }
  return true; 
}

// BFS QUESTION 4!!
// BFS starting at root. Can be a subroot. 
// runtime: O(V+E) = O(vertexes + edges)
std::vector<int> BST::BFS(TreeNode* root) {
  std::vector<int> retval = {};
  std::queue<TreeNode*> to_visit = {}; 
  TreeNode* curr = nullptr; 
  // if we don't push, we dont enter while loop, and we return empty vector
  if(root != nullptr) {
    to_visit.push(root); 
  } 

  while(to_visit.size() > 0) {
    curr = to_visit.front();
    to_visit.pop();
    retval.push_back(curr->val); 
    // get their children in the queue!
    if(curr->left != nullptr) {
      to_visit.push(curr->left);
    } 
    if(curr->right != nullptr) {
      to_visit.push(curr->right);
    }
  }
  return retval; 
}

// runtime: O(V+E)
void BST::BFSPrint(TreeNode* root) {
  std::vector<int> r = BFS(root); 
  for(auto n : r) {
    std::cout << n << " ";
  }
  std::cout << std::endl; 
}