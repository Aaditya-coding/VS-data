#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        // concept of slope - Optimal approach
        int sum = 1, i = 1;
        int n = arr.size();
        while(i<n){
            if(arr[i]==arr[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n and arr[i]>arr[i-1]){
                peak+=1;
                sum+=peak;
                i++;
            }
            int down = 1;
            while(i<n and arr[i]<arr[i-1]){
                sum+=down;
                i++;
                down++;
            }
            if(down>peak) sum+= down-peak;
        }
        return sum;
    }
};
