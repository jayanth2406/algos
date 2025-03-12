#include <iostream>
using namespace std;

/*
    Selection Sort: 
        - The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning
        - The algorithm maintains two subarrays in a given array
        - 1) The subarray which is already sorted
        - 2) Remaining subarray which is unsorted
        - In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray
        - Time Complexity: 
            - Worst Case: O(n^2)
            - Best Case: O(n^2)
            - Average Case: O(n^2)
        - Space Complexity: O(1)
        - In Place: Yes
        - Stable: No
        - Advantages: 
            - The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation
        - Disadvantages: 
            - The main disadvantage of selection sort is its poor efficiency when dealing with a huge list of items
            - Selection sort is inefficient to operate on a large list
        - Applications:
            - Selection sort is used when:
                - The list is considerably small
                - Cost of swapping does not matter
                - Checking of all the elements is compulsory
            - Selection sort is used in the following scenarios:
                - In a music player, the playlist is sorted on the basis of the name of the song, or the time when it was added
                - In an online multiplayer game, the players are sorted in the order of decreasing scores
                - In an online shopping website, the products are usually sorted on the basis of their prices
                - In a library, the books are sorted according to their accession numbers
                - In a school, students are sorted on the basis of their roll numbers
                - In a classroom, students are sorted on the basis of their heights
*/

void selectionSort(int arr[], int n) {
    int i, j, min_idx; 

    for (i = 0; i < n - 1; i++) {
        min_idx = i; 
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; 
            }
        }
        swap(arr[min_idx], arr[i]); 
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl; 
}

int main() {
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    selectionSort(arr, n); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
}