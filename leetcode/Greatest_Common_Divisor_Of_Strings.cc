#include<bits/stdc++.h>
using namespace std;

/**
    1071. Greatest Common Divisor of Strings
    For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t 
    (i.e., t is concatenated with itself one or more times).

    Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

    Example 1:
        Input: str1 = "ABCABC", str2 = "ABC"
        Output: "ABC"
    Example 2:
        Input: str1 = "ABABAB", str2 = "ABAB"
        Output: "AB"
    Example 3:
        Input: str1 = "LEET", str2 = "CODE"
        Output: ""

    Constraints:
        1 <= str1.length, str2.length <= 1000
        str1 and str2 consist of English uppercase letters.
*/

// Good Solution
    string gcdOfStrings(string str1, string str2) {
        //checking if the str1+str2 is equal to str2+str1 or not
        //if not then gcd cannnot be find of such strings
        if(str1+str2 != str2+str1) return "";
        // else we have to find the gcd .... gcd will always start from the starting
        // the length of the gcd of the substring is equal to gcd of str1's length and str2's length
        return str1.substr(0,gcd(str1.length(),str2.length()));
    }

// My Solution
class Solution {
public:
    bool checkp(string &x, string &p) {
        for(int i=0; i<p.size(); i++) {
            if(p[i] != x[i%(x.size())]) return false;
        }
        if(p.size()%x.size()==0) return true;
        return false;
    }
    string gcdOfString(string &str1, string &str2) {
        int i=0, n=str1.size(), m=str2.size();
        string x;
        if(n<=m) {
            x=str1;
            i=n;
            bool t=checkp(x, str2);
            if(t) {
                return x;
            } else {
                i--;
                while(i--) {
                    x.pop_back();
                    t = checkp(x, str1) && checkp(x, str2);
                    if(t) {
                        return x;
                    }
                }
                return "";
            }
        } else {
            return gcdOfString(str2, str1);
        }
    }
};


int main() {
    string str1 = "aa";
    string str2 = "ab";
    cout << Solution().gcdOfString(str1, str2);
}