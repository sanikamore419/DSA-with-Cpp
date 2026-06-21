// LeetCode 125: Valid Palindrome
// Approach: Two Pointers + Custom Alphanumeric Check
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:

    // Function to check whether a character is alphanumeric
    bool isalphanum(char ch) {
        return ((ch >= '0' && ch <= '9') ||
                (tolower(ch) >= 'a' && tolower(ch) <= 'z'));
    }

    bool isPalindrome(string s) {

        // Initialize two pointers
        int st = 0;
        int end = s.size() - 1;

        // Traverse from both ends towards the center
        while (st < end) {

            // Skip non-alphanumeric characters from the left
            if (!isalphanum(s[st])) {
                st++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if (!isalphanum(s[end])) {
                end--;
                continue;
            }

            // Compare characters after converting them to lowercase
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }

            // Move both pointers inward
            st++;
            end--;
        }

        // If all characters matched, the string is a palindrome
        return true;
    }
};
