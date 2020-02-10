#include "src/lib/SinglyLinkedList.h"
#include "gtest/gtest.h"
#include <vector>

// // default constructor
// SinglyLinkedList();
TEST(Constructor, EmptyTest) {
    SinglyLinkedList sll;
    std::vector<int> actual = sll.list_to_vect(sll.head_); 
    std::vector<int> expected = {}; 
    EXPECT_EQ(expected.size(), actual.size());
    for(int i = 0; i < actual.size(); i++) {
        EXPECT_EQ(expected[i], actual[i]); 
    }
}

// // SinglyLinkedList(const std::vector<int> &inputs, int i); 
// TEST(VectConstructor, OutOfRangeTest) {
//     std::vector<int> v = {1,2,3,4}; 
//     SinglyLinkedList sll(v, 1);
//     std::vector<int> actual = sll.list_to_vect(sll.head_); 
//     std::vector<int> expected = {}; 
//     EXPECT_EQ(expected.size(), actual.size());
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
//     EXPECT_EQ(sll.size(), 0);
// }

// bool empty(); // checks if empty
TEST(Empty, BasicTest) {
    SinglyLinkedList sll;
    EXPECT_EQ(sll.empty(), true);
}

// int size(); // returns size
TEST(Size, BasicTest) {
    SinglyLinkedList sll;
    sll.push_back(3);
    EXPECT_EQ(sll.size(), 1);
}
TEST(Size, SizeZero) {
    SinglyLinkedList sll;
    EXPECT_EQ(sll.size(), 0);
}

// void push_back(int i); // inserts at the back
// int back(); // returns the value of last item
// void pop_back(); // removes the last item
TEST(PushPopBack, BasicTest) {
    SinglyLinkedList sll;
    sll.push_back(3);
    EXPECT_EQ(sll.back(), 3);
    sll.push_back(4); 
    EXPECT_EQ(sll.back(), 4);
    sll.pop_back();
    EXPECT_EQ(sll.back(), 3);
}
TEST(PushPopBack, EmptyTest) {
    SinglyLinkedList sll;
    sll.push_back(3);
    EXPECT_EQ(sll.back(), 3);
    sll.pop_back();
    EXPECT_EQ(sll.empty(), true);
    EXPECT_EQ(sll.size(), 0); 
    sll.push_back(3);
    sll.push_back(4);
    sll.push_back(5);
    EXPECT_EQ(sll.size(), 3); 
}
TEST(PushPopBack, HarderTest) {
    SinglyLinkedList sll;
    sll.push_back(3);
    EXPECT_EQ(sll.back(), 3);
    sll.push_back(3);
    sll.push_back(4);
    sll.push_back(5);
    EXPECT_EQ(sll.size(), 4); 
    EXPECT_EQ(sll.back(), 5); 
}

// void push_front(int i); // inserts at the front
// void pop_front(); // removes the first item
// int front(); // returns the value of first item
TEST(PushPopFront, BasicTest) {
    SinglyLinkedList sll;
    sll.push_front(3);
    EXPECT_EQ(sll.front(), 3);
    sll.push_front(4); 
    EXPECT_EQ(sll.front(), 4);
    sll.pop_front();
    EXPECT_EQ(sll.front(), 3);
}

TEST(PushPopFront, PopEmpty) {
    SinglyLinkedList sll;
    sll.push_front(3);
    EXPECT_EQ(sll.size(), 1); 
    sll.pop_front(); 
    EXPECT_EQ(sll.size(), 0); 
    EXPECT_EQ(sll.size(), 0); 
}

// void insert_after(ListNode* p, int i); // inserts value i after p
TEST(InsertAfter, BasicTest) {
    SinglyLinkedList sll;
    sll.push_front(1);
    sll.push_back(4);
    sll.insert_after(sll.head_, 2); 
    sll.insert_after(sll.head_->next, 3); 
    
    EXPECT_EQ(sll.front(), 1);
    sll.pop_front();
    EXPECT_EQ(sll.front(), 2);
    sll.pop_front();
    EXPECT_EQ(sll.front(), 3);
    sll.pop_front();
    EXPECT_EQ(sll.front(), 4);
}

// void erase(ListNode* p); // Erases node p
TEST(Erase, BasicTest) {
    SinglyLinkedList sll;
    sll.push_front(1);
    sll.push_back(4);
    sll.push_back(6);
    
    sll.erase(sll.head_->next); 
    EXPECT_EQ(sll.front(), 1);
    EXPECT_EQ(sll.back(), 6);
    EXPECT_EQ(sll.size(), 2);
}

// ListNode *GetBackPointer(); // Returns pointer to last item
TEST(GetBackPointer, BasicTest) {
    SinglyLinkedList sll;
    sll.push_front(1);
    sll.push_back(4);
    sll.push_back(6);
    EXPECT_EQ(sll.GetBackPointer()->val, 6);
}

// ListNode *GetIthPointer(int i);
TEST(GetIthPointer, BasicTest) {
    SinglyLinkedList sll;
    sll.push_front(1);
    sll.push_back(4);
    sll.push_back(6);
    EXPECT_EQ(sll.GetIthPointer(1)->val, 4);
    EXPECT_EQ(sll.GetIthPointer(2)->val, sll.GetBackPointer()->val);
}