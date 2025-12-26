/*
--------------------------------------------------------
LeetCode 2483: Minimum Penalty for a Shop
Difficulty: Medium

Problem Summary:
- Given a string consisting of 'Y' and 'N'
- 'Y' -> customers come at that hour
- 'N' -> no customers come

Penalty Rules:
1. Shop is OPEN and no customers ('N') -> penalty +1
2. Shop is CLOSED and customers come ('Y') -> penalty +1

Goal:
Return the EARLIEST hour to close the shop such that
the total penalty is minimized.

Approach:
- Count total number of 'Y' initially.
- Iterate through each possible closing hour.
- Maintain:
  LN = number of 'N' before closing (open but empty)
  Y  = number of 'Y' before closing
- Remaining 'Y' after closing = totalY - Y
- Penalty = LN + remainingY

Time Complexity: O(n)
Space Complexity: O(1)
--------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string c) {
        int LN = 0;        // Count of 'N' before closing hour
        int totalY = 0;   // Total 'Y' in string

        // Count total customers
        for (char ch : c) {
            if (ch == 'Y') totalY++;
        }

        int Y = 0;                // 'Y' before closing
        int minPenalty = INT_MAX;
        int ans = 0;

        // Try closing at each hour from 0 to n-1
        for (int i = 0; i < c.size(); i++) {
            int remainingY = totalY - Y;
            int penalty = remainingY + LN;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }

            // Update counts
            if (c[i] == 'Y') Y++;
            else LN++;
        }

        // Case: close after the last hour (hour = n)
        int remainingY = totalY - Y; // should be 0
        int penalty = remainingY + LN;

        if (penalty < minPenalty) {
            ans = c.size();
        }

        return ans;
    }
};

/*
Example:
Input: "YYNY"

Closing Hour Analysis:
Close at 0 -> penalty = 3
Close at 1 -> penalty = 2
Close at 2 -> penalty = 1  (minimum)
Close at 3 -> penalty = 2
Close at 4 -> penalty = 1

Answer = 2 (earliest minimum)
*/
