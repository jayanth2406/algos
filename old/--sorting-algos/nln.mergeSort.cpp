#include <iostream>
using namespace std;

/*
    Merge Sort: 
        - Merge Sort is a Divide and Conquer algorithm
        - It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves
        - The merge() function is used for merging two halves
        - The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one
        - Time Complexity: 
            - Worst Case: O(nlogn)
            - Best Case: O(nlogn)
            - Average Case: O(nlogn)
        - Space Complexity: O(n)
        - In Place: No
        - Stable: Yes
        - Advantages: 
            - Merge Sort is useful for sorting linked lists
            - Merge Sort is a stable sort
            - Merge Sort is used in external sorting
            - Merge Sort is used in sorting huge files
            - Merge Sort is used in inversion count problem
            - Merge Sort is used in external merge sort
            - Merge Sort is used in count inversions in an array
            - Merge Sort is used in external sorting
            - Merge Sort is used in count inversions in an array
            - Merge Sort is used in external sorting
            - Merge Sort is used in count inversions in an array
            - Merge Sort is used in external sorting
            - Merge Sort is used in count inversions in an array
            - Merge Sort is used in external sorting
            - Merge Sort is used in count inversions in an array
            - Merge Sort is used in external sorting
            - Merge Sort is used in count inversions in an array
            - Merge Sort is used in external sorting
        - Disadvantages: 
            - Merge Sort is not an in-place sort
        - Applications:
            
*/

void merge(int arr[], int l, int m, int r) {
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i]; 
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j]; 
    }

    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; 
            i++; 
        } else {
            arr[k] = R[j]; 
            j++; 
        }
        k++; 
    }

    while (i < n1) {
        arr[k] = L[i]; 
        i++; 
        k++; 
    }

    while (j < n2) {
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) {
        return; 
    }

    int m = l + (r - l) / 2; 
    mergeSort(arr, l, m); 
    mergeSort(arr, m + 1, r); 
    merge(arr, l, m, r); 
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i]; 
    }
    cout << endl; 
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    mergeSort(arr, 0, n - 1); 
    printArray(arr, n); 

    return 0; 
}