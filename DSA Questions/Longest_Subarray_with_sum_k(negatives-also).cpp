#include<bits\stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum(0), maxlen(0);
    map<int, int> mp; // Creating a presum map
    for(int i = 0; i < n; i++) {
        sum+=arr[i]; // Keep adding the elements to sum

        if(sum == k) { // If sum is equal to k update the maxlen
            maxlen = max(maxlen, i+1); 
        }

        int rem = sum - k; // Otherwise takeout the remainder 
        if(mp.find(rem) != mp.end()) { // If the remainder is present in map
            int len = i - mp[rem]; // Calulate the length of remainder
            maxlen = max(maxlen, len); // update maxlen with rem's len
        }

        if(mp.find(sum) == mp.end()) { // If sum not found in map
            mp[sum] = i; // Add the sum to map with its index i
        }
    }
    cout << maxlen << endl;
}

int main() {
    solve();
}