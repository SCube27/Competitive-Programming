#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr+n);
        bool istrue = true;
        for(int j = n-1; j > 0; j--) {
            if(arr[j] - arr[j-1] > 1) {
                istrue = false;
                break;
            }
        }
        if(istrue) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return;
}

int main() {
    solve();
}

// Take all the elements
// Insert in an array and sort them
// Keep a flag to check while evaluating condition
// Reverse loop and check the difference of current and previous index value (if > 1 then flag false else remains true)
// after rev loop check the flag if true then YES, if false then NO