/*
Problem:
---------
LeetCode 4083. Minimum Deletions to Make Array Sharp

Approach:
---------
We initialize `diff` to 0 to count adjacent pairs containing equal
elements.

Then, we traverse the array starting from index 1.

For every index `i`, we compare the current element with the previous
element using the XOR operator:

    nums[i - 1] ^ nums[i]

If both elements are equal, their XOR is 0, so we increment `diff`.

After checking all adjacent pairs, we return `diff`.


Key Idea:
---------
The XOR operator returns 0 when both operands are equal:

    a ^ a = 0

Therefore, the condition:

    (nums[i - 1] ^ nums[i]) == 0

checks whether two consecutive elements are equal.

Every time this condition is true, the counter increases by one.

This logic counts adjacent equal pairs, but it does not necessarily
calculate the minimum deletions required to make an array beautiful
under LeetCode 2216's rules.


Example:
--------
Input:
nums = [1, 1, 2, 2, 3]

Checking adjacent elements:

    1 and 1 -> equal -> diff = 1
    1 and 2 -> different
    2 and 2 -> equal -> diff = 2
    2 and 3 -> different

Output produced by this code:

    2


Time Complexity:
----------------
O(n)

We traverse the array once, where n is the number of elements.


Space Complexity:
-----------------
O(1)

Only the integer variable `diff` is used for additional storage.
*/

class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int diff = 0;
        for(int i = 1; i < nums.size(); i++){
            if((nums[i - 1] ^ nums[i]) == 0){
                diff++;
            }
        }
        return diff;
    }
};
