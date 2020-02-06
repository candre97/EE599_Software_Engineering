README for HW3 Assignment

/////////////////////////////////////////////////////
// Question 1:
/////////////////////////////////////////////////////
Please compare pros and cons of the following options:
● Passing parameters by value
pros: changes don't persist to the input variable outside of the function
cons: slow, takes more time because you need to make a copy of the parameter you
are passing by value into the function
Used when: you pass in smaller data types (like an int) where making a copy won't slow down your program too much. You do not want changes to the input to persist outside the function

● Passing parameters using pointers
pros: can change the value of the variable passed in to the function, faster than pass by value because you don't need to make a copy
cons: might make changes to memory or the variable that you pass in that you don't intend
Used when: you want changed to persist with the possibility of the pointer becoming nullptr or reassigned after the function

● Passing parameters using references -- very similar to passing parameters using pointers
pros: can change the value of the variable passed in to the function, faster than pass by value because you don't need to make a copy
cons: might make changes to memory or the variable that you pass in that you don't intend
Used when: you want changes to persist to a variable with no need to return nullptr or reassigning 

● Passing parameters using const references
pros: faster than pass by value because you don't need to make a copy of the input variable, protects your variable from changes if you want to guarantee that there are none
cons: ... can't really think of any, besides maybe making your code convoluted and ugly if you do void DoWork(const int &n). Might make things harder in your function if you need to make a copy or the input anyways
Used when: you're passing in a large data type like a vector or string and want to ensure that changes are not made despite it being passed by value


/////////////////////////////////////////////////////
// Question 2 implementation & Runtime Analysis -- 
// See solution_test class
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// Question 3 implementation & Runtime Analysis -- 
// See ListNode class
/////////////////////////////////////////////////////




































# C++ Template for Bazel and Google Test


> Can be used in Visual Studio Code

You can use this template for most of your C++ projects without the need for changing the BUILD files.

## Installation

You can copy this using this command:

```bash
git clone https://github.com/ourarash/cpp-template.git
```

### Run main:

You can run this using `blaze`:

```bash
bazel run src/main:main
```

### Run Tests:

You can run unit tests using [`blaze`](installing-bazel):

```bash
bazel test tests:tests
```

## Directory Structure

![Directory Structure](https://github.com/ourarash/cpp-template/blob/master/tree.png?raw=true | width = 100)

## Installing Bazel

This repo uses `Bazel` for building C++ files.
You can install Bazel using this [link](https://docs.bazel.build/versions/master/install.html).

### Credit

This repo was inspired by [this post](https://www.ratanparai.com/c++/writing-unit-tests-with-bazel/).
