#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(n log n)
// Space Complexity = O(n)

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = deadline.size();

        vector<pair<int,int>> jobs;

        for(int i = 0; i < n; i++)
            jobs.push_back({profit[i], deadline[i]});

        // Highest profit first
        sort(jobs.begin(), jobs.end(),
            [](pair<int,int>& a, pair<int,int>& b) {
                return a.first > b.first;
            });

        int maxD = *max_element(deadline.begin(), deadline.end());

        vector<int> parent(maxD + 1);

        for(int i = 0; i <= maxD; i++)
            parent[i] = i;

        function<int(int)> find = [&](int x) {
            if(parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        int cnt = 0;
        int totalProfit = 0;

        for(auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            int slot = find(d);

            if(slot > 0) {
                cnt++;
                totalProfit += p;

                // Slot is now occupied
                parent[slot] = find(slot - 1);
            }
        }

        return {cnt, totalProfit};
    }
};