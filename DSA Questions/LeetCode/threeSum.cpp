#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // optimal approach
    vector<vector<int>> threeSumOptimal(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) { // keeping i constant and implementing two pointer on remaining further part
            if(i > 0 && nums[i] == nums[i-1]) continue; // making sure value of i is not the same otherwise skip the below part

            // two pointer starts
            int j = i+1;
            int k = nums.size()-1;
            while(j < k) { 
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++; // making sure j isnt the same
                    while(j < k && nums[k] == nums[k+1]) k--; // making sure k isnt the same
                }
            }
        }
        return ans;
    }

    // better approach
    vector<vector<int>> threeSumBetter(vector<int>& nums) {
        set<vector<int>> st; // kept a set of vectors for distinct triplets

        for(int i = 0; i < nums.size(); i++) {
            // kept a set for registering distinct elements
            set<int> hashSet; // for every iteration of i we take a new set

            for(int j = i+1; j < nums.size(); j++) {
                int third = -(nums[i] + nums[j]); // calculate the third element

                if(hashSet.find(third) != hashSet.end()) { // find third element in the hash set
                    // if found then form a new list and store in set of lists
                    vector<int> temp = {nums[i], nums[j], third}; 
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]); // if not found then store the current j in set for next iterations
            }
        } 
        vector<vector<int>> ans(st.begin(), st.end()); // finally store the set of vectors in vcetor of vectors
        return ans;
    }
};
