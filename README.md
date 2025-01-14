# Algorithms-and-Datatructures
Welcome to my repository where I solve and document exercises from the subject Algorithms & Data Structures. This repository will serve as a progressive record of my work, including code, explanations, and analyses for each exercise.

## Table of contents
- [Introduction](#introduction)
- [Exersizes](#exersizes)
    - [C++ Basics, Complexity, and ADT](#c-basics-complexity-and-adt)
        - [Exersize 1](#exersize-1)
        - [Exersize 2](#exersize-2)
        - [Exersize 3](#exersize-3)
        - [Exersize 4](#exersize-4)
        - [Exersize 5](#exersize-5)
        
    - [Elementary data structures and their processing](#elementary-data-structures-and-their-processing)
        - [Exersize 1 - List Abstract Data Type and Linked List](#exersize-1---list-abstract-data-type-and-linked-list)
        - [Exersize 2 - Implementing a Stack Using an Array](#exersize-2---implementing-a-stack-using-an-array)
        - [Exersize 3 - Queue Using Stack(s)](#exersize-3---queue-using-stacks)
        - [Exersize 4 - Hash Table Operations with Chaining, Linear Probing, and Quadratic Probing](#exersize-4---hash-table-operations-with-chaining-linear-probing-and-quadratic-probing)
        - [Exersize 5 - Implement a Set Using a Queue, List, or Stack ADT](#exersize-5---implement-a-set-using-a-queue-list-or-stack-adt)
        - [Exersize 6 - Implement a Dictionary/Map Using STL Vector](#exersize-6---implement-a-dictionarymap-using-stl-vector)
        - [Exersize 7 - Old Exam Question](#exersize-7---old-exam-question)

    - [Recursion and Array Sorting](#recursion-and-array-sorting)
        - [Exercise 1 - Recursive Search and Min/Max Functions](#exercise-1---recursive-search-and-min-max-functions)
        - [Exercise 2 - Triangle Pattern Printer](#exercise-2---triangle-pattern-printer)
        - [Exercise 3 - Booklet Printing Function](#exercise-3---booklet-printing-function)
        - [Exercise 4 - Maze Solver](#exercise-4---maze-solver)
        - [Exercise 5 - Recursive List Search](#exercise-5---recursive-list-search)
        - [Exercise 6 - Selection Sort Algorithm](#exercise-6---selection-sort-algorithm)
        - [Exercise 7 - Counting Sort Algorithm](#exercise-7---counting-sort-algorithm)
        - [Exercise 8 - IntroSort Implementation](#exercise-8---introsort-implementation)

- [How to use this repository](#how-to-use-this-repository)


## Introduction
This repository contains solutions and documentation for exercises from the "Algorithms & Data Structures" course, part of the Software Technology program at Aarhus University. The course, taken in the third semester of the program, covers a range of fundamental topics including programming, complexity analysis, and the implementation of various data structures and algorithms.

In this repository, you'll find my approach to solving different exercises, along with explanations and analyses for each one. The exercises are designed to deepen the understanding of key concepts in algorithms and data structures through practical coding and problem-solving.

The repository is structured to reflect the progression of the course, with updates as new exercises are completed.

## Exersizes
## C++ Basics, Complexity, and ADT
### Exersize 1
Write a program that:

    1. Generates M random integers and stores them in vector.

    2. Generates another N random integers and counts how many of them are already present in the vector, using an iterator.

Estimate the worst-case complexity of the program.

### Exersize 2
What is the time complexity (Big-O) of myMethod?
```cpp
int myMethod(int N)
{
    int x = 0;
    int y = 0;
    for(int i = 0; i <N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N * sqrt(N); k++)
                x++;

    for(int i = 0; i < N * N; i++)
        y++;

    return x + y;
}
```

### Exersize 3
For each of the following four program fragments:

    - Give an analysis of the running time in Big-O notation.

    - Implement the code inside a C function, and give the running time for several values of N.

    - Compare your analysis with the actual running times.

    - Does compiling/running programs with the -O optimization flag change anything in your analysis?

1. program fragment:
```cpp
sum = 0;
for (i = 0; i < n; i++)
    sum++;
```   
2. program fragment:
```cpp
sum = 0;
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        sum++;
```  
3. program fragment:
```cpp
sum = 0;
for (i = 0; i < n; i++)
    for (j = 0; j < n * n; j++)
        sum++;
```
4. program fragment:
```cpp
sum = 0;
for (i = 0; i < n; i++)
    for (j = 0; j < i; j++)
        sum++;
```
### Exersize 4
Write an implementation of the ADT MaxHeap described below. The implementation must be done by using the standard class `vector` from C++. If you need to iterate through the vector, you must use an iterator and its methods and operators `begin()`, `end()`, `++`, and `*`.
```cpp
class MaxHeap
{
    public:
    //is the heap empty?
    virtual bool isEmpty() const = 0;

    //number of elements in the heap
    virtual int size() = 0;

    //number of elements in the heap
    virtual void insert(const int x) = 0;

    //find the maximum element in the heap
    virtual const int findMax() const = 0;

    // delete and return the maximum element of the heap
    virtual int deleteMax() = 0;
};
```
What is the time complexity of the five operations of MaxHeap?  You must argue for your answers

Make a new implementation of the MaxHeap using a `List`. Make sure to use the List interface where possible.

### Exersize 5
Create and implement a C++ class called `Library` that manages books. Each book (which should also be a class) has an identifier (an integer provided when creating the book) and a category (an integer between 0 and 15 inclusive, provided when constructing the book). The `Library` class should allow the following functionalities:

- **Adding new books** to the library.
- **Borrowing books** from the library.
- **Returning borrowed books**.
- **Displaying all available books** and **borrowed books**.
- A function that returns the number of books in a given category.
- When adding a new book, issue a warning (to `std::cout`) if the number of books in any category exceeds twice the average number of books per category, to ensure the user maintains a balanced library.

A main function should test all features of the library. Below is the provided starting point for the code that you can modify to implement this:

```cpp
int main() {
    Library myLibrary;

    // Adding books to the library
    myLibrary.addBook(1, 3); // Book ID: 1, Category: 3
    myLibrary.addBook(2, 7); // Book ID: 2, Category: 7
    myLibrary.addBook(3, 3); // Book ID: 3, Category: 3
    myLibrary.addBook(4, 15); // Book ID: 4, Category: 15
    myLibrary.addBook(5, 3); // Book ID: 5, Category: 3 (Warning should trigger here)
    myLibrary.addBook(6, 0); // Book ID: 6, Category: 0

    // Display all books in the library
    std::cout << "\nAll books in the library:\n";
    myLibrary.displayAllBooks();

    // Display available books in the library
    std::cout << "\nAvailable books in the library:\n";
    myLibrary.displayAvailableBooks();

    // Borrow a book by ID
    std::cout << "\nBorrowing Book ID 2:\n";
    if (myLibrary.borrowBook(2)) {
        std::cout << "Book ID 2 borrowed successfully.\n";
    } else {
        std::cout << "Failed to borrow Book ID 2.\n";
    }

    // Attempt to borrow the same book again
    std::cout << "\nAttempting to borrow Book ID 2 again:\n";
    if (myLibrary.borrowBook(2)) {
        std::cout << "Book ID 2 borrowed successfully.\n";
    } else {
        std::cout << "Failed to borrow Book ID 2.\n";
    }

    // Display borrowed books
    std::cout << "\nBorrowed books in the library:\n";
    myLibrary.displayBorrowedBooks();

    // Return a borrowed book by ID
    std::cout << "\nReturning Book ID 2:\n";
    if (myLibrary.returnBook(2)) {
        std::cout << "Book ID 2 returned successfully.\n";
    } else {
        std::cout << "Failed to return Book ID 2.\n";
    }

    // Display available books after returning a book
    std::cout << "\nAvailable books in the library after returning Book ID 2:\n";
    myLibrary.displayAvailableBooks();

    // Display the number of books in a specific category
    int categoryToCheck = 3;
    std::cout << "\nNumber of books in category " << categoryToCheck << ": "
              << myLibrary.countBooksInCategory(categoryToCheck) << std::endl;

    return 0;
}
```
Justify the choice of the data structures you chose to maintain the books in the library.

Provide the complexity of each operation in the library, and justify.

## Elementary data structures and their processing
### Exersize 1 - List Abstract Data Type and Linked List
Implement the List ADT using a linked list that you implement from scratch. Your linked list should support the following operations:
- Insertion at the beginning, middle (given a position), and end of the list.
- Deletion of an element from the beginning, middle (given a position), and end of the list.
- Check if a given element exists in the list.
- Traverse the list to print all elements.

Additionally, add a function to reverse the list and test it.

### Exersize 2 - Implementing a Stack Using an Array
Implement a stack using an ordinary array. The stack should be initialized with a size parameter that defines the initial size of the stack. The default constructor should create a stack with 100 elements as the initial size. When `push(...)` is called and the stack is full, a new array should be allocated with double the size. The content of the old array should be copied to the new one, and the old array should be deleted. Analyze the running time of the stack operations `push` and `pop` in terms of the number of elements `N` it stores.

### Exersize 3 - Queue Using Stack(s)
Implement a queue using stack(s). The implementation must be a template and use the Stack ADT presented in the course. There is no requirement for the implementation to be efficient, but you cannot use the internal structure of the stack nor an iterator for the stack.

### Exersize 4 - Hash Table Operations with Chaining, Linear Probing, and Quadratic Probing
Let `T` be a hash-table of size 7 with the hash function `h(x) = x mod 7`. Write down the entries of `T` after the keys 5, 28, 19, 15, 20, 33, 12, 17, 33, and 10 have been inserted using:
- Chaining
- Linear probing
- Quadratic probing

Also, calculate the load factor (λ) in the three cases.

### Exersize 5 - Implement a Set Using a Queue, List, or Stack ADT
Implement a Set using either a Queue, List, or Stack ADT as presented in the course. There is no requirement for the implementation to be efficient, but you cannot use the internal structure of the ADT nor an iterator for the ADT.

### Exersize 6 - Implement a Dictionary/Map Using STL Vector
Implement a Dictionary (or Map) using an STL vector. The elements of the vector (for the implementation) must be an STL `pair` representing the (key, value).

### Exersize 7 - Old Exam Question
In this exercise, a hash table is implemented using quadratic probing to resolve collisions. The hash function used is: `h(x) = x mod 11`.

The table is populated with the values 22, 5, 16, and 27, inserted in that order.

#### Task
1. **Verify the Table**:  
   Check that the values 22, 5, 16, and 27 are inserted correctly using the hash function and quadratic probing. Positions 1, 2, 3, 4, 7, 8, and 10 are available for new entries.

2. **Insert Additional Values**:  
   Insert the following values into the table:
   - 1
   - 12
   - Age
   - Student number

#### Procedure
- The hash function `h(x) = x mod 11` determines the initial position of each value.
- If a collision occurs (the position is already occupied), quadratic probing is applied to find the next available position using the formula: `h(x, i) = (h(x) + i^2) mod table size`.

#### Steps to Follow
1. Insert the values 22, 5, 16, and 27, ensuring the correct application of the hash function and quadratic probing.
2. Insert the additional values (1, 12, age, and student number), applying the same logic for handling collisions.
3. After all insertions, verify the final state of the table and explain where each value is placed and why.

## Recursion and Array Sorting
### Exersize 1 - Recursive Search and Min/Max Functions
Implement recursive algorithms that, given an array `A` of `N` elements, will:

* Search for a given element x in A and return true if x is found, otherwise return false.
* Find the maximum and minimum elements in A.

State the time complexity for the worst-case scenario for both parts.

### Exersize 2 - Triangle Pattern Printer
Implement a recursive algorithm `triangle(int m, int n)` that:
* Takes two integer inputs `m` and `n`.
* Prints a triangle pattern of lines using the '*' character. The first line will contain `m` characters, the next line will contain `m+1` characters, and so on, up to a line with `n` characters.
* After reaching `n` characters, the pattern should reverse, going from `n` characters back to `m`.
Example output for `triangle(4, 6)`:
```cpp
****
*****
******
******
*****
****
```

### Exersize 3 - Booklet Printing Function
Many printers allow booklet printing of large documents. When using booklet printing, 4 pages are printed on each sheet of paper so that the output sheets can be folded into a booklet.

Implement a function `bookletPrint(int startPage, int endPage)` that outputs the pages on each sheet. You may assume that the total number of pages is a multiple of four.

Example for `bookletPrint(1, 8)`:
 
```cpp
Sheet 1 contains pages 1, 2, 7, 8
Sheet 2 contains pages 3, 4, 5, 6
```

### Exersize 4 - Maze Solver
Write a recursive algorithm that accepts a `ROWS x COLS` array of characters representing a maze. Each position can contain either an 'X' or a blank space, and one position contains an 'E' marking the exit. Starting at position (1, 1), the algorithm must search for a path to the position marked 'E'. If a path exists, the algorithm should return `true`; otherwise, return `false`.

Example maze input:
```cpp
char maze[ROWS][COLS] = {
  {'X','X','X','X','X'},
  {'X',' ',' ',' ','X'},
  {'X',' ','X',' ','X'},
  {'X',' ','X',' ','X'},
  {'X','E','X','X','X'}
};
```

### Exersize 5 - Recursive List Search
Extend Week 3’s List ADT with a new function `int search(const Object x)` that searches the list for a specific value `x` using recursion. Use the Recursion Recipe to guide you and write down your answers to the four points. Test your implementation.

Note: It may be beneficial to create a recursive helper function that is called from the public search function.

### Exersize 6 - Selection Sort Algorithm
Implement the Selection Sort algorithm, which works by finding the smallest element in the array and swapping it with the element at `A[0]`, then finding the second smallest element and swapping it with `A[1]`, and so on for the first `N-1` elements.

Create a new template implementation of the selection sort algorithm so that it can handle vectors with any generic element type, similar to the provided Insertion Sort code.

Don't forget to test the algorithm thoroughly. Also, provide the best-case and worst-case time complexities for the algorithm.

### Exersize 7 - Counting Sort Algorithm
Implement the Counting Sort algorithm for an array `A` of integers in the range `{0, ..., k}. This algorithm runs in **O(N)** time. Provide an analysis of the space complexity.

### Exersize 8 - IntroSort Implementation
1. Modify the existing `quickSort` implementation into an **IntroSort** algorithm. Introduce a constant `useInsertion` that determines when to use quicksort and when to use insertion sort.

2. Test your implementation using different input sizes. Measure the time used, and experiment with different values of the `useInsertion` constant. Discuss the results and what you conclude.

3. Measure the time for `stlSort.cpp` using the same input as in part 2 and compare the results with your implementation. Discuss the comparison.


## How to use this repository
1. Navigate to the folder corresponding to the desired exersize.
2. Each folder contains:
    - The solution code
    - A brief explanation and analysis in README.md
    - Any additional resources or data files used
3. Clone this repository using:

    git clone https://github.com/Miko58/Algorithms-and-Datatructures.git
