/*
    LeetCode 852. Peak Index in a Mountain Array
    Difficulty: Medium

    Approach:
    - Use Binary Search to find the peak element.
    - If arr[mid] is greater than both neighbors, it is the peak.
    - If the sequence is increasing at mid, move to the right.
    - Otherwise, move to the left.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1;
        int end = arr.size() - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Check if mid is the peak element
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            // Increasing slope, peak lies to the right
            else if (arr[mid] > arr[mid - 1]) {
                st = mid + 1;
            }
            // Decreasing slope, peak lies to the left
            else {
                end = mid - 1;
            }
        }

        return -1; // Peak is guaranteed to exist
    }
};
