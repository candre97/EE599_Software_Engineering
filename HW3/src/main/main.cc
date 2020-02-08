#include <iostream>
#include "src/lib/solution.h"
#include "src/lib/SinglyLinkedList.h"

int main()
{
    std::vector<int> v = {1,2,3,4}; 
    SinglyLinkedList sll(v,-1); 
    sll.print();
    std::vector<int> v2 = sll.list_to_vect(sll.head_); 
    std::cout << v2[0] << v2[1] << std::endl;
    return EXIT_SUCCESS;
}