/*
Author : Sanika
Problem : 961. N-Repeated Element in Size 2N Array
Platform : LeetCode
Difficulty : Easy

Approach :
The array has size 2n and contains n+1 unique elements.
Exactly one element is repeated n times, while all others appear once.

Because the repeated element occurs many times, it must appear very close
to itself in the array. Within a small window of size 4, repetition is
guaranteed.

We scan the array and compare:
- current element with next element
- current element with element at distance 2
- current element with element at distance 3

As soon as a match is found, that element is the answer.

This avoids extra space and works in linear time.

Concepts Used :
- Array traversal
- Observation-based optimization
- Constant space approach

Time Complexity : O(n)
Space Complexity : O(1)
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1])
                return nums[i];

            if (i + 2 < n && nums[i] == nums[i + 2])
                return nums[i];

            if (i + 3 < n && nums[i] == nums[i + 3])
                return nums[i];
        }

        return -1;
    }
};
