#include "SinglyLinkedList.h"

// default constructor --
// runtime: O(1)
SinglyLinkedList::SinglyLinkedList() {
  head_ = nullptr; 
}

/* Creates a linked list out of vector “inputs” and connects the last
item’s next to i(th) item in the list.
- If i is -1, the last item’s next is nullptr.
- If i is greater than or equal to input size, the last item’s next is nullptr. 
- assuming that i is the index of the tail, i <= size - 1
*/
// runtime: O(n)
SinglyLinkedList::SinglyLinkedList(const std::vector<int> &inputs, int i) {
  if((i  < 0) || (i > inputs.size()) || (i == inputs.size() - 1)) {
    for(int j = 0; j < inputs.size(); j++) {
      //std::cout << j << std::endl; 
      push_back(inputs[j]);
    }
  }
  else {
    for(int j = i + 1; j < inputs.size(); j++) {
      push_back(inputs[j]);
    }
    for(int j = 0; j <= i; j++) {
      push_back(inputs[j]);
    }
    //push_back(inputs[i]); 
  }
}

// destructor, cleans up
// runtime: O(n)
SinglyLinkedList::~SinglyLinkedList() { 
  // iterate through the list, delete every ListNode 
  if(size() == 0) {
    delete head_; 
    return; 
  }
  ListNode* curr_node = head_; 
  ListNode* next_node = nullptr;
  while(curr_node != nullptr) {
    next_node = curr_node->next; 
    delete curr_node; 
    curr_node = next_node; 
  }
} 

// checks if empty
// runtime: O(1)
bool SinglyLinkedList::empty() {
  return (head_ == nullptr);
}

// returns size
// // runtime: O(n)
int SinglyLinkedList::size() {
  int retval = 0;
  for(ListNode* ptr = head_; ptr != nullptr; ptr = ptr->next) {
    retval++;
  }
  return retval; 
}

// inserts at the back 
// runtime: O(n)
void SinglyLinkedList::push_back(int i) {
  if(empty()) {
    push_front(i);  // stupid fix, but a fix nonetheless
    return;
  }
  ListNode* ptr;
  for(ptr = head_; ptr->next != nullptr; ptr = ptr->next) {
  }
  ListNode* new_tail = new ListNode(i); 
  new_tail->next = nullptr; 
  ptr->next = new_tail; 
}

// inserts at the front
// runtime: O(1)
void SinglyLinkedList::push_front(int i) {
  ListNode* new_head = new ListNode(i);
  new_head->next = head_; 
  head_ = new_head;  
}

// inserts value i after p
// runtime: O(n)
void SinglyLinkedList::insert_after(ListNode* p, int i) {
  ListNode* ptr = head_; 
  for(ptr; ptr != nullptr; ptr = ptr->next) {
    if(ptr->next == p->next && ptr->val == p->val) {
      // this is the one!! 
      // Note: initially tried checking for same memory addresses, didn't work! 
      break; 
    }
  }
  if(ptr == nullptr) {
    std::cout << "Node p not found in list" << std::endl;
    return; 
  }
  ListNode* toAdd = new ListNode(i); 
  toAdd->next = ptr->next; 
  ptr->next = toAdd; 
}

// Erases node p
// runtime: O(n)
void SinglyLinkedList::erase(ListNode* p) {
  ListNode* ptr = head_; 
  ListNode* prev = ptr;
  for(ptr; ptr != nullptr; ptr = ptr->next) {
    if(ptr->next == p->next && ptr->val == p->val) {
      // this is the one!! 
      // Note: initially tried checking for same memory addresses, didn't work! 
      break; 
    }
    prev = ptr; 
  }
  if(ptr == nullptr) {
    std::cout << "Node p not found in list" << std::endl;
    return; 
  }
  prev->next = ptr->next; 
  ptr->next = nullptr; 
  delete ptr; 
}

// removes the first item & delete from memory
// runtime: O(1)
void SinglyLinkedList::pop_front() {
  if(empty()) {
    return;
  }
  ListNode* to_remove = head_; 
  head_ = to_remove->next; 
  delete to_remove; 
}

// removes the last item & delete from memory
// runtime: O(n)
void SinglyLinkedList::pop_back() {
  if(empty()) {
    return;
  }
  if(size() == 1) {
    head_->next = nullptr; 
    head_ = nullptr; 
    return; 
  }
  ListNode* ptr = head_; 
  ListNode* prev = ptr; 
  for(ptr; ptr->next != nullptr; ptr = ptr->next) {
    // advance to last item in the linked list
    prev = ptr; 
  }
  prev->next = nullptr; 
  delete ptr; 
}

// returns the value of last item
// runtime: O(n)
int SinglyLinkedList::back() {
  ListNode* ptr = nullptr; 
  for(ptr = head_; ptr->next != nullptr; ptr = ptr->next) {
    // advance to last item in the linked list
  }
  return ptr->val; 
}

// returns the value of first item 
// runtime: O(1)
int SinglyLinkedList::front() {
  if(head_ == nullptr) {
    return INT16_MIN; 
  }
  else {
    return head_->val; 
  }
  return INT16_MIN; // compiler was complaining 
}

// Returns pointer to last item
// runtime: O(n)
ListNode* SinglyLinkedList::GetBackPointer() {
  ListNode* ptr = head_; 
  for(ptr = head_; ptr->next != nullptr; ptr = ptr->next) {
    // advance to last item in the linked list
  }
  return ptr; 
}

// Returns pointer to i(th) element. head is at i = 0
// runtime: O(n) = O(i)
ListNode* SinglyLinkedList::GetIthPointer(int i) {
  if(i > size() - 1 || i < 0) {
    std::cout << "Error, index out of range" << std::endl;
    return nullptr; 
  }
  ListNode* ith = head_; 
  for(int j = 0; j < i; j++) {
    ith = ith->next; 
  }
  return ith; 
}

// Prints the list: ex. Empty list: {}. List with items: {1, 2, 3}
// runtime: O(n)
void SinglyLinkedList::print() {
  std::cout << "{"; 
  for(ListNode* ptr = head_; ptr != nullptr; ptr = ptr->next) {
    std::cout << ptr->val; 
    if(ptr->next != nullptr) {
      std::cout << ", " ; 
    }
  }
  std::cout << "}" << std::endl;
}

// called with head_ as parameter to convert full list to vector 
// runtime: O(n)
std::vector<int> SinglyLinkedList::list_to_vect(ListNode* ptr) {
  std::vector<int> retval = {};
  for(ptr; ptr != nullptr; ptr = ptr->next) {
    retval.push_back(ptr->val); 
  }
  return retval; 
}

//ListNode *head_; // Pointer to the first element, feels wrong as public