#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n) {
    int maxSum = INT_MIN;
    int sum = 0; 

    for(int i = 0; i < n; i++) {
        sum+=arr[i];

        if(sum > maxSum) {
            maxSum = sum;
        }

        if(sum < 0) {
            sum = 0;
        }
    }
    cout << maxSum << endl; 
}

int main() {
    int arr[] = {2, -1, -2, 4, 3, -2, 1, -3};
    int n = 8;
    solve(arr, n);    
}