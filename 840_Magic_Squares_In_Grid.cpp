// LeetCode 840. Magic Squares In Grid
// Checks how many 3x3 magic squares exist inside a grid

#include <vector>
using namespace std;

class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        // Center must be 5 for a valid 3x3 magic square
        if (grid[r + 1][c + 1] != 5) return false;

        vector<int> used(10, 0);

        // Values must be 1 to 9 and all distinct
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || used[val]) return false;
                used[val] = 1;
            }
        }

        // Check rows
        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != 15)
                return false;
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (grid[r][c + j] + grid[r + 1][c + j] + grid[r + 2][c + j] != 15)
                return false;
        }

        // Check diagonals
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15)
            return false;

        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};
