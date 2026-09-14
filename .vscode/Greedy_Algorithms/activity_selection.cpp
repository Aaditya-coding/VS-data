#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(n log n)
// Space Complexity = O(n)

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<pair<int, int>> meetings;
        
        for(int i=0;i<n;i++){
            meetings.push_back({finish[i],start[i]});
        }
        
        sort(meetings.begin(),meetings.end());
        
        int cnt = 0;
        int lastEnd = -1;
        
        for(int i = 0; i < n; i++) {
                   if(meetings[i].second > lastEnd) {
                       cnt++;
                       lastEnd = meetings[i].first;
                   }
               }

        return cnt;
    }
};