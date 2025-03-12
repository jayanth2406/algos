#include <iostream>
using namespace std;

/*
    Insertion Sort: 
        - Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands
        - Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list
        - At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there
        - It repeats until no input elements remain
        - Sorting is typically done in-place, by iterating up the array, growing the sorted list behind it
        - At each array-position, it checks the value there against the largest value in the sorted list (which happens to be next to it, in the previous array-position checked)
        - If larger, it leaves the element in place and moves to the next
        - If smaller, it finds the correct position within the sorted list, shifts all the larger values up to make a space, and inserts into that correct position
        - The resulting array after k iterations has the property where the first k + 1 entries are sorted ("+1" because the first entry is skipped)
        - In each iteration the first remaining entry of the input is removed, and inserted into the result at the correct position, thus extending the result
        - The algorithm is typically implemented when sorting a small number of elements
        - It can also be useful when memory usage is important, as it requires only a constant amount O(1) of additional memory space
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

void insertionSort(int arr[], int n) {
    int i, key, j; 
    for (i = 1; i < n; i++) {
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        }
        arr[j + 1] = key; 
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

int main() {
    int arr[] = {12, 11, 13, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    insertionSort(arr, n); 
    printArray(arr, n); 

    return 0; 
}