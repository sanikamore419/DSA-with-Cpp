/*
---------------------------------------------------------
Problem   : 1390. Four Divisors
Author    : Sanika
Difficulty: Medium
---------------------------------------------------------

Concepts Used:
- Number Theory
- Divisor Counting
- Prime Factorization Logic
- Optimization using sqrt(n)

Approach:
A number has exactly 4 divisors if:
1) It is of the form p^3 (p is prime), OR
2) It is of the form p * q (p and q are distinct primes)

For each number:
- Start with divisors 1 and n
- Check divisors up to sqrt(n)
- Count divisor pairs
- If exactly 4 divisors exist, add their sum to answer
*/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            int sum = 1 + n;   // 1 and n are always divisors
            int cnt = 0;       // count of divisors excluding 1 and n

            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    int d1 = i;
                    int d2 = n / i;

                    // Perfect square case
                    if (d1 == d2) {
                        cnt++;
                        sum += d1;
                    } else {
                        cnt += 2;
                        sum += d1 + d2;
                    }

                    // More than 4 divisors → invalid
                    if (cnt > 2) break;
                }
            }

            // Exactly 4 divisors → cnt must be 2
            if (cnt == 2) {
                ans += sum;
            }
        }

        return ans;
    }
};
