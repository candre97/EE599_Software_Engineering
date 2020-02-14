#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <string>
#include <vector>
#include <numeric>

class MaxHeap {
public:
  MaxHeap(); // default constructor
  MaxHeap(std::vector<int>& v); // for testing purposes

  int GetParentIndex(int i); // *GT*
  int GetLeftIndex(int i); // *GT*
  int GetRightIndex(int i); // *GT*
  int GetLargestChildIndex(int i); // *GT*

  int GetLeft(int i);
  int GetRight(int i);
  int GetParent(int i);
  int GetLargestChild(int i);

  int top(); // GT
  void push(int v); // GT
  void pop(); // GT
  void TrickleUp(int i);
  void TrickleDown(int i);

  // for testing
  std::vector<int> GetData();

private:
  std::vector<int> data_;
};

#endif