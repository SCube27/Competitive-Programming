#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n; 
    int nums[n];
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_set<int> st; // Using unordered set as it stores only distinct values
    for(int i = 0; i < n; i++) { // Inserting values in set
        st.insert(nums[i]);
    }

    int ans(0);
    for(auto it : st) {
        // If a previous element is present for current element, then the current elment is not the start of its sequence
        if(st.find(it-1) == st.end()) { // But if no previous element then assign count as 1 and start finding next elements 
            int count = 1;
            int x = it;
            while(st.find(x+1) != st.end()) { // If next element present
                count++; // Increment count
                x++; // Increment checker variable for finding next element in sequence
            }
            ans = max(ans, count); // update ans after every sequence found
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
}