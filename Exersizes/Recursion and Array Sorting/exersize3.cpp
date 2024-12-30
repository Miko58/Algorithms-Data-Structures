#include <iostream>

void bookletPrint(int startPage, int endPage) {
    static int sheet = 1;
    
    if (endPage - startPage < 1) return; // BC

    std::cout << "Sheet " << sheet++ << " contains pages ";
    std::cout << startPage <<  ", " << startPage + 1 << ", ";
    std::cout << endPage - 1 <<  ", " << endPage << std::endl;

    bookletPrint(startPage + 2, endPage - 2); 
}

int main() {
    bookletPrint(1, 9);
}