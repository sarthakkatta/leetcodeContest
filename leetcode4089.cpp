/*
Problem:
---------
LeetCode 4089. Count Subarrays With Loose Bounds


Approach:
---------
We maintain two variables:

    left  = starting index of the current valid segment
    count = total number of subarrays counted so far

We traverse the array from left to right.

For every element nums[i]:

1. If nums[i] < minK or nums[i] > maxK:
   The element is outside the allowed range [minK, maxK].
   Therefore, any subarray containing this element is invalid.

   We update:

       left = i + 1

   This starts a new segment immediately after the invalid element.

2. Otherwise:
   The current element is within the allowed range.

   We add:

       i - left + 1

   This counts all subarrays ending at index i that start anywhere
   between `left` and `i`.

Finally, we return `count`.


Key Idea:
---------
The main idea is to count valid subarrays ending at each index instead
of generating every possible subarray.

If the current valid segment starts at index `left` and ends at index
`i`, the number of subarrays ending at `i` is:

    i - left + 1

For example, if the current segment is:

    [2, 3, 4]

At the last element, the subarrays ending there are:

    [4]
    [3, 4]
    [2, 3, 4]

There are 3 such subarrays.

Whenever an element falls outside [minK, maxK], we reset the starting
boundary because no valid subarray can include that element.

Important:
This code only checks whether elements lie within the range. The actual
LeetCode 2444 problem also requires every counted subarray to contain
both `minK` and `maxK`.


Example:
--------
Input:
nums = [1, 2, 3, 4]
minK = 2
maxK = 3

Processing:

    i = 0, nums[i] = 1
    1 < 2, so left = 1
    count = 0

    i = 1, nums[i] = 2
    Within range
    count += 1 - 1 + 1 = 1

    i = 2, nums[i] = 3
    Within range
    count += 2 - 1 + 1 = 2
    count = 3

    i = 3, nums[i] = 4
    4 > 3, so left = 4
    count remains 3

Output produced by this code:

    3


Time Complexity:
----------------
O(n)

We traverse the array exactly once, where n is the number of elements.


Space Complexity:
-----------------
O(1)

Only the variables `left` and `count` are used for additional storage.
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left = 0;
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                left = i + 1;
            } else {
                count += i - left + 1;
            }
        }
        return count;
    }
};
