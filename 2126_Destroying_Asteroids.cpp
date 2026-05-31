/*
LeetCode 2126 - Destroying Asteroids

Approach:
1. Sort asteroids in ascending order.
2. Destroy smaller asteroids first to increase planet mass.
3. If at any point planet mass is smaller than the current asteroid,
   return false.
4. Otherwise add asteroid mass to planet mass and continue.

Time Complexity: O(n log n)
Space Complexity: O(1) (excluding sorting space)
*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long currMass = mass;

        for (int asteroid : asteroids) {
            if (currMass < asteroid)
                return false;

            currMass += asteroid;
        }

        return true;
    }
};
