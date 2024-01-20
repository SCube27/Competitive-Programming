#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& matrix, int n) {
    
    // Step 1 : Transpose the Matrix (Convert the rows as columns or columns as rows)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2 : Reverse all the rows of this transposed matrix
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    return matrix;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    vector<vector<int>> ans = solve(matrix, n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl; 
    }
    return 0; 
}