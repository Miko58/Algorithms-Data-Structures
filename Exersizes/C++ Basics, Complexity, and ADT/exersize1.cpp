#include <iostream>
#include <vector>
#include <ctime> // For seeding rand()

int main()
{
    std::srand(std::time(0)); // Seed for random number generation
    std::vector<int> vectorM(10);
    std::vector<int> vectorN(10); 

    for(int& M : vectorM)
        M = 1 + rand() % 10;
    
    std::cout << "Vector with M integers:\n";
    for(int M : vectorM)
        std::cout << M << " ";
    
    for(int &N : vectorN)
        N = 1 + rand() % 10;
    
    std::cout << "\nVector with N integers:\n";
    for(int N : vectorN)
        std::cout << N << " ";

    std::cout << "\nThe amount of N integers inside the vector with M integers: ";
    int count = 0;
    for(int M : vectorM)
        for(int N : vectorN)
            if(N == M)
                count++;

    std::cout << count;

    return 0;
}

/*
The estimated worst-case time complexity of this program is O(n^2).
This is because there is a nested loop structure, where for each 
element in vectorM, the program iterates through all elements in vectorN. 
Since the other loops iterate only once through the vectors, 
their contributions to the overall time complexity are negligible.
*/