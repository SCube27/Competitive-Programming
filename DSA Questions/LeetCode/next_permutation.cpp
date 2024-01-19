#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Step 1
    // We want to find the breakpoint (a breakpoint is from where all the head numbers should be similar in next permutation)
    // A permutation would have all the numbers smaller that its preceding number, so in case if a number is greater than its preceding number(or current number is smaller than its next number) that preceding number is the breakpoint.
    int ind = -1;
    for(int i = n-2; i >= 0; i--) {
        if(arr[i] < arr[i+1]) { // Current number is smaller than next number
            ind = i;
            break;
        }
    }

    // If we dont find such a pattern then the current permutation is the last one of its series and hence the next permutation for this current one will be the first one in series that can be obtained by reversing it.
    if(ind == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    // Step 2
    //Now since we want the closest permutation (i.e exactly the next permutation) we have to find the number that is greater thab breakpoint but smaller than other numbers after breakpoint.(smallest no. greater than breakpoint)
    // Such a number will be exactly the first in te line if we go reverse 
    for(int i = n-1; i > ind; i--) {
        if(arr[ind] < arr[i]) { // Once we find a number greater than breakpoint
            swap(arr[ind], arr[i]); // Swap that number with breakpoint and stop
            break;
        }
    }

    // Step 3 
    // Now all the numbers before & including breakpoint are in place. Only the ones after the breakpoint are not
    // Since we want exactly next permutation the sequence of number should be forming smallest possible value.
    // That can be done by sorting the numbers. (Incase of permutation the numbers would be in descending order so we just need to reverse them)
    reverse(arr.begin()+ind+1, arr.end()); 
    return;
}

int main() {
    solve();
}