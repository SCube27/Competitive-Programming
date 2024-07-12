#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int preSum = 0;

        unordered_map<int, int> map;
        map[0] = 0; // to start registering the mods from 1
        for(int i = 0; i < n; i++) {
            preSum += nums[i];
            int mod = preSum%k;

            if(map.find(mod) != map.end()) { // if present in map then find len
                if(i+1 - map[mod] >= 2) { // if length is greater than 2
                    return true;
                }
            }
            else { // if not present then store in map
                map[mod] = i+1;
            }
        }
        return false;
    }
};