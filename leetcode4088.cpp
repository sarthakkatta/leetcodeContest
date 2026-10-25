/*
Problem:
---------
LeetCode 4088 - Difference Between Peaks and Valleys


Approach:
---------
We traverse the array from index 1 to the second-last index because
the first and last elements do not have both a left and a right neighbor.

We maintain two variables:
- `sump` stores the sum of all peak elements.
- `sumv` stores the sum of all valley elements.

For every element `nums[i]`, we check two conditions:

1. Peak:
   If the current element is greater than both its neighbors:

       nums[i] > nums[i - 1] && nums[i] > nums[i + 1]

   it is a peak, so we add it to `sump`.

2. Valley:
   If the current element is smaller than both its neighbors:

       nums[i] < nums[i - 1] && nums[i] < nums[i + 1]

   it is a valley, so we add it to `sumv`.

After traversing the array, we return the difference between the sum
of peaks and the sum of valleys:

    sump - sumv


Key Idea:
---------
A peak is an element that is strictly greater than its immediate
neighbors.

A valley is an element that is strictly smaller than its immediate
neighbors.

For example:

    [1, 4, 2, 5, 1]

- `4` is a peak because 4 > 1 and 4 > 2.
- `2` is a valley because 2 < 4 and 2 < 5.
- `5` is a peak because 5 > 2 and 5 > 1.

Therefore:

    Sum of peaks   = 4 + 5 = 9
    Sum of valleys = 2

The difference is:

    9 - 2 = 7

The comparisons are strict, so an element equal to either neighbor
is neither a peak nor a valley.


Example:
--------
Input:
nums = [1, 4, 2, 5, 1]

Step 1: Initialize:

    sump = 0
    sumv = 0

Step 2: Check each interior element:

    i = 1 -> nums[1] = 4
             4 > 1 and 4 > 2
             Peak -> sump = 4

    i = 2 -> nums[2] = 2
             2 < 4 and 2 < 5
             Valley -> sumv = 2

    i = 3 -> nums[3] = 5
             5 > 2 and 5 > 1
             Peak -> sump = 9

Step 3: Calculate the difference:

    sump - sumv = 9 - 2 = 7

Output:
    7


Time Complexity:
----------------
O(n)

We traverse the array once, checking each interior element in constant
time, where n is the number of elements.


Space Complexity:
-----------------
O(1)

We use only two integer variables to store the sums of peaks and valleys.
*/

class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int sump = 0;
        int sumv = 0;
        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]){
                sump += nums[i];
            }else if(nums[i] < nums[i - 1] && nums[i] < nums[i + 1]){
                sumv += nums[i];
            }
        }
        return (sump - sumv);
    }
};
