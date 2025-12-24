/*
LeetCode 3074 - Apple Redistribution into Boxes
Difficulty: Easy
Topic: Greedy, Sorting

Approach:
1. Calculate total number of apples.
2. Sort box capacities in descending order.
3. Select boxes greedily until total capacity >= total apples.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (int a : apple) totalApples += a;

        sort(capacity.begin(), capacity.end(), greater<int>());

        int curr = 0, boxes = 0;
        for (int cap : capacity) {
            curr += cap;
            boxes++;
            if (curr >= totalApples) return boxes;
        }
        return boxes;
    }
};
