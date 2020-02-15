#include <iostream>
#include "src/lib/solution.h"
#include "src/lib/MaxHeap.h"
#include "src/lib/BST.h"

void PrintVect(const std::vector<int>& v) {
    std::cout << "---------------------" << std::endl;
    for(auto n : v) {
        std::cout << n << ", "; 
    }
    std::cout << std::endl << "---------------------" << std::endl;
}

int main()
{   
    Solution sol; 
    std::vector<int> input = {5, 9, 3, 1, 7};
    std::vector<int> exp = {1, 3, 5, 7, 9};
    std::vector<int> actual = sol.QueueSort(input); 
    
    PrintVect(actual); 
    return EXIT_SUCCESS;    
}