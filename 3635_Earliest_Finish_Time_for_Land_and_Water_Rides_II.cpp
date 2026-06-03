// LeetCode 3635. Earliest Finish Time for Land and Water Rides II
// Approach: Greedy
// Time Complexity: O(n + m)
// Space Complexity: O(1)

class Solution {
    static inline int MAX = 300005;

public:
    int earliestFinishTime(vector<int>& la, vector<int>& lb,
                           vector<int>& wa, vector<int>& wb) {

        int l = MAX, w = MAX;
        int minL = MAX, minW = MAX;

        int n = la.size();
        int m = wa.size();

        // Earliest land ride completion time
        for (int i = 0; i < n; i++) {
            l = min(l, la[i] + lb[i]);
        }

        // Best answer for Land -> Water
        for (int i = 0; i < m; i++) {
            w = min(w, wa[i] + wb[i]);
            minL = min(minL, max(wa[i], l) + wb[i]);
        }

        // Best answer for Water -> Land
        for (int i = 0; i < n; i++) {
            minW = min(minW, max(la[i], w) + lb[i]);
        }

        return min(minL, minW);
    }
};
