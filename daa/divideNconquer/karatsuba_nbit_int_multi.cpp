#include<bits/stdc++.h>
using namespace std;

/***
 * @problem: Multiply two n-bit integers using Karatsuba's algorithm
 * @pseudo_code:
 * 1. Divide the integers into two halves
 * 2. Recursively multiply the two halves
 * 3. Compute the product using the 3 products
 * 
 * @time_complexity: O(n^1.59)
 * @space_complexity: O(n)
 */

int makeEqualLength(string &X, string &Y) {
    int n1 = X.length();
    int n2 = Y.length();
    if(n1 < n2) {
        for(int i=0; i<n2-n1; i++) {
            X = '0' + X;
        }
        return n2;
    } else {
        for(int i=0; i<n1-n2; i++) {
            Y = '0' + Y;
        }
        return n1;
    }
}

string add(string X, string Y) {
    int n = makeEqualLength(X, Y);
    int carry = 0;
    string result = "";
    for(int i=n-1; i>=0; i--) {
        int sum = (X[i]-'0') + (Y[i]-'0') + carry;
        result = to_string(sum%10) + result;
        carry = sum/10;
    }
    if(carry) {
        result = to_string(carry) + result;
    }
    return result;
}

string subtract(string X, string Y) {
    int n = makeEqualLength(X, Y);
    string result = "";
    for(int i=n-1; i>=0; i--) {
        int diff = (X[i]-'0') - (Y[i]-'0');
        if(diff < 0) {
            X[i-1] = X[i-1] - 1;
            diff += 10;
        }
        result = to_string(diff) + result;
    }
    return result;
}

string multiply(string X, string Y) {
    int n = makeEqualLength(X, Y);
    if(n == 0) return "0";
    if(n == 1) return to_string((X[0]-'0') * (Y[0]-'0'));
    int fh = n/2;
    int sh = n - fh;
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);
    string P1 = multiply(Xl, Yl);
    string P2 = multiply(Xr, Yr);
    string P3 = multiply(add(Xl, Xr), add(Yl, Yr));
    string P4 = subtract(subtract(P3, P1), P2);
    for(int i=0; i<2*sh; i++) {
        P1 += '0';
    }
    for(int i=0; i<sh; i++) {
        P4 += '0';
    }
    return add(add(P1, P2), P4);
}

int main() {
    string X = "1100";
    string Y = "1010";
    cout << "Multiply: " << multiply(X, Y) << endl;
    cout << "Add: " << add(X, Y) << endl;
    cout << "Subtract: " << subtract(X, Y) << endl;
    return 0;
}