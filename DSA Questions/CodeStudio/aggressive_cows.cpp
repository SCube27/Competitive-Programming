#include<bits/stdc++.h>
using namespace std;

int maximum(vector<int>& arr) {
    int maxi = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

bool cowsPlaced(vector<int>& arr, int mid, int k) {
    int prev_cow = arr[0];
    int rem_cows = k-1;

    for(int i = 1; i < arr.size(); i++) {
        if(arr[i]-prev_cow >= mid) {
            prev_cow = arr[i];
            rem_cows -= 1;
            if(rem_cows == 0) return true;
        }
    }
    return false;
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int s = 1, e = maximum(arr);

        while(s <= e) {
            int mid = s+(e-s)/2;
            bool isPossible = cowsPlaced(arr, mid, c);

            if(isPossible) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        cout << e;
    }
}

int main() {
    solve();
}