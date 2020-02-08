#include <iostream>
#include "src/lib/solution.h"
#include "src/lib/SinglyLinkedList.h"

int main()
{
    std::vector<int> v = {1,2,3}; 
    SinglyLinkedList sll(v,-1); 
    sll.print();
    sll.pop_back(); 
    sll.pop_back();
    sll.pop_back();
    std::cout << sll.size() << std::endl;
    return EXIT_SUCCESS;
}