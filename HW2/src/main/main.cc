#include <iostream>
#include "src/lib/solution.h"
#include <typeinfo>

int main()
{
    Solution solution ;
    //std::cout << solution.PrintHelloWorld() << std::endl;
    std::string in1 = "TEST"; 
    std::cout << in1 << std::endl;
    solution.SwapCharByIdx(in1, 0, 1); 
    std::cout << in1 << std::endl;
    in1 = "EE599"; 
    solution.ReverseStr(in1); 
    std::cout << in1 << std::endl;
    in1 = "EE599"; 
    solution.ToLower(in1); 
    std::cout << in1 << std::endl;
/*
    int i1 = 1;
    int i2 = 2;
    std::cout << i1 << i2 << std::endl;
    solution.SwapByRef(i1, i2); 
    std::cout << i1 << i2 << std::endl;
    solution.SwapPtrs(&i1, &i2); 
    std::cout << i1 << i2 << std::endl;
*/
/*
    std::vector<int> v1 = {1,2,3}; 
    std::vector<int> v2 = {3,5,6}; 
    std::vector<int> v = solution.UnionVect(v1,v2); 
    std::vector<int> expected = {3};
    if(v.size() == expected.size()){
        std::cout << "Same Size" << std::endl;
    } 
    for(auto n : v) {
        std::cout << n << std::endl; 
    }
    std::cout << "-----------" << std::endl;
    for(auto n : expected) {
        std::cout << n << std::endl; 
    }

*/
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
    // int a[] = {1,2,3,4}; 
    // int size = *(&a + 1) - a;
    // std::cout << size << std::endl; 

    // char b[] = {'a', 'b', 'c', 'd'}; 
    // size = *(&b + 1) - b; 
    // std::cout << size << std::endl; 

    // float c[] = {3.22, 4.54, 12.1, 23.0, 0.0}; 
    // size = *(&c + 1) - c; 
    // std::cout << size << std::endl; 



    return EXIT_SUCCESS;
}