#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve() {
    int t;
    cin >> t;
    while(t--) {
        int x, y, n;
        cin >> x >> y >> n;
        int max(0);
 
        int res = n/x; // line 29
        if(x*res+y <= n) { // Line 30
            cout << x*res+y << endl;
        }
        else {
            res--; // Line 31
            cout << x*res+y << endl;
        }
    }
}
 
int main() {
    solve();
}
// Since k%x = y; (As k < n)
// We can also say x*(any number from 1 to n/x) + y = k 
// We go till n/x only because if we multiply x with number beyond n/x it will exceed "n" and "k < n" so we go till n/x
// This also means n/x might be the highest possible number before n to satisfy above equations
// If n/x doesnt satisfy then the number will be the one before n/x