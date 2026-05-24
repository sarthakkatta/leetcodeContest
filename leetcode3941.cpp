/*
Problem: Password Strength 

Approach:
1. Store all unique characters using unordered_set.
2. Traverse each unique character:
   - Lowercase letter  → +1 strength
   - Uppercase letter  → +2 strength
   - Digit             → +3 strength
   - Special character → +5 strength
3. Sum all contributions.
4. Return total password strength.

Key Idea:
- Only unique characters contribute to strength score.

Time Complexity: O(N)
Space Complexity: O(U)
  (U = number of unique characters)
*/

class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st(password.begin(), password.end());
        int strength = 0;
        for (char ch : st) {
            if (ch >= 'a' && ch <= 'z') {
                strength += 1;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                strength += 2;
            }
            else if (ch >= '0' && ch <= '9') {
                strength += 3;
            }
            else { 
                strength += 5;
            }
        }
        return strength;
    }
};
