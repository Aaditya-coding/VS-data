#include<bits/stdc++.h>
using namespace std;
// Time Complexity = O(n)
// Space Complexity = O(n)
class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        
        stack<int> st;
        
        for (int x : arr) {
            
            while (!st.empty() && st.top() * x < 0) {
                
                if (abs(st.top()) < abs(x)) {
                    st.pop();
                }
                else if (abs(st.top()) > abs(x)) {
                    x = st.top();
                    st.pop();
                }
                else {
                    st.pop();
                    x = 0;
                    break;
                }
            }
            
            if (x != 0)
                st.push(x);
        }
        
        vector<int> ans;
        
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};