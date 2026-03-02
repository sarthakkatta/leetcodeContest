/*
Problem: Trim Trailing Vowels 


Approach:
1. Traverse string from end to beginning.
2. If last character is a vowel, remove it.
3. Stop when a non-vowel character is found.
4. Return modified string.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else
            return false;
    }

    string trimTrailingVowels(string s){
        for(int i = s.length() - 1; i >= 0; i--){
            if(isvowel(s[i]))
                s.pop_back();
            else
                break;
        }
        return s;
    }
};
