#include "src/lib/SinglyLinkedList.h"
#include "gtest/gtest.h"
#include <vector>

// // default constructor
// SinglyLinkedList();
TEST(Constructor, EmptyTest) {
    SinglyLinkedList ssl;
    std::vector<int> actual = ssl.list_to_vect(ssl.head_); 
    std::vector<int> expected = {}; 
    ASSERT_EQ(expected.size(), actual.size());
    for(int i = 0; i < actual.size(); i++) {
        ASSERT_EQ(expected[i], actual[i]); 
    }
}

// SinglyLinkedList(const std::vector<int> &inputs, int i); 
TEST(VectConstructor, OutOfRangeTest) {
    std::vector<int> v = {1,2,3,4}; 
    SinglyLinkedList ssl(v, 1);
    std::vector<int> actual = ssl.list_to_vect(ssl.head_); 
    std::vector<int> expected = {}; 
    ASSERT_EQ(expected.size(), actual.size());
}


// // Note do we need an actual destructor-- need to loop through the ll delete everything
// ~SinglyLinkedList();
// // destructor, cleans up

// bool empty(); // checks if empty
// int size(); // returns size
// void push_back(int i); // inserts at the back
// void push_front(int i); // inserts at the front
// void insert_after(ListNode* p, int i); // inserts value i after p
// void erase(ListNode* p); // Erases node p
// void pop_front(); // removes the first item
// void pop_back(); // removes the last item
// int back(); // returns the value of last item
// int front(); // returns the value of first item
// ListNode *GetBackPointer(); // Returns pointer to last item
// // Returns pointer to i(th) element
// ListNode *GetIthPointer(int i);
// // for testing purposes... 
// // this way tests can only worry about the int values in order. 
// // the order and the "next" is tested in the way the vector is assembled.
// std::vector<int> list_to_vect(ListNode* ptr);

// // Prints the list: ex. Empty list: {}. List with items: {1, 2, 3}
// void print();
// ListNode *head_; // Pointer to the first element, feels wrong as public