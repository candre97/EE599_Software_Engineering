#include "AcademicRecord.h"

// Implement the default constructor that initializes grades to 0.
// runtime: O(1)
AcademicRecord::AcademicRecord() {
  math_g_ = 0;
  phys_g_ = 0;
  comp_g_ = 0;
}

// runtime: O(1 * 6) = O(1)
void AcademicRecord::EnforceBounds(int* mg, int* pg, int* cg) {
  *mg = std::max(0,*mg); 
  *mg = std::min(100,*mg); 
  *pg = std::max(0,*pg); 
  *pg = std::min(100,*pg); 
  *cg = std::max(0,*cg); 
  *cg = std::min(100,*cg); 
}

// ● Implement a constructor that takes the initial grades as three parameters.
// runtime: O(1)
AcademicRecord::AcademicRecord(int mg, int pg, int cg) {
  // bound the inputs [0,100]
  math_g_ = mg; 
  phys_g_ = pg; 
  comp_g_ = cg; 
  EnforceBounds(&math_g_, &phys_g_, &comp_g_); 
}

// ● Implement the copy constructor.
// runtime: O(1)
AcademicRecord::AcademicRecord(const AcademicRecord* ar) {
  math_g_ = ar->math_g_; 
  phys_g_ = ar->phys_g_; 
  comp_g_ = ar->comp_g_; 
  EnforceBounds(&math_g_, &phys_g_, &comp_g_); 
}

// ● The class should support “++” and “--” operators (both postfix and prefix)
// ○ A “++” call should increase all marks of each subject by 10.
// runtime: O(1)
AcademicRecord AcademicRecord::operator++ () { // prefix
  comp_g_ += 10;
  phys_g_ += 10;
  math_g_ += 10;
  EnforceBounds(&math_g_, &phys_g_, &comp_g_); 
  AcademicRecord ar(math_g_, phys_g_, comp_g_); 
  return ar;  // return incremented values
} 

// runtime: O(1)
AcademicRecord AcademicRecord::operator++ (int) { // postfix
  AcademicRecord ar(math_g_, phys_g_, comp_g_); 
  math_g_ += 10; 
  phys_g_ += 10; 
  comp_g_ += 10; 
  EnforceBounds(&math_g_, &phys_g_, &comp_g_); 
  return ar; // return original values
}

// ○ A “--” call should decrease all marks of each subject by 20.
// runtime: O(1)
AcademicRecord AcademicRecord::operator-- () { // prefix 
  comp_g_ -= 20;
  phys_g_ -= 20;
  math_g_ -= 20;
  EnforceBounds(&math_g_, &phys_g_, &comp_g_); 
  AcademicRecord ar(math_g_, phys_g_, comp_g_); 
  return ar;  // return decremented values
}

// runtime: O(1)
AcademicRecord AcademicRecord::operator-- (int)  { // postfix 
  AcademicRecord ar(math_g_, phys_g_, comp_g_); 
  math_g_ -= 20; 
  phys_g_ -= 20; 
  comp_g_ -= 20; 
  EnforceBounds(&math_g_, &phys_g_, &comp_g_); 
  return ar; // return original values
}

// ● The class should support “+=” and “-=”, which affect all grades of the object.
// runtime: O(1)
void AcademicRecord::operator+= (int n) {
  math_g_ = math_g_ + n; 
  phys_g_ = phys_g_ + n; 
  comp_g_ = comp_g_ + n; 
  EnforceBounds(&math_g_, &phys_g_, &comp_g_); 
}
// runtime: O(1)
void AcademicRecord::operator-= (int n) {
  math_g_ = math_g_ - n; 
  phys_g_ = phys_g_ - n; 
  comp_g_ = comp_g_ - n; 
  EnforceBounds(&math_g_, &phys_g_, &comp_g_); 
}

// ● The class should support “==” for comparison.
// runtime: O(1)
bool AcademicRecord::operator== (const AcademicRecord& ar) {
  if(math_g_ == ar.math_g_ && phys_g_ == ar.phys_g_ && comp_g_ == ar.comp_g_) {
    return true;
  }
  return false; 
}

// ● After any operation, marks for any subject should stay within the range of 0 and 100:
// ○ If after any operation, marks for any subject are exceeding 100 then your code
// should simply set the marks of that particular subject as 100.
// ○ Similarly, if after any operation the mark of any subject below is 0 then your code
// should just set the marks of that particular subject to 0.

// ● Print(), which returns a string that contains all marks and can later be used to print the
// marks.
// runtime: O(1)
std::string AcademicRecord::Print() {
  std::string ret = "\nMath: " + std::to_string(math_g_) + "\nPhysics: " + std::to_string(phys_g_) +
                    " \nComputers: " + std::to_string(comp_g_); 
   return ret; 
}
