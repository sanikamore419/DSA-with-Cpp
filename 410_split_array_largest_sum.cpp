// LeetCode 410: Split Array Largest Sum
// Approach: Binary Search on Answer
// Time Complexity: O(n * log(sum))
// Space Complexity: O(1)

class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long mid) {
        int count = 1;
        long long curr_sum = 0;

        for (int num : nums) {
            if (curr_sum + num <= mid) {
                curr_sum += num;
            }
            else {
                count++;
                curr_sum = num;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int num : nums) {
            high += num;
        }

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
