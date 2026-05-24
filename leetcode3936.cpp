/*
Problem: Minimum Swaps to Move Zeros to End

Approach:
1. Count total number of zeros in the array.
   - actualzeros = total zeros present.
2. Check the last `actualzeros` positions:
   - Count how many zeros are already there.
3. Remaining zeros outside this segment
   need to be swapped into the end.
4. Minimum swaps:
   - actualzeros - curzero

Key Idea:
- Best arrangement places all zeros in last positions.
- Count how many are already correctly placed.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int actualzeros = 0;
        for(int num : nums){
            if(num == 0) actualzeros++;
        }
        int curzero = 0;
        for(int i = n - actualzeros; i < n; i++){
            if(nums[i] == 0){
                curzero++;
            }
        }
        return actualzeros - curzero;
    }
};
