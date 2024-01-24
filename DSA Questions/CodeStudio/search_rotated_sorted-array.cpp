#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans(-1);
    int s = 0, e = n-1;
    while(s<=e) {
        int mid = s + (e-s)/2;
        if(arr[mid] == x) { // If mid found return its index
            cout << mid;
            return;
        } 
        else if(arr[s] <= arr[mid]) { // If mid is in left half
            // Check if target is present in this left half
            if(arr[s] <= x && x <= arr[mid]) { // If present then eliminate right half
                e = mid - 1;
            }
            else { // If not present then eliminate this left half
                s = mid + 1;
            } 
        }
        else { // Else mid is in right half
            // Check if target is present in this right half
            if(arr[mid] <= x && x <= arr[e]) { // If present then eliminate the left half
                s = mid + 1;
            }
            else { // If not present then eliminate this right half 
                e = mid - 1;
            }
        }   
    }
    cout << -1; // After BS if not found then return -1
    return;
}

int main() {
    solve();
}

// Two step process in BS
// Calculate mid then
// Step 1 : Check if mid is in left or right half
// Step 2 : For each half mid is present in check if the target too is in that half :
    // a) If present then eliminate other half
    // b) If not eliminate this half