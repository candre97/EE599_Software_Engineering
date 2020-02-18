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
    int res = sol.FindKthLargest(input, 40); 
    std::cout << res << std::endl;

    PrintVect(input); 

    return EXIT_SUCCESS;    
}