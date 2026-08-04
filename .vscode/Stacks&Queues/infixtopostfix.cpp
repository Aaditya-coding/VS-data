#include<bits/stdc++.h>
using namespace std;
// Time Complexity = O(N) + O(N)
// Space Complexity = O(N) 
class Solution{
    public:
    int priority(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' or ch=='/') return 2;
        else if(ch=='+' or ch=='-') return 1;
        else return -1;
    }

    string infixToPostfix(string &s){
        int n = s.length();
        if(n==0) return "";
        stack<char>st;
        string ans="";
        int i=0;
        while(i<n){
            if((s[i]>='A' and s[i]<='Z')or(s[i]>='a' and s[i]<='z')or(s[i]>='0' and s[i]<='9')) ans+=s[i];
            else if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                while(!st.empty() and st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while (!st.empty() && (priority(s[i]) < priority(st.top()) || (priority(s[i]) == priority(st.top()) && s[i] != '^'))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};