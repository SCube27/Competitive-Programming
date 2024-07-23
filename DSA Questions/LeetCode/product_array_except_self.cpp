#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC -> O(3n)  SC -> O(2n)
    vector<int> productExceptSelfBetter(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1);

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }

    // TC -> O(2n)  SC -> O(1)
    vector<int> productExceptSelfOptimal(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // calculating the prefix product in ans itself to save space
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        int pr = 1;
        for(int i = n-2; i >= 0; i--) {
            pr *= nums[i+1]; // computing the suffix product 
            ans[i] *= pr; // immediately multiplying it to ans
        }

        return ans;
    }
};