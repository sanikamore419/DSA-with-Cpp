// LeetCode 344: Reverse String
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {

        // Initialize two pointers at the beginning and end of the array
        int st = 0, end = s.size() - 1;

        // Swap characters until the pointers meet
        while (st < end) {
            swap(s[st++], s[end--]);
        }
    }
};
