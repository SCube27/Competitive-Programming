#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n) {
    int count(0), element;
    for(int i = 0; i < n; i++) {
        if(count == 0) {
            element = arr[i];
            count = 1;
        }
        else if(arr[i] == element) {
            count++;
        }
        else {
            count--;
        }
    }
    cout << element << endl;
    /* Use this part only if it's said that there might not exist a majority element
    int count1 = 0
    for(int i = 0; i < n; i++) {
        if(arr[i] == element) {
            count1++;
        }
    }
    if(count1 > n/2) cout << element << endl;
    else cout << -1 << endl;
    */

}

int main() {
    int arr[] = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    int n = 16;
    solve(arr, n);
}