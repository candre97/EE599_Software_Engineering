#include <iostream>
#include "src/lib/solution.h"
#include "src/lib/SinglyLinkedList.h"
#include "src/lib/AcademicRecord.h"
#include <iterator> 

void main_test_q5() {
    AcademicRecord obj1;
    obj1.math_g_ = 5;
    obj1.comp_g_ = 10;
    obj1.phys_g_ = 95;
    std::cout << obj1.Print() << std::endl;
    obj1++;
    std::cout << obj1.Print() << std::endl;
    obj1--;
    std::cout << obj1.Print() << std::endl;
    AcademicRecord obj2=obj1;
    std::cout<< obj2.Print() << std::endl;
    obj2+=50;
    std::cout << obj2.Print() << std::endl;
    obj2-=30;
    std::cout << obj2.Print() << std::endl;
}

void print_vect(std::vector<int> v) {
    std::cout << "*********************************************************************" << std::endl; 
    std::cout << "Vector: "; 
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i]; 
        if(i != v.size() - 1) {
            std::cout << ", "; 
        }
    }
    std::cout << std::endl; 
    std::cout << "*********************************************************************" << std::endl; 
}

void print_menu() {
    std::cout << "Menu: " << std::endl; 
    std::cout << "1. What is the first element?" << std::endl; 
    std::cout << "2. What is the last element?" << std::endl; 
    std::cout << "3. What is the current element?" << std::endl; 
    std::cout << "4. What is the i(th) element from the current location?" << std::endl; 
    std::cout << "5. Exit." << std::endl;
}

// runtime is O(n) for every lap through the while loop. 
// this is because of the print_vect() function
// selection=4 can also result in O(n) by itself
void run_program(std::vector<int> v) {
    int selection = 1; 
    int ith; 
    bool ok = true; 
    int j = 0; 
    std::vector<int>::iterator itr = v.begin(); 
    std::vector<int>::iterator old_itr; 
    while(selection != 5) {
        print_vect(v); 
        print_menu(); 
        do {
            std::cout << "Your Selection: >"; 
            std::cin >> selection; 
        } while(selection > 5 || selection < 1); 
        std::cout << "Output: "; 
        switch(selection) {
            case 1:
                itr = v.begin();
                std::cout << *itr << std::endl;
                break;
            case 2: 
                itr = v.end();
                itr--;
                std::cout << *itr << std::endl;
                break;
            case 3: 
                std::cout << *itr << std::endl;
                break;
            case 4: 
                do{
                    std::cout << "Enter the value of i: >";
                    std::cin >> ith; 
                    if(ith < 0) {
                        std::cout << "Value of i cannot be negative" << std::endl; 
                    }
                    if(ith > v.size()) {
                        std::cout << "Value of i cannot be greater than the size of vector" << std::endl;
                    }
                }while(ith < 0 || ith > v.size()); 
                ok = true;
                j = 0;
                old_itr = itr; 
                for(int i = 0; i < ith; i++) {
                    if(itr == v.end()) {
                        ok = false;
                    }
                    else if(ok) {
                        j++; 
                        itr++;
                    }
                }
                if(!ok) {
                    std::cout << "Sorry! You cannot traverse " << ith << " element(s) from your current location." << std::endl;
                    itr = old_itr; 
                }
                else {
                    std::cout << *itr << std::endl;
                }
                break;
            case 5: 
                std::cout << "Quitting...!" << std::endl; 
                break;
            default: 
                break;
        }
    }
}

int main()
{   
    std::vector<int> v = {1, 4, 5, 23, 100, 12, 18, 175}; 
    run_program(v); 

    return EXIT_SUCCESS;
}