#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[6]; // Since the limit of n is 10^4
        int total(0); // total -> stores all round numbers in n
        for(int i = 1; i < 6; i++) {
            arr[i] = n%10; // inserting every digit of n in arr
            n = n/10;
            if(arr[i] != 0) {
                total++; // 9876 -> 4
            }
        }
        cout << total << endl;

        int m(1); // m -> multiples of 10, prints values of all place value
        for(int i = 1; i < 6; i++) {
            if(arr[i] != 0) {
                cout << arr[i]*m << " "; // 9876 -> 9000 800 70 6
            }
            m*=10;
        }
        cout << endl;
    }
}

int main() {
    solve();
}

// For the first loop we basically checked all the non zero values and added up them to total as they are round values and inserted them to arr

// For second loop we printed all the values in arr in expanded form