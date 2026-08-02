#include<bits/stdc++.h>
using namespace std;
// Time Complexity = O(4N)
// Space Complexity = O(2N) + O(N)
class Solution{
    public:
    vector<int> nextGreater(vector<int> &arr){
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() and st.top() <= arr[i%n]) st.pop();
            if(i<n){
                if(st.empty()) nge[i] = -1;
                else nge[i] = st.top();
            }
            st.push(arr[i%n]);
        }
        return nge;
    }
};