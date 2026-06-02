// LeetCode 3633. Earliest Finish Time for Land and Water Rides I
// Approach: Brute Force
// Time Complexity: O(n * m)
// Space Complexity: O(1)

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {

                // Land -> Water
                int landFinish = landStartTime[i] + landDuration[i];
                int finish1 = max(landFinish, waterStartTime[j]) +
                              waterDuration[j];

                // Water -> Land
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int finish2 = max(waterFinish, landStartTime[i]) +
                              landDuration[i];

                ans = min(ans, min(finish1, finish2));
            }
        }

        return ans;
    }
};
