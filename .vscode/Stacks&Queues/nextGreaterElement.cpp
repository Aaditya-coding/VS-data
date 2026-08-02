#include<bits/stdc++.h>
using namespace std;
// Time Complexity = O(2N)
// Space Complexity = O(N) + O(N)
class Solution{
    public:
    vector<int> nextLargerElement(vector<int>&arr){
        int n = arr.size();
        stack<int>st;
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top()<=arr[i]) st.pop();
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
            st.push(arr[i]);
        }
        return nge;
    }
};