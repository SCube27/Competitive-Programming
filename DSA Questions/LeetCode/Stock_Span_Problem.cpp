#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr;
	stack<pair<int, int>> s;
	int t;
	cin >> t;
	while(t--) {
		int num;
		cin >> num;
		arr.push_back(num);
		int n = arr.size();
		
		int index = n-1;
		int res;
		while(!s.empty() && s.top().first < arr[index]) {
			s.pop();
		}

		if(!s.empty()) res = index - s.top().second;
		else res = index+1;

		s.push({arr[index], index});
		cout << res << " ";
	}
}

// Uses the Next Greater Element to Left Pattern to solve the question 
// For every new element of the array we find the next greater element to the left then we find the difference between the current element index and NGL element index 
// Return this difference as answer
// To store the index along with the element we store pairs in the stack