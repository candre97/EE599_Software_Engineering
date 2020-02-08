#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <string>
#include <vector>
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class SinglyLinkedList {
public:
  // default constructor
  SinglyLinkedList();

  /* Creates a linked list out of vector “inputs” and connects the last
item’s next to i(th) item in the list.
- If i is -1, the last item’s next is nullptr.
- If i is greater than input size, the last item’s next is nullptr. */
  SinglyLinkedList(const std::vector<int> &inputs, int i); 

// Note do we need an actual destructor-- need to loop through the ll delete everything
  ~SinglyLinkedList();
  // destructor, cleans up

  bool empty(); // checks if empty
  int size(); // returns size
  void push_back(int i); // inserts at the back
  void push_front(int i); // inserts at the front
  void insert_after(ListNode* p, int i); // inserts value i after p
  void erase(ListNode* p); // Erases node p
  void pop_front(); // removes the first item
  void pop_back(); // removes the last item
  int back(); // returns the value of last item
  int front(); // returns the value of first item
  ListNode *GetBackPointer(); // Returns pointer to last item
  // Returns pointer to i(th) element
  ListNode *GetIthPointer(int i);
  // for testing purposes... 
  // this way tests can only worry about the int values in order. 
  // the order and the "next" is tested in the way the vector is assembled.
  std::vector<int> list_to_vect(ListNode* ptr);

  // Prints the list: ex. Empty list: {}. List with items: {1, 2, 3}
  void print();
  ListNode *head_; // Pointer to the first element, feels wrong as public

  
};

#endif