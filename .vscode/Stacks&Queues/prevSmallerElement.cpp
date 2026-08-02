#include<bits/stdc++.h>
using namespace std;
// Time Complexity = O(2N)
// Space Complexity = O(N) + O(N)
class Solution{
    public:
    vector<int> prevSmaller(vector<int> &arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top()>=arr[i]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(arr[i]);
        }
        return pse;
    }
};