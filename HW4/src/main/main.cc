#include <iostream>
#include "src/lib/solution.h"
#include "src/lib/MaxHeap.h"

int main()
{   
    std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
    MaxHeap* m = new MaxHeap(in);
    m->pop(); 
    m->Print();
    m->pop(); 
    m->Print();
    m->pop();
    m->Print();

    return EXIT_SUCCESS;    
}