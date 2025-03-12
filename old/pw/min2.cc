#include<bits/stdc++.h>
using namespace std;

/*
PW-5:1. Given two numbers, num1, and num2, represented by linked lists. The task is to return the head of the linked list that represents the sum of these two numbers.
For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.
Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.
Examples:
Input: num1 = 45 (4->5->null), num2 = 345 (3->4->5->null)
Output:  3->9->0->null
Explanation:
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Input: num1 = 0063 (0->0->6->3->null), num2 = 07 (0->7->null)
Output: 7->0->null
Explanation:
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
*/
struct LL {
    int v;
    LL* n;
    LL(int v):v(v), n(nullptr) {}
};
void printLL(LL* head) {
    while(head != nullptr) {
        cout << head->v << " ";
        head = head->n;
    }
    cout << endl;
}
LL* revLL(LL* head) {
    if (head == nullptr || head->n == nullptr) return head;
    LL* newHead = revLL(head->n);
    head->n->n = head;
    head->n = nullptr;
    return newHead;
}
LL* addLL(LL* ra, LL* rb) {
    LL* dummy = new LL(0);  // Dummy node to simplify adding new nodes
    LL* current = dummy;    // Pointer to build the new list
    int carry = 0;
    while (ra != nullptr || rb != nullptr || carry != 0) {
        int sum = carry;
        if (ra != nullptr) {
            sum += ra->v;
            ra = ra->n;
        }
        if (rb != nullptr) {
            sum += rb->v;
            rb = rb->n;
        }
        carry = sum / 10;
        current->n = new LL(sum % 10);  // Create new node for the sum
        current = current->n;
    }
    LL* result = dummy->n;  // Get the actual head of the result list
    delete dummy;  // Delete the dummy node to avoid memory leaks
    return result;
}
void addTwoLL() {
    LL* a = new LL(1);
    a->n = new LL(6);
    LL* b = new LL(3);
    b->n = new LL(4);
    b->n->n = new LL(5);

    LL* ra = revLL(a);
    LL* rb = revLL(b);

    LL* sum = addLL(ra, rb);
    LL* rsum = revLL(sum);
    printLL(rsum);
}
/*
PW-5:2. Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:
Input: head = [1], n = 1
Output: []
Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/
void rmvNthNodell(){

}
/*
PW-5:3. You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
Example 1:
Input: head = [1,2,3,4,5],  
k= 2
Output: [1,4,3,2,5]
Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
*/
void kswapll(){

}

/*
PW-6:1. Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.  
You must write an algorithm with O (log n) runtime complexity.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/
void binInsertSearch(){
    vector<int> a = {1,3,5,6};
    int n=a.size();
    int k = 5;

    int hi = n-1, lo=0;
    while(lo<=hi) {
        int mid = lo + (hi-lo)/2;
        if(a[mid] == k) {
            cout << mid << endl;
            return;
        }
        else if(a[mid] < k) lo = mid+1;
        else hi = mid-1;
    }
    cout << lo << endl;
    return;
}
/*
PW-6:2. A company wants to implement a system that can store and manage employee records. Each employee has basic details such as their name, employee ID, and salary. Additionally, each employee's address consists of an area name, street number, and house number. The HR team needs a feature in the system to search and display the names and IDs of employees living in a particular area for administrative purposes or targeted communication.
Design a program that accepts employee details (name, employee ID, salary, and address) and allows the HR department to input an area name. The program should display the names and IDs of all employees living in that specified area.
Time complexity: O(n)
Input:
Enter the number of employees: 3
Enter the name of employee 1: jack
Enter the employee id of employee 1: 110
Enter the salary of employee 1: 1000
Enter the area of employee 1: ameerpet
Enter the street no of employee 1: 23
Enter the house number of employee1 : 15
Enter the name of employee 2: jill
Enter the employee id of employee 2: 112
Enter the salary of employee 2: 2300
Enter the area of employee 2: kukatpally
Enter the street no of employee 2: 23
Enter the house number of employee 2 : 11
Enter the name of employee 3: jim
Enter the employee id of employee 3: 512
Enter the salary of employee 2: 3000
Enter the area of employee 3: ameerpet
Enter the street no of employee 3: 21
Enter the house number of employee3 : 12
Enter the area to find the employees belong to that area:Ameerpet
Output:
Name:jack
Empid: 110
Name:jim
Empid: 512
*/
void empl() {

}
/*
PW-6:3. We are given two arrays that represent the arrival and departure times of trains, the task is to find the minimum number of platforms required so that no train waits.
Examples:
Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}, dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}  
Output: 3  
Explanation: There are at-most three trains at a time (time between 9:40 to 12:00)
Input: arr[] = {9:00, 9:40}, dep[] = {9:10, 12:00}  
Output: 1  
Explanation: Only one platform is needed.
Expected Time Complexity: O (N log N) 
*/
void minPlatform() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int p=0;
    for(int i=1; i<arr.size(); i++) {
        if(arr[i] <= dep[i-1]) p++;
    }
    cout << p << endl;
}
/*
PW-7:1. Minimum Swaps to Sort Binary Array
You are given a binary array (an array that contains only 0s and 1s). You need to sort the 
array such that all the 0s appear before all the 1s. The only operation allowed is to swap 
adjacent elements. You must determine the minimum number of adjacent swaps
required to achieve the sorted array.
Key Insight:
We need to minimize the number of adjacent 0s and 1s that are out of order, i.e., 
minimize the "crossings" of 0s and 1s.
Example:
Input:
Enter binary array: 0 1 0 1 1 0
Output:
Minimum swaps required: 4
Input:
Enter binary array: 1 0 1 0 1 0
Minimum swaps required: 6
Approach:
Identify all 0s and 1s positions:
For every 0 in the array, if it appears after a 1, it will need to be moved to the left, which 
results in a swap with the adjacent 1s until all 0s are on the left side.
Strategy:
Track the positions of all 0s in the array.
For each 0, compute how many 1s are present to its left, as these 1s must be swapped 
with the 0 to move it to the left.
The total number of swaps will be the sum of all such necessary swaps for all 0s.
*/
void swap0n1() {
    vector<int> a = {1, 0, 0, 1, 0, 1};
    int n=a.size();
    int swapCnt=0;
    int zsCnt = count(a.begin(), a.end(), 0);
    stack<int> zPos;
    for(int i=0; i<n; i++) {
        if(a[i]==0) {
            zPos.push(i);
        }
    }
    for(int i=0; i<zsCnt; i++) {
        int oCnt=0;
        int cz = zPos.top();
        for(int j=0; j<cz; j++) {
            if(a[j] == 1) oCnt++;
        }
        zPos.pop();
        swapCnt+=oCnt;
    }
    for (int x : a) cout << x << " ";
    cout << endl << swapCnt << endl;
}
/*
PW-7:2. Optimized Search in a Sorted 2D Matrix
You are given an m x n matrix where each row is sorted in ascending order and each 
column is sorted in ascending order. Write an efficient algorithm to search for a target 
value. The algorithm should run in O (m + n) time.
Key Concept: Start searching from the top-right corner of the matrix
Hint: If the target is smaller than the current element, move left. If the target is larger, 
move down. Continue adjusting the search space accordingly.
Trickiness: Balancing both row-wise and column-wise sorted properties to narrow down 
the search space effectively.
Test case1:
Input:
Enter matrix dimensions (rows and columns): 3 4
Enter matrix row-wise:
1 4 7 11
2 5 8 12
3 6 9 16
Enter target value: 5
Output: Target found
Test case2:
Input:
Enter matrix dimensions (rows and columns): 3 3
Enter matrix row-wise:
1 2 3
4 5 6
7 8 9
Enter target value: 10
Output: Target not found.
*/
void matrixSearch() {
    vector<vector<int>> a = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16}
    };
    int n = a.size();
    int m = a[0].size();
    int k = 8;

    int r=0, c=m-1;
    while(r < n && c >=0) {
        if(a[r][c] == k) {cout << "Found at:("<<r<<","<<c<<").\n"; return;}
        else if(a[r][c] > k) c--;
        else r++;
    }

    cout << "Not found" << endl;
    return;
}
/*
PW-7:3. Given an integer array nums, return the maximum difference between two successive 
elements in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses extra linear space.
Example 1:
Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the 
maximum difference 3.
Example 2
Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0
*/
void maxDiffSorted() {
    vector<int> a = {3, 6, 1, 9};
    int n = a.size();
    int hi=INT_MIN, lo=INT_MAX;
    for(int x:a) {
        hi = max(hi, x);
        lo = min(lo, x);
    }
    if(n<2 || hi==lo) {
        cout << "0"<<endl;
        return;
    }
    
    int bs = min(1, (hi-lo)/n-1);
    int bc = (hi-lo)/bs+1;
    vector<pair<int, int>> b(bc, {INT_MAX, INT_MIN});
    for(int x :a){
        int in = (x - lo)/bs;
        b[in].first = min(b[in].first, x);
        b[in].second = max(b[in].second, x);
    }
    int mg =0, pre=INT_MAX;
    for(auto p : b) {
        if(p.first > p.second) continue;
        mg = max(mg, p.first - pre);
        pre = p.second;
    }
    cout << mg << endl;
}



int main() {
    cout << "-------- PW-5:1 --------" << endl;
    addTwoLL();
    cout << "-------- PW-5:2 --------" << endl;
    rmvNthNodell();
    cout << "-------- PW-5:3 --------" << endl;
    kswapll();
    cout << "-------- PW-6:1 --------" << endl;
    binInsertSearch();
    cout << "-------- PW-6:2 --------" << endl;
    empl();
    cout << "-------- PW-6:3 --------" << endl;
    minPlatform();
    cout << "-------- PW-7:1 --------" << endl;
    swap0n1();
    cout << "-------- PW-7:2 --------" << endl;
    matrixSearch();
    cout << "-------- PW-7:3 --------" << endl;
    maxDiffSorted();
    return 0;
}
