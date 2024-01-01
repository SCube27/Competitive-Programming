#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int arr[1001]; // Create array of 1001 to store positions from 1 to 1000
    int j(1);
    for(int i = 1; i <= 1666; i++) { // Traverse from 1 to 1666 to store all numbers polycarp likes
        if(i%3 != 0) {
            if(i%10 != 3) { // Those numbers that satisfy both conditions are liked numbers
                arr[j] = i; // Store the liked nummber(i) at position(j) in the array
                j++; // Increment j to store next liked number
            }
        }
    }

    int t;
    cin >> t;
    int k;
    while(t--) {
        cin >> k;
        cout << arr[k] << endl; // When asked number at kth position directly take it out from array and print it
    }
}

int main() {
    solve();
}

// Since we are given value of k will be till 1000 and in test case its given the position of 1000 is 1666
// So we create an array to store numbers for all position from 1 to 1000  
// We iterate from 1 to 1666 to store every number for every position from 1 to 1000
/* 
1  2  4  5  7  8  10  11  14  1666  <- i (number which isnt divisible by 3 and doesnt have 3 as last digit)
1  2  3  4  5  6  7   8   9   1000  <- j (position)

*/