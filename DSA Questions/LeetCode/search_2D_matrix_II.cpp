#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // optimal solution
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m-1;
        while(row < n && col >= 0) {
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][col] < target) {
                row++;
            }
            else if(matrix[row][col] > target) {
                col--;
            }
        }
        return false;
    }
};
// Better solution -> It works on the complexity of O(n * logn)

// this solution works on binary search but with a concept of elimminating either rows or columns
// we can see a pattern that whenever we take a point from the top right corner 
// 1. The numbers are in a increasing form for the row and col too.
// 2. This means the numbers in row are smaller from that point and the numbers in column are greater than that point.
// 3. This point can be treated as mid and if target(x) is greater than the point then it won't exist in the row so we move on
// 4. Similarly if the target(x) is smaller than the point then it won't exist in the col so we move on.
// [IMP] If the target exists then there will surely be a scenario when point meets target.