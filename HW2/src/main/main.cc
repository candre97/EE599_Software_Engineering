#include <iostream>
#include "src/lib/solution.h"
#include <typeinfo>

int main()
{
    Solution solution ;
    std::cout << solution.PrintHelloWorld() << std::endl;

///////////////////////////////
// question 2
////////////////////////////////
/* 
How would you find the size of a non-dynamic array? (We are asking about an array, not a
vector). Provide the example and outputs of your run for:
● An array of integers
● An array of chars
● An array of floats
*/
    int a[] = {1,2,3,4}; 
    int size = *(&a + 1) - a;
    std::cout << size << std::endl; 

    char b[] = {'a', 'b', 'c', 'd'}; 
    size = *(&b + 1) - b; 
    std::cout << size << std::endl; 

    float c[] = {3.22, 4.54, 12.1, 23.0, 0.0}; 
    size = *(&c + 1) - c; 
    std::cout << size << std::endl; 



    return EXIT_SUCCESS;
}