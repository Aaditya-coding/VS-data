#include<bits/stdc++.h>
using namespace std;
// Time Complexity = O(n)  [Can't be improved further]
// Space Complexity = O(n) [Can't be improved further] 

class Solution{
    public:
    bool isBalanced(string &s){
    int n = s.length();
    if(n==0) return true;
    stack<char> st;
    for(int i=0; i<n; i++){
        if((s[i]=='(')or(s[i]=='{')or(s[i]=='[')) st.push(s[i]);
        else{
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if((ch=='(' and s[i]==')')or(ch=='{' and s[i]=='}')or(ch=='[' and s[i]==']')) continue;
            else return false;
        }
    }
    return st.empty();
}
};