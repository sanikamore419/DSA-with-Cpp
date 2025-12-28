/*
=====================================================
LeetCode 1351 - Count Negative Numbers in a Sorted Matrix
Difficulty: Easy
Topic: Array, Matrix, Two Pointers

Problem Summary:
- Given a matrix sorted in non-increasing order row-wise and column-wise
- Count the total number of negative numbers efficiently

Approach:
1. Start from the top-right corner of the matrix
2. If the current element is negative:
   - All elements below it in the same column are negative
   - Add (rows - currentRow) to the count
   - Move left
3. If the current element is non-negative:
   - Move down

Time Complexity: O(m + n)
Space Complexity: O(1)

Author: Sanika
=====================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int row = 0;
        int col = n - 1;
        int count = 0;

        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += (m - row);
                col--;
            } else {
                row++;
            }
        }

        return count;
    }
};
