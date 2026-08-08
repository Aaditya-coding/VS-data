#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(2N)
// Space Complexity = O(1)

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {

        int n = mat.size();

        int top = 0;
        int down = n - 1;

        while(top < down){
            if(mat[top][down] == 1)
                top++;
            else
                down--;
        }

        int candidate = top;

        for(int i = 0; i < n; i++){

            if(i == candidate)
                continue;

            if(mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }

        return candidate;
    }
};