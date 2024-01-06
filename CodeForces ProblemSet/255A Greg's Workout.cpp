#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, a;
    cin >> n;
    int ch(0), bi(0), ba(0);
    string curr = "chest";
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(curr == "chest") {
            ch += a;
            curr = "biceps"; 
        }
        else if(curr == "biceps") {
            bi += a;
            curr = "back";
        }
        else {
            ba += a;
            curr = "chest";
        }
    }
    if(ch > bi && ch > ba) cout << "chest" << endl;
    else if(bi > ch && bi > ba) cout << "biceps" << endl;
    else if(ba > ch && ba > bi) cout << "back" << endl;
}

int main() {
    solve();
}

// kept a counter string with value as chest (as the first day is always going to be a chest day)
// so when there's a chest day we add up the exercises to ch and update counter string with biceps
// when there's biceps we add up exercises to biceps and update counter to back 
// similarly on back day add up exercises and update counter again to chest as the workouts go in cyclic manner