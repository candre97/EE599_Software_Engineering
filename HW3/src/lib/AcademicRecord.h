#ifndef ACADEMIC_RECORD_H
#define ACADEMIC_RECORD_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class AcademicRecord {
public:
  // Implement the default constructor that initializes grades to 0.
  AcademicRecord(); 
  
  // bounds three inputs on [0,100]
  void EnforceBounds(int* mg, int* pg, int* cg);

  // ● Implement a constructor that takes the initial grades as three parameters.
  AcademicRecord(int mg, int pg, int cg); 
  
  // ● Implement the copy constructor.
  AcademicRecord(const AcademicRecord* ar); 

  // ● The class should support “++” and “--” operators (both postfix and prefix)
  // ○ A “++” call should increase all marks of each subject by 10.
  AcademicRecord operator ++ (); // prefix
  AcademicRecord operator ++ (int); // postfix

  // ○ A “--” call should decrease all marks of each subject by 20.
  AcademicRecord operator -- (); // prefix
  AcademicRecord operator -- (int); // postfix

  // ● The class should support “+=” and “-=”, which affect all grades of the object.
  void operator += (int n); 
  void operator -= (int n); 

  // ● The class should support “==” for comparison.
  bool operator == (const AcademicRecord& ar); 

  // ● After any operation, marks for any subject should stay within the range of 0 and 100:
  // ○ If after any operation, marks for any subject are exceeding 100 then your code
  // should simply set the marks of that particular subject as 100.
  // ○ Similarly, if after any operation the mark of any subject below is 0 then your code
  // should just set the marks of that particular subject to 0.

  // ● Print(), which returns a string that contains all marks and can later be used to print the
  // marks.
  std::string Print(); 

  // going to follow the standed set by ll class and keep these public, though it makes me feel physically ill
  int math_g_; 
  int phys_g_; 
  int comp_g_; 
};

#endif