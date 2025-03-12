#include<bits/stdc++.h>
using namespace std;

/**
 * Can Place Flowers
    You have a long flowerbed in which some of the plots are planted, and some are not. 
    However, flowers cannot be planted in adjacent plots.

    Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
    and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 * Example 1:
    Input: flowerbed = [1,0,0,0,1], n = 1
    Output: true
    Example 2:
    Input: flowerbed = [1,0,0,0,1], n = 2
    Output: false

 * Constraints:
    1 <= flowerbed.length <= 2 * 104
    flowerbed[i] is 0 or 1.
    There are no two adjacent flowers in flowerbed.
    0 <= n <= flowerbed.length
 */

// Good Solution
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            bool left = i == 0 || flowerbed[i - 1] == 0;
            bool right = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
            
            if (left && right && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;        
    }
};

// My Solution
    bool canPlaceFlower(vector<int>& flowerbed, int n) {
        int k=flowerbed.size();
        if(k==0 && n==0) return true;
        if(k==0 && n!=0) return false;
        if(k==1) {
            if(flowerbed[0]==0) return true;
            if(flowerbed[0]==1 && n==0) return true;
            return false;
        }
        if(k==2) {
            if(flowerbed[0]==0 && flowerbed[1]==0 && n==1) return true;
            if((flowerbed[0]==1 || flowerbed[1]==1) && n==0) return true;
            return false;
        }
            for(int i=0; i<k; i++) {
                if(flowerbed[i]==0) {
                    if(i==0 && flowerbed[1]==0) {
                        n--;
                        flowerbed[0]=1;
                    } 
                    if(i!=0 && i==(k-1) && flowerbed[k-2]==0) {
                        n--;
                        flowerbed[k-1]=1;
                    }
                    if(i!=0 && i!=(k-1) && flowerbed[i-1]==0 && flowerbed[i+1]==0) {
                        n--;
                        flowerbed[i]=1;
                    }
                }
            }
            if(n<=0) return true;
        return false;
    }

    int main() {
        vector<int> flowerbed={0}; 
        int n=0;
        canPlaceFlower(flowerbed, n);
        return 0;
    }