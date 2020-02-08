#include "src/lib/SinglyLinkedList.h"
#include "gtest/gtest.h"
#include <vector>

// // default constructor
// SinglyLinkedList();
TEST(Constructor, EmptyTest) {
    SinglyLinkedList sll;
    std::vector<int> actual = sll.list_to_vect(sll.head_); 
    std::vector<int> expected = {}; 
    ASSERT_EQ(expected.size(), actual.size());
    for(int i = 0; i < actual.size(); i++) {
        ASSERT_EQ(expected[i], actual[i]); 
    }
}

// // SinglyLinkedList(const std::vector<int> &inputs, int i); 
// TEST(VectConstructor, OutOfRangeTest) {
//     std::vector<int> v = {1,2,3,4}; 
//     SinglyLinkedList sll(v, 1);
//     std::vector<int> actual = sll.list_to_vect(sll.head_); 
//     std::vector<int> expected = {}; 
//     ASSERT_EQ(expected.size(), actual.size());
// }


// // Note do we need an actual destructor-- need to loop through the ll delete everything
// ~SinglyLinkedList();
// // destructor, cleans up
// TEST(Destructor, OutOfRangeTest) {
//     std::vector<int> v = {1,2,3,4}; 
//     SinglyLinkedList sll;
//     sll.push_back(2);
//     sll.push_back(4); 
//     sll.~SinglyLinkedList(); 
//     ASSERT_EQ(sll.size(), 0);
// }

// bool empty(); // checks if empty
TEST(Empty, BasicTest) {
    SinglyLinkedList sll;
    ASSERT_EQ(sll.empty(), true);
}

// int size(); // returns size
TEST(Size, BasicTest) {
    SinglyLinkedList sll;
    sll.push_back(3);
    ASSERT_EQ(sll.size(), 1);
}
TEST(Size, SizeZero) {
    SinglyLinkedList sll;
    ASSERT_EQ(sll.size(), 0);
}

// void push_back(int i); // inserts at the back
// int back(); // returns the value of last item
// void pop_back(); // removes the last item
TEST(PushPopBack, BasicTest) {
    SinglyLinkedList sll;
    sll.push_back(3);
    ASSERT_EQ(sll.back(), 3);
    sll.push_back(4); 
    ASSERT_EQ(sll.back(), 4);
    sll.pop_back();
    ASSERT_EQ(sll.back(), 3);
}
TEST(PushPopBack, EmptyTest) {
    SinglyLinkedList sll;
    sll.push_back(3);
    ASSERT_EQ(sll.back(), 3);
    sll.pop_back();
    ASSERT_EQ(sll.empty(), true);
    ASSERT_EQ(sll.size(), 0); 
    sll.push_back(3);
    sll.push_back(4);
    sll.push_back(5);
    ASSERT_EQ(sll.size(), 3); 
}
TEST(PushPopBack, HarderTest) {
    SinglyLinkedList sll;
    sll.push_back(3);
    ASSERT_EQ(sll.back(), 3);
    sll.push_back(3);
    sll.push_back(4);
    sll.push_back(5);
    ASSERT_EQ(sll.size(), 4); 
    ASSERT_EQ(sll.back(), 5); 
}

// void push_front(int i); // inserts at the front
// void pop_front(); // removes the first item
// int front(); // returns the value of first item
TEST(PushPopFront, BasicTest) {
    SinglyLinkedList sll;
    sll.push_front(3);
    ASSERT_EQ(sll.front(), 3);
    sll.push_front(4); 
    ASSERT_EQ(sll.front(), 4);
    sll.pop_front();
    ASSERT_EQ(sll.front(), 3);
}

// void insert_after(ListNode* p, int i); // inserts value i after p
// void erase(ListNode* p); // Erases node p


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