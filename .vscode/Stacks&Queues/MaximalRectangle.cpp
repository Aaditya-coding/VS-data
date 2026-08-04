#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(m x n) + O(n x 2m)
// Space Complexity = O(n x m) + O(n)

class Solution {
  public:
  int lHist(vector<int>& heights) {

    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {

        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {

            int height = heights[st.top()];
            st.pop();

            int right = i;
            int left = st.empty() ? -1 : st.top();

            int width = right - left - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }

    return maxArea;
}
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int maxArea = 0;
        vector<vector<int>> pSum(n, vector<int>(m,0));
        for(int j=0; j<m; j++){
            int sum = 0;
            for(int i=0; i<n; i++){
                if(mat[i][j]==0) sum = 0;
                else sum++;
                pSum[i][j] = sum;
            }
        }
        
        for(int i=0; i<n; i++){
            maxArea = max(maxArea, lHist(pSum[i]));
        }
        return maxArea;
    }
};