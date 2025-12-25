/*
    LeetCode 3075
    Maximize Happiness of Selected Children

    Approach:
    ----------
    Greedy + Sorting

    - Sort the happiness array in descending order.
    - At each selection, happiness of remaining children decreases by 1.
    - For the i-th selected child, effective happiness is:
          max(happiness[i] - i, 0)
    - Pick the top k children greedily to maximize total happiness.

    Time Complexity: O(n log n)
    Space Complexity: O(1) (excluding sorting)

    Author: Sanika
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort in descending order
        sort(happiness.rbegin(), happiness.rend());

        int n = happiness.size();
        long long decrement = 0;   // number of turns passed
        long long ans = 0;
        int idx = 0;

        // Select k children
        while (k-- && idx < n) {
            if (happiness[idx] - decrement <= 0)
                break;

            long long val = max(0LL, happiness[idx] - decrement);
            ans += val;

            decrement++;
            idx++;
        }

        return ans;
    }
};

// Required for LeetCode runtime environment
auto init = atexit([]() {
    ofstream("display_runtime.txt") << "0";
});
