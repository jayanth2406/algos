#include <bits/stdc++.h>
using namespace std;

string tolwrNoPnc(string s)
{
    string k;
    for (auto x : s)
    {
        if (x == '.' || ',' || '!' || '?')
            continue;
        if (x >= 'A' && x <= 'Z')
        {
            k += x - ('A' - 'a');
        }
        else
        {
            k += x;
        }
    }
    return k;
}

int main()
{
    string s = "This is a test. This test is only a test.";
    int n = s.size();
    unordered_map<string, int> f;
    stringstream ss(s);
    string w;
    while (ss >> w)
    {
        w = tolwrNoPnc(w);
        f[w]++;
    }
    for (auto x : f)
    {
        if (x.second > 1)
            cout << "('" << x.first << "', " << x.second << ")" << endl;
    }
}