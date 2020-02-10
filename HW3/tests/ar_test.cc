#include "src/lib/AcademicRecord.h"
#include "gtest/gtest.h"
#include <vector>

// Implement the default constructor that initializes grades to 0.
//   AcademicRecord(); 
TEST(DefaultConstructor, InitializeAllToZero) {
  AcademicRecord ar; 
  EXPECT_EQ(0,ar.phys_g_&ar.math_g_&ar.comp_g_); 
}

//   // bounds three inputs on [0,100]
//   void EnforceBounds(int* mg, int* pg, int* cg);
TEST(EnforceBounds, BasicTest) {
  AcademicRecord ar; 
  int i,j,k; 
  i = 103; 
  j = -3;
  k = 100; 
  ar.EnforceBounds(&i,&j,&k);
  EXPECT_EQ(100,i); 
  EXPECT_EQ(0,j); 
  EXPECT_EQ(100,k); 
}

//   // ● Implement a constructor that takes the initial grades as three parameters.
//   AcademicRecord(int mg, int pg, int cg); 
TEST(ParameterizedConstructor, BasicTest) {
  AcademicRecord ar(50,60,70); 
  EXPECT_EQ(50,ar.math_g_); 
  EXPECT_EQ(60,ar.phys_g_); 
  EXPECT_EQ(70,ar.comp_g_); 
}

TEST(ParameterizedConstructor, Bounded) {
  AcademicRecord ar(500,-60,70); 
  EXPECT_EQ(100,ar.math_g_); 
  EXPECT_EQ(0,ar.phys_g_); 
  EXPECT_EQ(70,ar.comp_g_); 
}
  
//   // ● Implement the copy constructor.
//   AcademicRecord(const AcademicRecord* ar); 
TEST(CopyConstructor, BasicTest) {
  AcademicRecord ar(50,60,70); 
  AcademicRecord ar_copy(ar); 
  EXPECT_EQ(ar_copy.math_g_, ar.math_g_); 
  EXPECT_EQ(ar_copy.phys_g_, ar.phys_g_); 
  EXPECT_EQ(ar_copy.comp_g_, ar.comp_g_); 
}

//   // ● The class should support “++” and “--” operators (both postfix and prefix)
//   // ○ A “++” call should increase all marks of each subject by 10.
//   AcademicRecord operator ++ (); // prefix
TEST(IncPrefix, BasicTest) {
  AcademicRecord ar(50,60,70); 
  AcademicRecord ar2 = ar++;
  EXPECT_GT(ar.comp_g_, ar2.comp_g_); 
  EXPECT_GT(ar.phys_g_, ar2.phys_g_); 
  EXPECT_GT(ar.math_g_, ar2.math_g_); 
}

//   AcademicRecord operator ++ (int); // postfix
TEST(IncPostfix, BasicTest) {
  AcademicRecord ar(50,60,70); 
  AcademicRecord ar2 = ++ar;
  EXPECT_EQ(ar.comp_g_, ar2.comp_g_); 
  EXPECT_EQ(ar.phys_g_, ar2.phys_g_); 
  EXPECT_EQ(ar.math_g_, ar2.math_g_); 
}

//   // ○ A “--” call should decrease all marks of each subject by 20.
//   AcademicRecord operator -- (); // prefix
TEST(DecPrefix, BasicTest) {
  AcademicRecord ar(50,60,70); 
  AcademicRecord ar2 = ar--;
  EXPECT_LT(ar.comp_g_, ar2.comp_g_); 
  EXPECT_LT(ar.phys_g_, ar2.phys_g_); 
  EXPECT_LT(ar.math_g_, ar2.math_g_); 
}

//   AcademicRecord operator -- (int); // postfix
TEST(DecPostfix, BasicTest) {
  AcademicRecord ar(50,60,70); 
  AcademicRecord ar2 = --ar;
  EXPECT_EQ(ar.comp_g_, ar2.comp_g_); 
  EXPECT_EQ(ar.phys_g_, ar2.phys_g_); 
  EXPECT_EQ(ar.math_g_, ar2.math_g_); 
}


//   // ● The class should support “+=” and “-=”, which affect all grades of the object.
//   void operator += (int n); 
TEST(PlusEquals, BasicTest) {
  AcademicRecord ar(50,60,70); 
  ar += 20; 
  EXPECT_EQ(ar.comp_g_, 90); 
  EXPECT_EQ(ar.phys_g_, 80); 
  EXPECT_EQ(ar.math_g_, 70); 
  ar += 20; 
  EXPECT_EQ(ar.comp_g_, 100); 
  EXPECT_EQ(ar.phys_g_, 100); 
  EXPECT_EQ(ar.math_g_, 90); 
}

//   void operator -= (int n); 
TEST(MinusEquals, BasicTest) {
  AcademicRecord ar(20,40,60); 
  ar -= 20; 
  EXPECT_EQ(ar.comp_g_, 40); 
  EXPECT_EQ(ar.phys_g_, 20); 
  EXPECT_EQ(ar.math_g_, 0); 
  ar -= 20; 
  EXPECT_EQ(ar.comp_g_, 20); 
  EXPECT_EQ(ar.phys_g_, 0); 
  EXPECT_EQ(ar.math_g_, 0); 
}
//   // ● The class should support “==” for comparison.
//   bool operator == (const AcademicRecord& ar); 
TEST(EqualsEquals, BasicTest) {
  AcademicRecord ar(20,40,60); 
  AcademicRecord ar2(ar); 
  EXPECT_TRUE(ar == ar2); 
  ar -= 10; 
  EXPECT_FALSE(ar == ar2); 
}
