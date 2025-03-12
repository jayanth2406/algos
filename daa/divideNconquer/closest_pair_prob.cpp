#include <bits/stdc++.h>
using namespace std;

/***
 * @problem: Find the closest pair of points in a plane
 * @pseudo_code:
 * 1. Sort the points according to their x-coordinates
 * 2. Recursively find the closest pair of points in the left and right halves
 * 3. Find the closest pair of points in the strip of width 2d around the middle point
 * 4. Return the closest pair of points
 * 
 * @time_complexity: O(nlogn)
 * @space_complexity: O(n)
 */

struct Point {
    int x, y;
};

bool compareX(Point &a, Point &b) {
    return a.x < b.x;
}

bool compareY(Point &a, Point &b) {
    return a.y < b.y;
}

float dist(Point &a, Point &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

float bruteForce(vector<Point> &points, int l, int r) {
    float minDist = FLT_MAX;
    for(int i=l; i<=r; i++) {
        for(int j=i+1; j<=r; j++) {
            minDist = min(minDist, dist(points[i], points[j]));
        }
    }
    return minDist;
}

float stripClosest(vector<Point> &strip, float d) {
    float minDist = d;
    sort(strip.begin(), strip.end(), compareY);
    for(int i=0; i<strip.size(); i++) {
        for(int j=i+1; j<strip.size() && strip[j].y-strip[i].y < minDist; j++) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}

float closestUtil(vector<Point> &points, int l, int r) {
    if(r-l <= 3) return bruteForce(points, l, r);
    int mid = l + (r-l)/2;
    Point midPoint = points[mid];
    float dl = closestUtil(points, l, mid);
    float dr = closestUtil(points, mid+1, r);
    float d = min(dl, dr);
    vector<Point> strip;
    for(int i=l; i<=r; i++) {
        if(abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }
    return min(d, stripClosest(strip, d));
}

float closest(vector<Point> &points) {
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, 0, points.size()-1);
}

int main() {
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    cout << closest(points) << endl;
    return 0;
}
