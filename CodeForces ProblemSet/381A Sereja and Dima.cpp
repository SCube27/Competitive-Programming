#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int arr[n+2]; // Using a n+2 array so we can start from 1st index
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int left(1), right(n), serya(0), dima(0), i(1); // Using an i counter to keep the track of even and odd inexes
    while(left <= right) { // Using 2 pointer left -> 1 and right -> n
        if(i%2 == 1) { // If odd then assign to serya
            if(arr[left] >= arr[right]) { // If left > right then add up left
                serya += arr[left];
                left++;
            }
            else { // Else add up right 
                serya += arr[right];
                right--;
            }
        }
        else if(i%2 == 0) { // Else if value is even assign to dima
            if(arr[left] >= arr[right]) {
                dima += arr[left];
                left++;
            }
            else {
                dima += arr[right];
                right--;
            }
        }
        i++; // After every value comparison and assignment increase i value
    }
    cout << serya << " " << dima << endl;
}

int main() {
    solve();
}