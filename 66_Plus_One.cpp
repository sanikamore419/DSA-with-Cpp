#include <bits/stdc++.h>
using namespace std;

/*
Problem: 66. Plus One

Concept:
Array traversal, carry handling, basic math simulation

Author:
Sanika

Approach:
Start from the last digit since it is the least significant.
If the digit is less than 9, increment it and return the array.
If the digit is 9, change it to 0 and continue moving left.
If all digits are processed and become 0, insert 1 at the beginning.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
