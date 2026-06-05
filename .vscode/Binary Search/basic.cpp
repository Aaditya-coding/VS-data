#include <bits/stdc++.h>
using namespace std;
//Iterative Approach
//Time Complexity = O(log n)
class Solution {
    public:
      int binarysearch(vector<int> &arr, int k) {
          int n = arr.size();
          int low = 0;
          int high = n-1;
          int ans = -1;
          while(low<=high)
          {
            int mid = (low+high)/2; // declare the low and high as long long to avoid overflow
            // use mid = low + (high-low)/2; if you don't want to declare long long.
            if(arr[mid] == k) 
            {
                ans = mid;
                high = mid-1;
            }
            else if(arr[mid]<k) low = mid+1;
            else high = mid-1;
          }
          return ans;
      }
};
//Recursive Approach
//Time Complexity = O(log2(n))
class Solution {
  public:
    int bs(vector<int> &arr, int low, int high, int target)
    {
        int mid = (low+high)/2;
        int ans = -1;
        if(low>high) return ans;
        else
        {
        if(arr[mid]==target)
        {
            int left = bs(arr,low,mid-1,target);
            if(left!=-1) return left;
            return mid;
        }
        else if(arr[mid]<target) return bs(arr,mid+1,high,target);
        else return bs(arr,low,mid-1,target);
        return ans;
        }
    }
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int res = bs(arr,0,n-1,k);
        return res;
    }
};

