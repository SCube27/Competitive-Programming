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
        int evn(0), odd(0);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];

            if(i%2 && arr[i]%2 == 0) {
                evn++;
            }
            else if (i%2 == 0 && arr[i]%2) { 
                odd++;
            }
        }
        if(evn == odd) {
            cout << evn << endl;
        }
        else {
            cout << -1 << endl;
        }
    
    }
}

int main() {
    solve();
}

/*
if(i % 2 && arr[i] % 2 == 0): Checks if the current index is odd (i % 2) and the element is even (arr[i] % 2 == 0). If so, increments "evn".

else if(i % 2 == 0 && arr[i] % 2): Checks if the current index is even and the element is odd. If so, increments "odd".
*/

/*
if evn and odd values match then either return evn or odd
else return -1
*/