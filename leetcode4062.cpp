/*
Problem:
---------
LeetCode 4062. Transform Array Using Pair Operations


Approach:
---------
The code compares the total sum of elements in the `source` array with the
total sum of elements in the `target` array.

First, we calculate the sum of all elements in `source` and store it in
`sum`.

Then, we calculate the sum of all elements in `target` and store it in
`sum2`.

Finally, we check:

    sum == sum2

If both sums are equal, the function returns `true`; otherwise, it returns
`false`.

The use of `long long` ensures that the sum can safely handle larger values
without overflowing a normal integer.


Key Idea:
---------
The main idea is based on preserving the total sum.

If the allowed transformation only redistributes values between elements
without changing the overall total, then both arrays can be transformed
into each other only when their total sums are equal.

For example:

    source = [1, 2, 3]
    target = [3, 1, 2]

Both arrays have:

    1 + 2 + 3 = 6

Therefore, their sums are equal and the function returns `true`.


Example:
--------
Input:

    source = [1, 2, 3]
    target = [3, 1, 2]

Calculate source sum:

    sum = 1 + 2 + 3
        = 6

Calculate target sum:

    sum2 = 3 + 1 + 2
         = 6

Since:

    sum == sum2

The answer is:

    true


For example:

    source = [1, 2, 3]
    target = [1, 2, 4]

Then:

    source sum = 6
    target sum = 7

Since the sums are different:

    sum != sum2

The answer is:

    false


Time Complexity:
----------------
O(n)

We traverse the `source` array once and the `target` array once.

If both arrays contain `n` elements, the total work is O(n).


Space Complexity:
-----------------
O(1)

Only two variables, `sum` and `sum2`, are used apart from the input arrays.
No additional data structure depending on the input size is created.
*/

class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum = 0;
        long long sum2 = 0;
        for(auto &i : source)sum += i;
        for(auto &i : target)sum2 += i;

        return sum == sum2;
    }
};
