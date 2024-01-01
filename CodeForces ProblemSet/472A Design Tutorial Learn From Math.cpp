#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    if(n%2 == 0) {
        cout << 4 << " " << n-4;
    }
    else {
        cout << 9 << " " << n-9;
    }
}


int main() {
    solve();
}


// Since its given n is greater than or equal to 12 so the greatest even and odd composites before 12 are 4 & 9 resp
// If n is even then return 4 and n-4
// If n is odd then return 9 and n-9