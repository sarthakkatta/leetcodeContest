/*
Problem: Largest Integer With Given Digit Sum

Approach:
1. Check if it is possible to form an n-digit number:
   - The maximum possible digit sum for n digits is n × 9.
   - If the required sum s is greater than n × 9,
     return -1.
2. Initialize the answer as 0.
3. Traverse all n digit positions.
4. For each position:
   - Take the largest possible digit:
       x = min(s, 9)
   - Reduce the remaining sum:
       s -= x
   - Append x to the answer.
5. After filling all digits, return the constructed number.

Key Idea:
- To obtain the largest possible number,
  always place the largest possible digit
  at the leftmost available position.
- This greedy approach guarantees the
  lexicographically largest n-digit integer
  with the required digit sum.

Example:
Input:
n = 3
s = 20

Process:
Digit 1 = 9
Remaining Sum = 11

Digit 2 = 9
Remaining Sum = 2

Digit 3 = 2

Answer:
992

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int largestInteger(int n, int s) {

        if ((n * 9) < s)
            return -1;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int x = min(s, 9);

            s -= x;

            ans = ans * 10 + x;
        }

        return ans;
    }
};
