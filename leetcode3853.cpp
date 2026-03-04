/*
Problem: Merge Close Characters


Approach:
1. Traverse the string and look for same characters.
2. If two same characters are found within distance k,
   remove the later occurrence.
3. Repeat the process until no more merges are possible.
4. Return the resulting string.

Time Complexity: O(N^3) in worst case due to repeated scanning and erase.
Space Complexity: O(1)
*/


class Solution{
public:
    string mergeCharacters(string s, int k){
        bool merged = true;
        while(merged){
            merged = false;
            for(int i = 0; i < s.length(); i++){
                for(int j = i + 1; j < s.length(); j++){
                    if(s[i] == s[j] && j - i <= k){
                        s.erase(j, 1);
                        merged = true;
                        break;
                    }
                }
                if(merged) break;
            }
        }
        return s;
    }
};
