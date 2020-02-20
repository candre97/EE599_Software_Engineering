#include "src/lib/solution.h"
#include "src/lib/BST.h"
#include <iostream>
#include <map>
#include <vector>

void PrintVect(const std::vector<int>& v) {
    std::cout << "---------------------" << std::endl;
    for(auto n : v) {
        std::cout << n << ", "; 
    }
    std::cout << std::endl << "---------------------" << std::endl;
}

int main() {
  // Print Hellow world!
  BST* b = new BST();
  b->push(8); 
  b->push(9); 
  b->push(10); 
  b->push(11); 
  b->push(12); 
  b->push(13); 
  b->push(14); 
  b->push(15); 
  b->push(16); 
  std::vector<int> rec = b->InOrderRec(b->GetRoot()); 
  std::vector<int> nonrec = b->InOrderNonRec(); 

  PrintVect(rec); 
  PrintVect(nonrec); 
  return EXIT_SUCCESS;
}