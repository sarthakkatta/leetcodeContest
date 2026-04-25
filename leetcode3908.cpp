/*
Problem: Valid Digit Number 

Approach:
1. Convert number n to string.
2. Convert digit x to character.
3. Check:
   - If first character of string == x → return false.
4. Traverse string:
   - If any character equals x → return true.
5. If digit not found → return false.

Key Idea:
- Must contain digit x but should not start with it.

Time Complexity: O(D) (D = number of digits)
Space Complexity: O(D)
*/

class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char ch = x + '0';

        if(s[0] == ch) return false;

        for(char c : s){
            if(c == ch) return true;
        }
        return false;
    }
};
