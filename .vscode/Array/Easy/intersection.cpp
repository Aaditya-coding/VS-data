//Optimal Solution
//Time Complexity = O(n1+n2)
//Space Complexity = O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int i=0,j=0;
        int n1 = arr1.size(), n2 = arr2.size();
        set<int>st;
        while(i<n1 and j<n2)
        {
            if((arr1[i]) == arr2[j])
            {
               st.insert(arr1[i]); 
               i++;
               j++;
            }
            else if(arr1[i]<arr2[j]) i++;
            else if(arr2[j]<arr1[i]) j++;
        }
        vector <int> res(st.begin(),st.end());
        return res;
    }
};

