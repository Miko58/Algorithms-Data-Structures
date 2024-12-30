#include <iostream>
#include <vector>

// Swap function for arrays
void swap(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}

// Array-based Selection Sort
void selectionSort(int *arr, int n) {
    int currentMin;
    for (int i = 0; i < n - 1; i++) {
        currentMin = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[currentMin]) {
                currentMin = j;
            }
        }
        swap(&arr[currentMin], &arr[i]);
    }
}

// Print function for arrays
void printArray(int* arr, int size) {
    for (int i{}; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Generic swap for vectors
template<typename T>
void swapV(T &left, T &right) {
    T temp = left;
    left = right;
    right = temp;
}

// Template-based Selection Sort for vectors
template<typename T>
void selectionSort(std::vector<T> &arr) {
    int currentMin;
    for (int i = 0; i < arr.size() - 1; i++) {
        currentMin = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[currentMin]) {
                currentMin = j;
            }
        }
        swapV(arr[currentMin], arr[i]);
    }
}

// Template-based print for vectors
template<typename T>
void printVector(const std::vector<T> &arr) {
    for (const T &item : arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test array-based implementation
    int array[] = {3, 6, 4, 1, 7, 9, 2, 4, 8};
    int arraySize = sizeof(array) / sizeof(*array);

    std::cout << "Array unsorted: ";
    printArray(array, arraySize);

    selectionSort(array, arraySize);

    std::cout << "Array sorted: ";
    printArray(array, arraySize);

    // Test vector-based implementation
    std::vector<int> sort = {5, 6, 2, 7, 8, 2, 2, 4, 6};

    std::cout << "Vector unsorted: ";
    printVector(sort);

    selectionSort(sort);

    std::cout << "Vector sorted: ";
    printVector(sort);

    return 0;
}


// Both the best case and worst case time complexity of selection sort is O(n^2)
// Because it runs through all of the elements for every single element