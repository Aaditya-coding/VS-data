#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n,1);
        
        stack<int> st;
        st.push(0);
        
        for(int i=1; i<n; i++){
            while(!st.empty() and arr[st.top()]<=arr[i]){
                st.pop();
            }
            
            if(st.empty()) ans[i] = i + 1;
            else ans[i] = i - st.top();
            st.push(i);
        }
        return ans;
    }
};