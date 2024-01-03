#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, x;
    cin >> n;
    vector<int> math, prog, pe;
    for(int i = 1; i <= n; i++) {
        cin >> x;

        if(x == 1) prog.push_back(i);
        if(x == 2) math.push_back(i);
        if(x == 3) pe.push_back(i);
    }

    int ans = min(prog.size(), min(math.size(), pe.size()));
    cout << ans << endl;
    for(int i = 0; i < ans; i++) {
        cout << prog[i] << " " << math[i] << " " << pe[i] << endl;
    }
}

int main() {
    solve();
}

// The solution basically reseides on point that the skill having the least amount of student is the maximum number of groups formed.
// we just take in the position of students in the vector of their skill (line 12 13 14)
// take the skill with min number of student (line 17)
// return the max groups (line 18) and students on that particular team (line 20)