#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(n log n + m log m) predominantly because of sorting operations
// Space Complexity = O(log m + log n)  as the sorting operations take log m and log n stack space

class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // code here
        sort(cookie.begin(), cookie.end());
        sort(greed.begin(), greed.end());
        int n = greed.size();
        int m = cookie.size();
        int l = 0, r= 0;
        int cnt = 0;
        while(l<m and r<n){
            if(greed[r]<=cookie[l]){
                r++;
                cnt++;
            }
            l++;
        }
        return cnt;
    }
};