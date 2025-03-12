#include <iostream>
using namespace std;

/*
    Heap Sort: 
        - Heap sort is a comparison based sorting technique based on Binary Heap data structure
        - It is similar to selection sort where we first find the maximum element and place the maximum element at the end
        - We repeat the same process for remaining element
        - Heap sort algorithm can be divided into two parts:
            - Create a Heap of the unsorted list/array
            - Then a sorted array is created by repeatedly removing the largest/smallest element from the heap, and inserting it into the array
        - Time Complexity: 
            - Worst Case: O(nlogn)
            - Best Case: O(nlogn)
            - Average Case: O(nlogn)
        - Space Complexity: O(1)
        - In Place: Yes
        - Stable: No
        - Advantages: 
            - Efficient
            - Sorting in Place: No need for extra space
            - As Heap Sort requires a binary heap, it has a space complexity of O(1)
            - Heap Sort is very fast
            - Heap Sort is an in-place algorithm
            - Heap Sort is not a stable sort
            - Heap Sort is useful when we want to remove the object with the highest (or lowest) priority
            - Heap Sort is used in priority queues
        - Disadvantages: 
            - Heap Sort is not a stable sort
            - Heap Sort is useful when we want to remove the object with the highest (or lowest) priority
            - Heap Sort is used in priority queues
        - Applications:
            - Heap Sort is used in priority queues
            - Heap Sort is used in graph algorithms
            - Heap Sort is used in many algorithms as intermediate step
            - Heap Sort is used in sorting in parallel computing and supercomputers
            - Heap Sort is used in operating systems
            - Heap Sort is used in the Java library
            - Heap Sort is used in the C++ library
            - Heap Sort is used in the Python library
            - Heap Sort is used in the GNU C library
*/

// void swap(int *a, int *b) {
//     int temp = *a; 
//     *a = *b; 
//     *b = temp; 
// }

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl; 
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    heapSort(arr, n); 
    printArray(arr, n); 

    return 0; 
}