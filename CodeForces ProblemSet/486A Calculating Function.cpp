#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, a;
    cin >> n;
    if(n % 2 == 0) a = n / 2;
    else a = -(n + 1) / 2;
    cout << a << endl;
}

int main() {
    solve();
}

// Identify the pattern in the mathematical functions don't just go on applying brute force everywhere