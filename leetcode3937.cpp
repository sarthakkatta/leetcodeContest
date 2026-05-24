/*
Problem:  Minimum Operations to Make Array Modulo Alternating I

Approach:
1. Define helper function `cost()`:
   - Computes minimum circular distance between
     current remainder and target remainder.
   - Can move forward or backward modulo k.
2. Try every possible pair (x, y):
   - x → target remainder for even indices
   - y → target remainder for odd indices
   - x != y
3. For each element:
   - Compute current remainder = nums[i] % k
   - Add cost to convert it into target remainder.
4. Track minimum total operations across all pairs.
5. Return minimum answer.

Key Idea:
- Brute force all valid alternating remainder patterns.

Time Complexity: O(K^2 * N)
Space Complexity: O(1)
*/

class Solution {
public:
    int cost(int r, int target, int k) {
        int forward = (target - r + k) % k;
        int backward = (r - target + k) % k;
        return min(forward, backward);
    }
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        // try every pair (x, y)
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;
                int ops = 0;
                for (int i = 0; i < n; i++) {
                    int rem = nums[i] % k;
                    if (i % 2 == 0) {
                        ops += cost(rem, x, k);
                    } 
                    else {
                        ops += cost(rem, y, k);
                    }
                }
                ans = min(ans, ops);
            }
        }
        return ans;
    }
};
