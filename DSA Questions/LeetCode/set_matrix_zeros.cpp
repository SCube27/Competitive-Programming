// [IMP : See the diagram in notes to understand]
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& matrix, int n, int m) {
    // int row[n] = {0}; matrix[...][0]
    // int col[m] = {0}; matrix[0][...]

    // Step 1 : Marking the 0th row & 0th col as 0 by checking the whole matrix

    int col0 = 1; // Using the extra variable for avoiding the overlapping of row and col
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) { // For any point in matrix with value 0

                matrix[i][0] = 0; // Set the value for i-th row in 0th col as 0

                if(j != 0) { // If j index is not zero (If j is not pointing col 0)
                    matrix[0][j] = 0; // Set that value of 0th row and j-th col as 0
                }
                else { // If j is pointing col 0 then use the extra variable created
                    col0 = 0; // Set the variable as 0
                }
            }
        }
    }

    // Step 2 : Marking remaining rows(1 to n-1) and cols(1 to m-1) as 0 by checking the 0th row & 0th col

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] != 0) { // In remaining part (apart from 0th row & 0th col)

                // If i-th row in 0th col and 0th row in j-th col is 0 then mark that value as 0
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0; // Marking as 0
                }
            }
        }
    }

    // Step 3 : Marking rem values in 0th row & 0th col as 0

    if(matrix[0][0] == 0) { // If value at 0th row & 0th col is 0 then mark all values of 0th row as 0
        for(int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0) { // If value of col0(basically matrix[0][0] only) is 0 then mark all values of 0th col as 0
        for(int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main() {
    vector<vector<int>> matrix = {{6, 4, 2, 0}, {7, 5, 3, 1}, {1, 3, 5, 7}, {0, 2, 4, 6}};
    int n = 4, m = 4;

    vector<vector<int>> ans = solve(matrix, n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}