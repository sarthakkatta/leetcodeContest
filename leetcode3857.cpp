/*
Problem: Minimum Cost to Split into Ones


Approach:
1. Base case: if n == 1, cost is 0.
2. If n is odd:
   - Reduce to (n - 1).
   - Add (n - 1) to total cost.
3. If n is even:
   - Divide n by 2.
   - Recursively compute cost for n/2.
   - Add (n*n)/4 and double the recursive result.
4. Return total computed cost.

Time Complexity: O(log N) for even reductions, worst-case O(N) if mostly odd.
Space Complexity: O(log N) recursion stack.
*/


class Solution{
public:
    int minCost(int n){
        if(n == 1) return 0;
        if(n & 1){
            return (n - 1) + minCost(n - 1);
        }
        else{
            int res = minCost(n / 2);
            return ((n * n) / 4) + res + res;
        }
    }
};
