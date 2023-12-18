#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int match(0);
    vector<int> h(n), a(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i] >> a[i];

        for(int j = 0; j < i; j++) {
            if(h[i] == a[j]) {
                match+=1;
            }
            if(a[i] == h[j]) {
                match+=1;
            }
        }
    }
    cout << match << endl;
}

int main() {
    solve();
}

// The basic idea is that store all the jerseys color(number) in home(h) & away(a) vector
// If any color is equal to current home jersey from away then its a 'match' same is vice versa