#include<bits\stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    vector<int> arr;
	int n, k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> n >> k;
	map<int, int> presumMap; // Map stores the sum at current index i and i itself
	int sum(0), maxlen(0);
	for(int i = 0; i < n; i++) {
		sum += arr[i]; // Iterate the loop and add up the current i to sum

		if(sum == k) { // Before presum engg always check if sum is equalling k then it can be potential answer so store it in maxlen
			maxlen = max(maxlen, i+1);
		}

		int rem = sum - k; // If sum != k then check how much to remove from sum to get k and store it in rem

		// Find this remaining value in the map

		if(presumMap.find(rem) != presumMap.end()) { // If rem found in map
			int len = i - presumMap[rem]; // Subtract the index at which we got rem by taking it from map, with current index i
			maxlen = max(maxlen, len); // Update the maxlen
		}

		// Finally add up the sum in the map for future reference

		// (NOTE : Check this condition in case of longest subarray only, if asked shortest then dont check this condition)
		if(presumMap.find(sum) == presumMap.end()) { // Only add the sum if its not previously present
			presumMap[sum] = i; // Store the sum in map at current index i
		}
	}
	cout << maxlen; // Return the maxlen

}

int main() {
    solve();
}