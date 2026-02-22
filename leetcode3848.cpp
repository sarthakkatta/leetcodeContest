/*
Problem: Check Digitorial Permutation


Approach:
1. Store all valid digitorial numbers in an array.
2. Convert given number to string and sort its digits.
3. For each digitorial number, convert to string and sort digits.
4. Compare sorted strings.
5. If match found, return true, otherwise false.

Time Complexity: O(D log D)
Space Complexity: O(1)
*/


class Solution{
public:
    bool isDigitorialPermutation(int n){
        vector<int> arr = {1, 2, 145, 40585};
        string s = to_string(n);
        sort(s.begin(), s.end());
        for(int num : arr){
            string ss = to_string(num);
            sort(ss.begin(), ss.end());
            if(s == ss){
                return true;
            }
        }
        return false;
    }
};
