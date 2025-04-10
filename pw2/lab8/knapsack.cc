#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Course {
    int id, credit, benefit;
    double ratio;
};

bool compare(Course a, Course b) {
    return a.ratio > b.ratio;
}

void knapsack(int n, vector<int>& L, vector<int>& C, int b) {
    vector<Course> courses;
    for (int i = 0; i < n; i++) {
        courses.push_back({i + 1, C[i], L[i], (double)L[i] / C[i]});
    }
    
    sort(courses.begin(), courses.end(), compare);
    
    vector<int> selected(n, 0);
    int totalBenefit = 0, totalCredits = 0;
    
    for (auto& course : courses) {
        if (totalCredits + course.credit <= b) {
            selected[course.id - 1] = 1;
            totalCredits += course.credit;
            totalBenefit += course.benefit;
        }
    }
    
    cout << "Optimal Course Selection: ";
    for (int i = 0; i < n; i++) {
        if (selected[i]) cout << "x" << i + 1 << " = 1, ";
    }
    cout << "\nTotal Learning Benefit: " << totalBenefit << endl;
}

int main() {
    int n = 4, b = 6;
    vector<int> L = {85, 90, 80, 70};
    vector<int> C = {3, 4, 2, 1};
    
    knapsack(n, L, C, b);
    return 0;
}
