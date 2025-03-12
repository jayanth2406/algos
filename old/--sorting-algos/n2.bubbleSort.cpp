#include <iostream>
using namespace std;

/*
    Bubble Sort: 
        - Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order
        - Example: 
            First Pass: 
                (5 1 4 2 8) -> (1 5 4 2 8), Here, algorithm compares the first two elements, and swaps since 5 > 1
                (1 5 4 2 8) -> (1 4 5 2 8), Swap since 5 > 4
                (1 4 5 2 8) -> (1 4 2 5 8), Swap since 5 > 2
                (1 4 2 5 8) -> (1 4 2 5 8), Now, since these elements are already in order (8 > 5), algorithm does not swap them
            Second Pass: 
                (1 4 2 5 8) -> (1 4 2 5 8)
                (1 4 2 5 8) -> (1 2 4 5 8), Swap since 4 > 2
                (1 2 4 5 8) -> (1 2 4 5 8)
                (1 2 4 5 8) -> (1 2 4 5 8)
            Now, the array is already sorted, but our algorithm does not know if it is completed
            The algorithm needs one whole pass without any swap to know it is sorted
            Third Pass: 
                (1 2 4 5 8) -> (1 2 4 5 8)
                (1 2 4 5 8) -> (1 2 4 5 8)
                (1 2 4 5 8) -> (1 2 4 5 8)
                (1 2 4 5 8) -> (1 2 4 5 8)
        - Time Complexity: 
            - Worst Case: O(n^2)
            - Best Case: O(n)
            - Average Case: O(n^2)
        - Space Complexity: O(1)
        - In Place: Yes
        - Stable: Yes
        - Advantages: 
            - Simple implementation
            - Efficient for (quite) small data sets, much like other quadratic sorting algorithms
            - More efficient in practice than most other simple quadratic (i.e., O(n^2)) algorithms such as selection sort or bubble sort
            - Adaptive, i.e., efficient for data sets that are already substantially sorted: the time complexity is O(nk) when each element in the input is no more than k places away from its sorted position
            - Stable; i.e., does not change the relative order of elements with equal keys
            - In-place; i.e., only requires a constant amount O(1) of additional memory space
            - Online; i.e., can sort a list as it receives it
        - Disadvantages:
            - More complex than bubble sort or selection sort
            - Slower than shell sort or merge sort
            - Not suitable for large data sets
        - Applications:
            - Insertion sort is used when number of elements is small
            - It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array
            - In these cases insertion sort performs better than merge sort and heap sort
            - Insertion sort is preferred for sorting small arrays
            - This algorithm is used in the library’s sort function if the number of elements is small
            - It can also be useful when memory write is a costly operation
            - Insertion sort is used in Hybrid sort which combines different sorting algorithms to improve performance
            - Insertion sort is used in TimSort, an algorithm used in Python’s sorted function and implementations of Java’s Arrays.sort() and GNU C++’s std::sort
            - Insertion sort is used when number of elements is small
            - It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array
            - In these cases insertion sort performs better than merge sort and heap sort
            - Insertion sort is preferred for sorting small arrays
            - This algorithm is used in the library’s sort function if the number of elements is small
            - It can also be useful when memory write is a costly operation
            - Insertion sort is used in Hybrid sort which combines different sorting algorithms to improve performance
            - Insertion sort is used in TimSort, an algorithm used in Python’s sorted function and implementations of Java’s Arrays.sort() and GNU C++’s std::sort
*/

// void swap(int *a, int *b) {
//     int temp = *a; 
//     *a = *b; 
//     *b = temp; 
// }

void bubbleSort(int arr[], int n) {
    int i, j; 
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); 
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    bubbleSort(arr, n); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
}
