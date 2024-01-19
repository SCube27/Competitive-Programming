#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n); // Sort the array first for linear comparison
    int ans = 0;
    int count = 0; // stores count
    int x = INT_MIN; // checker variable

    for(int i = 0; i < n; i++) {
        // Check 1
        if(arr[i]-1 == x) { // If current value-1 == x then its next element in the sequence and hence update count++ and x to current value
            count++;
            x = arr[i];
        }

        // Check 2 : If current value is equal to x then ignore

        // Check 3 
        else if(arr[i] != x) { // If current value != x then its a new sequence and hence update count to 1 and x to current value
            count = 1;
            x = arr[i];
        }
        ans = max(ans, count); // Update ans after every check
    }
    cout << ans << endl;
}

int main() {
    solve();
}