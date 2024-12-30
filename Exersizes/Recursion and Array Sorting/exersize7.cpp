#include <iostream>
#include <vector> // For dynamic arrays
#include <algorithm> // For max_element

void countSort(int arr[], int n) {
    if (n == 0) return; // Handle empty array

    // Find the maximum element in the array
    int k = *std::max_element(arr, arr + n);

    // Create a count array dynamically and initialize to 0
    std::vector<int> count(k + 1, 0);

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Perform prefix sum to determine positions
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array to store sorted elements
    std::vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int A[] = {0,5,3,4,1,2,3,4,2,1,5,3,2,3,4};
    int size = sizeof(A) / sizeof(*A);
    countSort(A, size);

    // displaying the result
    std::cout << "Array after performing count sort : " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << A[i] << " ";
    }
    return 0;
}