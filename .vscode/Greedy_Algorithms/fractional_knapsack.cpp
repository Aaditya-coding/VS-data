#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(n log n)
// Space Complexity = O(n)

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double, int>> items;
        int n = val.size();
        for(int i = 0; i<n; i++){
            items.push_back({(double)val[i]/wt[i], i});
        }
        
        sort(items.begin(),items.end(),
            [](pair<double, int>&a, pair<double, int>&b){
                return a.first>b.first;
            });
        
        double totVal = 0;
        int W = capacity;
        
        for(int i = 0; i<n ; i++){
            int idx = items[i].second;
            if(wt[idx]<=W){
                totVal += val[idx];
                W = W - wt[idx];
            }
            else{
                totVal += items[i].first * W;
                break;
            }
        }
        return totVal;
    }
};
