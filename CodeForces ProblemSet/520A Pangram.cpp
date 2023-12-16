#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int arr[26] = {0}; // array to store frequency of all letters
    for(int i = 0; i < n; i++) {
        if(s[i] < 97) { // checking if current letter is uppercase
            s[i] = s[i] + 32; // convert it to lowercase by adding 32
            arr[s[i] - 'a']++; // storing the letter frequency in array on its designated position
        }
        else { // if lowercase then directly store
            arr[s[i] - 'a']++;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(arr[i] == 0) { // traversing the array to check if any index has 0 frequency
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

// The basic idea of subraacting 'a' while storing is that if a is the first letter then it'll be stored on the 0th index
// So since ascii of a is 97
// If current letter is a then a - a = 97 - 97 -> 0 store on 0th index
// For b, b - a = 98 - 97 -> 1 store on 1st index and so on

int main() {
    solve();
}