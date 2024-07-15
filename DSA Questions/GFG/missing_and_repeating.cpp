#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // optimal
    vector<int> findTwoElementOptimal(vector<int> arr, int n) {
        long long Sn = (n*(n+1))/2;
        long long Sn2 = (n * (n+1) * (2*n+1))/6;
        
        long long S = 0;
        long long S2 = 0;
        for(int i = 0; i < n; i++) {
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i];
        }
        
        long long val1 = S-Sn; // x - y
        long long val2 = S2-Sn2; // x2 - y2
        val2 = val2/val1; // x + y
        
        long long repeating = (val1+val2)/2; // x
        long long missing = repeating - val1; // y
        
        return {(int)repeating, (int)missing};
    }

    // better
    vector<int> findTwoElementBetter(vector<int> arr, int n) {
        int hash[n+1] = {0};
        for(int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }

        int missing = -1;
        int repeating = -1;
        for(int i = 1; i <= n; i++) {
            if(hash[i] == 0) missing = i;
            else if(hash[i] == 2) repeating = i;

            if(repeating != -1 && missing != -1) break;
        }

        return {repeating, missing};
    }
};

// Optimal Approach
// 1. Simply used the x+y & x-y equations method
// 2. Sn represents the sum of all numbers from 1 to n and Sn2 represents the sum of squares
// 3. S represents the sum of all values of array and S2 represents the sum of squares of all array values
// 4. x-y is given by val1
// 5. x2-y2 is initially given by val2
// 6. Now since x2-y2 -> (x+y)(x-y) so this also gives us val2 
// 7. So x+y(val2) = val2 / (x-y)
// 8. Since x-y is val1 hence x+y(val2) = val2 / val1 hence val2 = val2/val1
// 9. From here you can get x & y with x -> repeating value and y -> missing value