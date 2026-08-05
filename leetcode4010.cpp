/*
Problem: Maximize Pair Strength Using GCD

Approach:
1. Initialize:
   - x = 0 (stores the maximum pair strength).
2. Traverse all possible pairs of elements:
   - Outer loop selects the first element.
   - Inner loop selects the second element.
3. For every pair:
   - Compute their GCD.
   - Calculate pair strength as:
       (a / gcd) × (b / gcd)
4. Compare the computed strength with
   the current maximum.
5. Update the answer if a larger value
   is found.
6. After checking every pair,
   return the maximum pair strength.

Key Idea:
- The pair strength is calculated using
  the GCD of the two numbers.
- Since every pair must be examined,
  a brute-force approach is sufficient.

Example:
Input:
nums = [6, 10, 15]

Pairs:
(6,10) → gcd = 2
Strength = (6/2) × (10/2) = 15

(6,15) → gcd = 3
Strength = (6/3) × (15/3) = 10

(10,15) → gcd = 5
Strength = (10/5) × (15/5) = 6

Output:
15

Time Complexity: O(N² × log(min(a,b)))
Space Complexity: O(1)
*/

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();

        long long int x = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                long long int a = nums[i];
                long long int b = nums[j];

                long long int g = gcd(a, b);

                long long int s = (a / g) * (b / g);

                x = max(x, s);
            }
        }

        return x;
    }
};
