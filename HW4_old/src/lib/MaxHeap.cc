#include "MaxHeap.h"

 // default constructor
MaxHeap::MaxHeap() {
  data_ = {}; // empty vector
}

// parameterized constructor -- for making testing easier
// does not do any checking or validation of the heap
MaxHeap::MaxHeap(std::vector<int>& v) {
  for(auto n : v) {
    data_.push_back(n); 
  }
}

// parent is the max value of the tree
int MaxHeap::GetParentIndex(int i) {
  if (i == 0) {
    return -1;
  }
  return (i - 1) / 2;
}


int MaxHeap::GetLeftIndex(int i) {
  if ((2 * i) + 1 >= data_.size()) {
    return -1;
  }
  return (2 * i) + 1;
}

int MaxHeap::GetRightIndex(int i) {
  if ((2 * i) + 2 >= data_.size()) {
    return -1;
  }
  return (2 * i) + 2;
}

int MaxHeap::GetLargestChildIndex(int i) {
  if(GetLeft(i) > GetRight(i)) {
    return GetLeftIndex(i); 
  }
  return GetRightIndex(i); 
}

int MaxHeap::GetLeft(int i) {
  int idx = GetLeftIndex(i); 
  if(idx == -1) {
    return INT_MIN; 
  }
  return data_[idx]; 
}

int MaxHeap::GetRight(int i) {
  int idx = GetRightIndex(i); 
  if(idx == -1) {
    return INT_MIN; 
  }
  return data_[idx]; 
}

int MaxHeap::GetParent(int i) {
  int idx = GetParentIndex(i); 
  if(idx == -1) {
    return INT_MIN; 
  }
  return data_[idx]; 
}

int MaxHeap::GetLargestChild(int i) {
  int idx = GetLargestChildIndex(i); 
  if(idx == -1) {
    return INT_MIN; 
  }
  return data_[idx]; 
}

int MaxHeap::top() {
  if (data_.size() == 0) {
    return INT_MIN;
  }
  return data_[0];
}

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

void MaxHeap::pop() {
// Remove root and replace
// it with the last item
// ● Trickle down to preserve
// heap
  std::swap(data_[0] , data_[data_.size() - 1]);
  data_.pop_back(); 
  TrickleDown(0); 
}

void MaxHeap::TrickleUp(int i) {
  while (i != 0 && GetParent(i) < data_[i]) {
    std::swap(data_[i], data_[GetParentIndex(i)]);
    i = GetParentIndex(i);
  }
}

void MaxHeap::TrickleDown(int i) {
  while (GetLargestChild(i) > data_[i]) {
    std::swap(data_[i], data_[GetLargestChildIndex(i)]);
    i = GetLargestChildIndex(i);
  }
}

std::vector<int> MaxHeap::GetData() {
  return data_; 
}