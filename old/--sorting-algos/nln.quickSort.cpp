#include <iostream>
using namespace std;

/*
    Quick Sort: 
        - Divide and Conquer algorithm
        - Picks an element as pivot and partitions the given array around the picked pivot
        - There are many different versions of quickSort that pick pivot in different ways
        - Always pick first element as pivot
        - Always pick last element as pivot (implemented below)
        - Pick a random element as pivot
        - Pick median as pivot
        - The key process in quickSort is partition()
        - Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x
        - All this should be done in linear time
        - Partition algorithm:
            - There can be many ways to do partition, following pseudo code adopts the method given in CLRS book
            - The logic is simple, we start from the leftmost element and keep track of index of smaller (or equal to) elements as i
            - While traversing, if we find a smaller element, we swap current element with arr[i]
            - Otherwise we ignore current element
        - Time Complexity: 
            - Worst Case: O(n^2)
            - Best Case: O(nlogn)
            - Average Case: O(nlogn)
        - Space Complexity: O(1)
        - In Place: Yes
        - Stable: No
        - Advantages: 
            - Quicksort is an in-place sorting algorithm
            - Quicksort is a cache-friendly sorting algorithm as it has good locality of reference when used for arrays
            - Quicksort is also a tail recursive algorithm
        - Disadvantages: 
            - Quicksort is highly recursive and uses a stack
            - Quicksort is not a stable sorting algorithm
            - Quicksort doesn’t guarantee nlogn performance, worst case is O(n^2)
            - Quicksort is not adaptive
            - Quicksort doesn’t require any extra storage
            - Quicksort is preferred over mergeSort for sorting arrays because of in-place sorting and low auxiliary space
            - Quicksort is preferred over heapSort for sorting objects because of in-place sorting
        - Applications: 
            - Quicksort is preferred for arrays
            - MergeSort is preferred for linked lists
            - Quicksort is a cache-friendly algorithm as it has good locality of reference when used for arrays
            - Quicksort is tail recursive
            - Quicksort is used in CPU scheduling, Java’s Arrays.sort() method uses quicksort
            - Quicksort is used in many, many library sort routines
            - Quicksort is often faster in practice than other O(nlogn) algorithms
            - Quicksort can be implemented in different ways by changing the choice of pivot, so that the worst case rarely occurs for a given type of data
            - Quicksort is an in-place algorithm which means it doesn’t require any extra storage to sort the elements of the array
             
*/ 

// void swap(int *a, int *b) {
//     int temp = *a; 
//     *a = *b; 
//     *b = temp; 
// }

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quickSort(arr, 0, n - 1); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
}