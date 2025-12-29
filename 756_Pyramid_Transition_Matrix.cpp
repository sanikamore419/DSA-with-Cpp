#include <bits/stdc++.h>
using namespace std;

// LeetCode 756 - Pyramid Transition Matrix
// Optimized DFS using bitmask + state pruning
// Reference logic inspired by https://www.youtube.com/@0x3f

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        vector<int> groups[7][7];
        for (auto &s : allowed) {
            groups[s[0] & 31][s[1] & 31].push_back(s[2] & 31);
        }

        int n = bottom.size();
        vector<int> pyramid(n, 0);

        for (int i = 0; i < n; i++) {
            pyramid[n - 1] |= (bottom[i] & 31) << (i * 3);
        }

        vector<uint8_t> visited(1 << ((n - 1) * 3), 0);

        function<bool(int,int)> dfs = [&](int level, int idx) -> bool {
            if (level < 0) return true;

            if (visited[pyramid[level]]) return false;

            if (idx == level + 1) {
                visited[pyramid[level]] = 1;
                return dfs(level - 1, 0);
            }

            int left = (pyramid[level + 1] >> (idx * 3)) & 7;
            int right = (pyramid[level + 1] >> ((idx + 1) * 3)) & 7;

            for (int top : groups[left][right]) {
                pyramid[level] &= ~(7 << (idx * 3));
                pyramid[level] |= top << (idx * 3);
                if (dfs(level, idx + 1)) return true;
            }
            return false;
        };

        return dfs(n - 2, 0);
    }
};
