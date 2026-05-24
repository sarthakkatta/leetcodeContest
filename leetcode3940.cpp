/*
Problem: Limit Occurrences in Sorted Array

Approach:
1. Initialize answer array with first element.
2. Maintain count of current element occurrences.
3. Traverse array from index 1:
   - If current element equals previous:
       → increment count.
   - Else:
       → reset count to 1.
4. If count <= k:
   - Add current element to answer.
5. Return final filtered array.

Key Idea:
- Since array is sorted, duplicates appear consecutively.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int count = 1;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } 
            else {
                count = 1;
            }
            if (count <= k) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
