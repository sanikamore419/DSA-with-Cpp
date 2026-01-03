/*
Author: Sanika

Problem: 1411. Number of Ways to Paint N × 3 Grid

Approach:
We observe that for a single row of a 3-column grid using 3 colors
(Red, Yellow, Green) with no adjacent cells having the same color,
there are exactly 12 valid color patterns.

These patterns can be classified into two types:

1) Type A (ABC pattern):
   - All three cells have different colors.
   - Example: Red-Yellow-Green
   - Total such patterns = 6

2) Type B (ABA pattern):
   - First and third cells have the same color, middle is different.
   - Example: Red-Yellow-Red
   - Total such patterns = 6

Let:
diff = number of ways to paint the grid till current row using Type A
same = number of ways to paint the grid till current row using Type B

Transition between rows:
- A new Type A row can be formed from:
    2 * previous diff + 2 * previous same
- A new Type B row can be formed from:
    2 * previous diff + 3 * previous same

We iterate row by row and update these two states.
Only previous row values are needed, so space is optimized to O(1).

Final answer = diff + same (mod 1e9 + 7)

Concepts Used:
- Dynamic Programming
- State Compression
- Combinatorics
- Modular Arithmetic

Time Complexity:
O(n)

Space Complexity:
O(1)
*/

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long diff = 6; // Type A: all different colors
        long long same = 6; // Type B: first and third same

        for (int i = 2; i <= n; i++) {
            long long newDiff = (2 * diff + 2 * same) % MOD;
            long long newSame = (2 * diff + 3 * same) % MOD;

            diff = newDiff;
            same = newSame;
        }

        return (diff + same) % MOD;
    }
};
