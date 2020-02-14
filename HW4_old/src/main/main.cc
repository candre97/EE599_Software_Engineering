#include <iostream>
#include "src/lib/solution.h"
#include "src/lib/MaxHeap.h"

int main()
{
    std::vector<int> in = {103,96,89,90,88,54,43,23,11,32,41,20,19,3,5};
    MaxHeap* m = new MaxHeap(in);
        
    for(auto n : m->GetData()) {
        std::cout << n << " "; 
    }
    std::cout << std::endl; 

    m->pop(); 

    for(auto n : m->GetData()) {
        std::cout << n << " "; 
    }
    std::cout << std::endl; 

    return EXIT_SUCCESS;    
}