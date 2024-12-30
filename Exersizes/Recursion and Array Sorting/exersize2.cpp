#include <iostream>

void triangle(int m, int n) {
    std::string stuff(m, '*');

    if (m > n) return; // BC

    std::cout << stuff << std::endl;
    triangle(m + 1, n);
    std::cout << stuff << std::endl;
}

int main() {
    triangle(4,6);

    return 0;
}