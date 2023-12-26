#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int arr[4];
    int max = INT_MIN;
    for(int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+4);

    for(int i = 0; i < 3; i++) {
        int ans = arr[3] - arr[i];
        cout << ans << " ";
    }
}

int main() {
    solve();
}

// The basic idea is that the greatest number will surely be the addition of all three numbers.
// Hence we sort the array so the greatest number will be a last 
// We gradually subtract each value from the greatest value to get all three values.
// Eg 3 6 5 4 -> (after sorting) 3 4 5 6
// Subrtract all values from 6 so
// 6 - 3 -> 3
// 6 - 4 -> 2
// 6 - 5 -> 1
// So the answer will be 3 2 1 in any order.