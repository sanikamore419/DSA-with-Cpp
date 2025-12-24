class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // Step 1: Calculate total apples
        int totalApples = 0;
        for (int a : apple) {
            totalApples += a;
        }

        // Step 2: Sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());

        // Step 3: Select boxes greedily
        int currentCapacity = 0;
        int boxCount = 0;

        for (int cap : capacity) {
            currentCapacity += cap;
            boxCount++;
            if (currentCapacity >= totalApples) {
                return boxCount;
            }
        }

        return boxCount; // guaranteed solution exists
    }
};
