#include <bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    priority_queue<int> pq;
    int n = heights.size();
    int i;
    for (i = 0; i < n - 1; i++)
    {
        int diff = heights[i + 1] - heights[i];
        if (diff > 0)
        {
            if (bricks >= diff)
            {
                bricks -= diff;
                pq.push(diff);
            }
            else if (ladders > 0)
            {
                if (!pq.empty() && pq.top() > diff)
                {
                    int top = pq.top();
                    bricks += top - diff;
                    pq.pop();
                    pq.push(diff);
                    ladders--;
                }
                else
                {
                    ladders--;
                }
            }
            else
            {
                break;
            }
        }
    }
    return i;
}

int main()
{
    vector<int> ht = {4,2,7,6,9,14,12};
    int brick=5, lddr=1;
}