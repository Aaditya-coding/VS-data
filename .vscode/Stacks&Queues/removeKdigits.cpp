#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(3N) + O(k)
// Space Complexity = O(N) + O(N)

class Solution{
    public:
        string removeKdig(string &s, int k){
            int n = s.length();
            string ans = "";
            stack<char> st;
            
            for(int i=0;i<n;i++){
                while(!st.empty() and k>0 and (st.top()-'0')>(s[i]-'0')){
                    st.pop();
                    k--;
                }
                st.push(s[i]);
            }

            while(k>0 and !st.empty()){
                st.pop();
                k--;
            }

            while(!st.empty()){
                ans += st.top();
                st.pop();
            }

            reverse(ans.begin(),ans.end());

            int i=0;
            int m = ans.length();
            while(i<m and ans[i]=='0'){
                i++;
            }

            ans.erase(0,i);

            if(ans.empty()) return "0";
            return ans;
        }
};