/*
Problem:
---------
LeetCode 2444 - Count Subarrays With Fixed Bounds


Approach:
---------
We use four variables to count valid subarrays efficiently:

    start = last index where an element was outside [minK, maxK]
    mini  = last index where nums[i] == minK
    maxi  = last index where nums[i] == maxK
    count = total number of valid subarrays

We traverse the array from left to right.

1. Track invalid elements:
   If nums[i] < minK or nums[i] > maxK, the current element cannot
   belong to any valid subarray.

   We update:

       start = i

   Any valid subarray ending at the current index must start after
   this invalid position.

2. Track the latest occurrence of maxK:
   If nums[i] == maxK, update:

       maxi = i

3. Track the latest occurrence of minK:
   If nums[i] == minK, update:

       mini = i

4. Count valid subarrays ending at index i:
   A valid subarray must:
   - Start after the most recent invalid element.
   - Contain at least one occurrence of minK.
   - Contain at least one occurrence of maxK.

   The earliest of the latest minK and maxK occurrences determines
   the last possible starting boundary:

       min(mini, maxi)

   Therefore, the number of valid subarrays ending at index i is:

       max(0, min(mini, maxi) - start)

   We add this value to `count`.


Key Idea:
---------
The important observation is that we do not need to generate every
possible subarray.

For each ending index `i`, we only need to know:
- Where the last invalid element occurred.
- Where `minK` most recently occurred.
- Where `maxK` most recently occurred.

The latest occurrence of either bound that appears earlier determines
how far left the starting position can extend while still including
both required values.

The formula:

    min(mini, maxi) - start

counts all possible starting positions between `start + 1` and
`min(mini, maxi)`, inclusive.

If either bound has not appeared yet, its index remains `-1`.
The `max(0L, ...)` expression ensures that no negative number of
subarrays is added.


Example:
--------
Input:
nums = [1, 3, 5, 2, 7, 5]
minK = 1
maxK = 5

Initially:
    start = -1
    mini  = -1
    maxi  = -1
    count = 0

i = 0, nums[i] = 1
    mini = 0
    maxi = -1
    valid = max(0, min(0, -1) - (-1)) = 0
    count = 0

i = 1, nums[i] = 3
    No boundary index changes.
    valid = 0
    count = 0

i = 2, nums[i] = 5
    maxi = 2
    valid = max(0, min(0, 2) - (-1)) = 1
    count = 1

i = 3, nums[i] = 2
    valid = max(0, min(0, 2) - (-1)) = 1
    count = 2

i = 4, nums[i] = 7
    7 > 5, so start = 4
    valid = max(0, min(0, 2) - 4) = 0
    count = 2

i = 5, nums[i] = 5
    maxi = 5
    valid = max(0, min(0, 5) - 4) = 0
    count = 2

Output:
    2

The valid subarrays are:
    [1, 3, 5]
    [1, 3, 5, 2]


Time Complexity:
----------------
O(n)

We traverse the array once and perform constant-time operations at
each index.


Space Complexity:
-----------------
O(1)

Only a fixed number of variables are used, regardless of the input size.
*/

class Solution {
public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long count = 0, start = -1, mini = -1, maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) start = i;
            if (nums[i] == maxK) maxi = i;
            if (nums[i] == minK) mini = i;
            int valid = max(0L, min(mini, maxi) - start);
            count += valid;
        }
        return count;
    }
};
