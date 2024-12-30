#include <iostream>

bool search(int *arr, int x, int n) {
    if (n == 1) return x == arr[n - 1]; // BC
    if (x != arr[n - 1]) return search(arr, x, n - 1); // RC
    
    return x == arr[n - 1]; // true if x is inside, false if not
}

int main() {
    int array[] = {1,2,3,4,5,6,7,8,9};
    int arraySize = sizeof(array) / sizeof(array[0]);

    std::cout << search(array, 1, arraySize);

    return 0;
}