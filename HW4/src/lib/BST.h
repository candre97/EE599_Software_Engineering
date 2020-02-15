#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
#include <numeric>
#include <iostream> 
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
public:
  // helper functions
  void Insert(TreeNode*& root, int v); 
  void InOrder(TreeNode* a, std::vector<TreeNode* >& t); 
  TreeNode* GetRoot(); 
  bool search(TreeNode* root, int v);

  BST();

  // Inserts elements of initial_values
  // one by one into the Tree
  BST(const std::vector<int>& a);

  ~BST();

  void push(int key); // **GT** Inserts a key inside Tree
  bool find(int key); // **GT** Returns true of key is in the tree
  bool erase(int key); // **GT** Removes the key from the tree. If not successful, returns false.
  
  // question 4. 
  // also used for testing Q3 functions. 
  std::vector<int> BFS(TreeNode* root); 
  void BFSPrint(TreeNode* root);

private:
  TreeNode* root_;
};

#endif