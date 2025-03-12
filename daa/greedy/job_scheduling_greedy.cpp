#include<bits/stdc++.h>
using namespace std;

/***
 * Greedy Job Scheduling
 *
 * @problem:
 *    Given a set of n jobs where each job has a start time, end time, and profit, we need to find the maximum profit that can be earned by selecting a subset of jobs such that no two jobs overlap.
 * 
 * @pseudo_code:
 *   1. Sort the jobs based on the end time.
 *   2. Create a dp array of size n and initialize it with the profit of each job.
 *   3. For each job, find the maximum profit that can be earned by selecting the job or not selecting the job.
 *   4. Repeat step 3 until all jobs are processed.
 * 
 * @time_complexity:
 *  O(nlogn) where n is the number of jobs.
 */

struct Job {
    int start, end, profit;

    Job(int start, int end, int profit)
    : start(start), end(end), profit(profit) {}
};

bool compare(Job &a, Job &b) {
    return a.end < b.end;
}

int maxProfit(vector<Job> &jobs) {
    if (jobs.empty()) return 0;

    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    vector<int> dp(n);
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++) {
        int profit = jobs[i].profit;
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid].end <= jobs[i].start) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (high != -1) {
            profit += dp[high];
        }
        dp[i] = max(profit, dp[i - 1]);
    }
    return dp[n - 1];
}

int main() {
    vector<Job> jobs = {{1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
    cout << "Maximum profit that can be earned: " << maxProfit(jobs) << endl;
    return 0;
}