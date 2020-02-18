#include "MaxHeap.h"

 // default constructor
 // runtime: O(1)
MaxHeap::MaxHeap() {
  data_ = {}; // empty vector
}

// parameterized constructor -- for making testing easier
// does not do any checking or validation of the heap
 // runtime: O(n)
MaxHeap::MaxHeap(std::vector<int>& v) {
  for(auto n : v) {
    data_.push_back(n); 
  }
}

// parent is the max value of the tree
 // runtime: O(1)
int MaxHeap::GetParentIndex(int i) {
  if (i < 1) {
    return -1;
  }
  if( i > data_.size() - 1) {
    return -1;
  }
  return (i - 1) / 2;
}

 // runtime: O(1)
int MaxHeap::GetLeftIndex(int i) {
  if ((2 * i) + 1 >= data_.size()) {
    return -1;
  }
  if (i < 0) {
    return -1; 
  }
  return (2 * i) + 1;
}

 // runtime: O(1)
int MaxHeap::GetRightIndex(int i) {
  if ((2 * i) + 2 >= data_.size()) {
    return -1;
  }
  if (i < 0) {
    return -1; 
  }
  return (2 * i) + 2;
}

 // runtime: O(1)
int MaxHeap::GetLargestChildIndex(int i) {
  if(GetLeft(i) > GetRight(i)) {
    return GetLeftIndex(i); 
  }
  return GetRightIndex(i); 
}

 // runtime: O(1)
int MaxHeap::GetLeft(int i) {
  int idx = GetLeftIndex(i); 
  if(idx == -1) {
    return INT_MIN; 
  }
  return data_[idx]; 
}

 // runtime: O(1)
int MaxHeap::GetRight(int i) {
  int idx = GetRightIndex(i); 
  if(idx == -1) {
    return INT_MIN; 
  }
  return data_[idx]; 
}

 // runtime: O(1)
int MaxHeap::GetParent(int i) {
  int idx = GetParentIndex(i); 
  if(idx == -1) {
    return INT_MIN; 
  }
  return data_[idx]; 
}

 // runtime: O(1)
int MaxHeap::GetLargestChild(int i) {
  int idx = GetLargestChildIndex(i); 
  if(idx == -1) {
    return INT_MIN; 
  }
  return data_[idx]; 
}

 // runtime: O(1)
int MaxHeap::top() {
  if (data_.size() == 0) {
    return INT_MIN;
  }
  return data_[0];
}

 // runtime: O(log n)
void MaxHeap::push(int v) {
//   Add to the end
// ● Trickle up to preserve
// heap property
// ○ also known as bubble-up,
// percolate-up, sift-up,
// heapify-up, or cascade-up
  data_.push_back(v); 
  TrickleUp(data_.size() - 1); 
}

 // runtime: O(log n)
void MaxHeap::pop() {
// Remove root and replace
// it with the last item
// ● Trickle down to preserve
// heap
  std::swap(data_[0] , data_[data_.size() - 1]);
  data_.pop_back(); 
  TrickleDown(0); 
}

 // runtime: O(log n)
void MaxHeap::TrickleUp(int i) {
  while (i != 0 && GetParent(i) < data_[i]) {
    std::swap(data_[i], data_[GetParentIndex(i)]);
    i = GetParentIndex(i);
  }
}

 // runtime: O(log n)
void MaxHeap::TrickleDown(int i) {
  int idx = 0;
  while (GetLargestChild(i) > data_[i]) {
    idx = GetLargestChildIndex(i);
    std::swap(data_[i], data_[idx]);
    i = idx;
  }
}

 // runtime: O(1)
std::vector<int> MaxHeap::GetData() {
  return data_; 
}

// runtime: O(n)
void MaxHeap::Print() {
  std::cout << "---------------" << std::endl; 
  std::cout << "SIZE: " << data_.size() << std::endl;
  for(int i = 0; i < data_.size(); i++) {
    std::cout << data_[i] << ", "; 
    if(i == 0 || i == 2 || i == 6 || i == 14) {
      std::cout << std::endl; 
    }
  }
  std::cout << std::endl << "---------------" << std::endl; 
}