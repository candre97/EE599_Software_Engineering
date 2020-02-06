#include "SinglyLinkedList.h"

// default constructor
SinglyLinkedList::SinglyLinkedList() {
  ListNode* ln(0); 
  ln->next = nullptr;
  ln->val = 0;
  head_ = ln; 
}

/* Creates a linked list out of vector “inputs” and connects the last
item’s next to i(th) item in the list.
- If i is -1, the last item’s next is nullptr.
- If i is greater than or equal to input size, the last item’s next is nullptr. 
- assuming that i is the index of the tail, i <= size - 1
*/
SinglyLinkedList::SinglyLinkedList(const std::vector<int> &inputs, int i) {
  ListNode* temp(0); 

  if(i == -1 || i > inputs.size()) {
    ListNode* tail(0); 
    tail->val = inputs[inputs.size()-1]; 
    tail->next = nullptr; 
    temp = tail; 
  }
  else {
    ListNode* tail(0); 
    tail->val = inputs[i]; 
    tail->next = nullptr; 
    temp = tail; 
  }
  
  for(int j = inputs.size() - 1; j > -1; j--) {
    if(j == i) {
      continue;
    }
    ListNode* toAdd(0); 
    toAdd->val = inputs[j];
    toAdd->next = temp;
    temp = toAdd; 
  }
  head_ = temp; 
}

// destructor, cleans up
// SinglyLinkedList::~SinglyLinkedList() { 
//   // iterate through the list, delete every ListNode 
// } 

// checks if empty
bool SinglyLinkedList::empty() {
  return (head_->next == nullptr);
}

// returns size
int SinglyLinkedList::size() {

}

// inserts at the back
void SinglyLinkedList::push_back(int i) {

}

// inserts at the front
void SinglyLinkedList::push_front(int i) {

}

// inserts value i after p
void SinglyLinkedList::insert_after(ListNode* p, int i) {

}

// Erases node p
void SinglyLinkedList::erase(ListNode* p) {

}

// removes the first item
void SinglyLinkedList::pop_front() {
  
}

// removes the last item
void SinglyLinkedList::pop_back() {

}

// returns the value of last item
int SinglyLinkedList::back() {

}

// returns the value of first item 
int SinglyLinkedList::front() {

}

// Returns pointer to last item
ListNode* SinglyLinkedList::GetBackPointer() {

}

// Returns pointer to i(th) element
ListNode* SinglyLinkedList::GetIthPointer(int i) {

}

// Prints the list: ex. Empty list: {}. List with items: {1, 2, 3}
void SinglyLinkedList::print() {

}

//ListNode *head_; // Pointer to the first element, feels wrong as public