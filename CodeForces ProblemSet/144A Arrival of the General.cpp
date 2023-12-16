#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    int maxi = 0, mini = 110; // to store max and min element
    int pos1(0), pos2(0); // to store position of max and min element
    cin >> n;    
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        if(a > maxi) { // getting the max value and its index
            maxi = a;
            pos1 = i;
        }
        if(a <= mini) { // getting the min value and its index
            mini = a;
            pos2 = i;
        }
    }

    if(pos1 > pos2) { // if position of max index is greater than min index then subtract an extra 1 as they both exchange at a point
        cout << (pos1 - 1) + (n - pos2) - 1 << endl;
    }
    else { // if max position is smaller than min position then use normal formula
        cout << (pos1 - 1) + (n - pos2) << endl;
    }
}

int main() {
    solve();
}