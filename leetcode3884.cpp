/*
Problem: First Matching Character From Both Ends

Approach:
1. Traverse the string from left to right.
2. For each index i, compare s[i] with its mirror character s[n-i-1].
3. If both characters match, return the index i.
4. If no such index exists, return -1.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == s[n - i - 1]) return i;
        }
        return -1;
    }
};
