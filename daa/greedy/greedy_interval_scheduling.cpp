#include <bits/stdc++.h>
using namespace std;

/***
 * Greedy Interval Scheduling
 *
 * @problem:
 *     Given a set of requests, each request has a starting and finishing time, 
 *     We need to find the optimized subset of non-overlapping intervals that can be selected.
 *
 * @pseudo_code:
 *  1. Sort the intervals based on their finishing time.
 *  2. Select the first interval and set its finishing time as the end.
 *  3. For each interval, if the starting time is greater than or equal to the end, then select the interval and update the end.
 *  4. Repeat step 3 until all intervals are processed.
 *
 * @time_complexity:
 *  O(nlogn) where n is the number of intervals.
 */

struct Interval {
    int start, finish;
};

bool compare(Interval a, Interval b) {
    return a.finish < b.finish;
}

void intervalScheduling(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), compare);
    
    int n = intervals.size();
    int end = intervals[0].finish;
    cout << "Selected Intervals: ";
    cout << "[" << intervals[0].start << ", " << intervals[0].finish << "] ";
    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= end) {
            cout << "[" << intervals[i].start << ", " << intervals[i].finish << "] ";
            end = intervals[i].finish;
        }
    }
}

int main() {
    vector<Interval> intervals = {{1, 3}, {2, 5}, {3, 8}, {4, 7}, {5, 9}, {6, 10}, {7, 11}, {8, 12}};
    intervalScheduling(intervals);
    return 0;
}
