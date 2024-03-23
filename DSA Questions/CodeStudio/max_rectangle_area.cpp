#include<bits/stdc++.h>
using namespace std;

int maximum(vector<int>& area, int n) {
	int maxi = INT_MIN;
	for(int i = 0; i < n; i++) {
		if(maxi < area[i]) maxi = area[i];
	}
	return maxi;
}

vector<int> NSR(vector<int>& heights, int n) {
	int pseudo = n;
	vector<int> ans(n);
	stack<pair<int, int>> s;

	for(int i = n-1; i >= 0; i--) {
		while(!s.empty() && heights[i] <= s.top().first) {
			s.pop();
		}

		if(!s.empty()) ans[i] = s.top().second;
		else ans[i] = pseudo;

		s.push({heights[i], i});
	}
	return ans;
}

vector<int> NSL(vector<int>& heights, int n) {
	int pseudo = -1;
	vector<int> ans(n);
	stack<pair<int, int>> s;

	for(int i = 0; i < n; i++) {
		while(!s.empty() && heights[i] <= s.top().first) {
			s.pop();
		}

		if(!s.empty()) ans[i] = s.top().second;
		else ans[i] = pseudo;

		s.push({heights[i], i});
	}
	return ans;
}

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();

	vector<int> left(n);
	vector<int> right(n);

	left = NSL(heights, n);
	right = NSR(heights, n);

	vector<int> width(n);
	vector<int> area(n);

	for(int i = 0; i < n; i++) {
		width[i] = right[i] - left[i] - 1;    
	}

	for(int i = 0; i < n; i++) {
		area[i] = heights[i] * width[i];
	}

	int max_area = maximum(area, n); 
	return max_area;
}

int main() {
	int n;
	cin >> n;
	vector<int> heights(n);

	for(int i = 0; i < n; i++) {
		cin >> heights[i];
	}

	int area = largestRectangleArea(heights);
	cout << area;

}