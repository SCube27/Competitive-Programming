#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    while(n--) {
        long long int a, b;
        cin >> a >> b;
        if(a%b == 0) {
            cout << 0 << endl;
        }
        else {
            int rem = a % b;
            cout << b-rem << endl;
        }
    }
}
// The basic idea is mod b from a and then subtract remainder from b to get the answer
// eg 10 % 4 = 2 now 4 - 2 = 2 <- this is the answer since if we add 2 to 10 it becomes 12 and 12 % 4 = 0

int main() {
    solve();
}