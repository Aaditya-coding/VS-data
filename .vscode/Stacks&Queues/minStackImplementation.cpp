#include<bits/stdc++.h>
using namespace std;
// Time Complexity = O(1)
// Space Complexity = O(N)
class MinStack{
    stack<int>st;
    int min;

    void push(int val){
        if(st.empty()){
            min = val;
            st.push(val);
        }
        else{
            if(val>min) st.push(val)
            else{
                st.push(2*val-min);
                min = val;
            }
        }

    }

    void pop(){
        if(st.empty()) return;
        else{
            int n = st.top();
            st.pop();
            if(n<min) min = 2*min - n;
        }
    }

    void top(){
        if(st.empty()) return;
        int n = st.top()
        if(min<n) return n;
        return min;
    }

    getMin(){
        return min;
    }
}