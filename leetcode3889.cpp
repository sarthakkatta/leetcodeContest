/*
Problem: Mirror Frequency Distance

Approach:
1. Create a frequency array to count occurrences of all characters.
2. Traverse the string and fill frequency of each character.
3. Use a visited array to avoid double counting pairs.
4. For lowercase letters ('a' to 'z'):
   - Find mirror character using: mirror = 'z' - (c - 'a')
   - Add absolute difference of their frequencies to answer.
   - Mark both characters as visited.
5. For digits ('0' to '9'):
   - Find mirror character using: mirror = '9' - (c - '0')
   - Add absolute difference similarly.
   - Mark both as visited.
6. Return total accumulated difference.

Time Complexity: O(N + 26 + 10) ≈ O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(128,0);

        for(char c : s){
            freq[c]++;
        }

        vector<bool> visited(128,false);
        int ans = 0;

        for(char c = 'a'; c <= 'z'; c++){
            if(visited[c]) continue;

            char mirror = 'z' - (c - 'a');

            ans += abs(freq[c] - freq[mirror]);
            visited[c] = true;
            visited[mirror] = true;
        }

        for(char c = '0'; c <= '9'; c++){
            if(visited[c]) continue;

            char mirror = '9' - (c - '0');

            ans += abs(freq[c] - freq[mirror]);
            visited[c] = true;
            visited[mirror] = true;
        }
        return ans;
    }
};
