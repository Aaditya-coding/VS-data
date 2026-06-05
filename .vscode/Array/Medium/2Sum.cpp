#include <bits/stdc++.h>
using namespace std;
//Brute Force Solution
//Time Complexity = O(n^2).
//Space Complexity = O(1).
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]+arr[j]==target) 
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//Better Solution.
//Use map and map.find()--> if an item is not found then it will return map.end().
//Time Complexity = O(nlogn)[when map is used], O(n)[when unordered map is used O(n^2) in worst cases]
//Space Complexity = O(n).
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        map<int,int> mpp; 
        for(int i=0;i<n;i++)
        {
            int a = arr[i];
            int more = target - a;
            if(mpp.find(more)!=mpp.end())
            return true;
            mpp[a] = i;   // Enter your elements into the map also, so that mpp.find() can return a value.
        }
        return false;
    }
};

