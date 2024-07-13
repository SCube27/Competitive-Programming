#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // optimal approach
    vector<vector<int>> mergeOptimal(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end()); // sorting the intervals so nearer ones come closer for merge

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            if(ans.empty() || intervals[i][0] > ans.back()[1]) { // if ans is empty or current start is greater than previously stored then simply store current interval as its not mergeable
                ans.push_back(intervals[i]);
            }
            else { // if previously stored ones' end is greater than current ones' start then update the previous ones' end with max of previous and current ones' ends 
                ans.back()[1] = max(ans.back()[1], intervals[i][1]); 
            }
        }
        return ans;
    }

    // better approach
    vector<vector<int>> mergeBrute(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!ans.empty() && end <= ans.back()[1]) {
                continue;
            } 
            for(int j = i+1; j < n; j++) {
                if(intervals[j][0] <= end) {
                    end = max(intervals[j][1], end);
                }
                else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};