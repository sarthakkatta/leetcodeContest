/*
Problem:
---------
LeetCode 4071. Minimum Rotations to Dial a Number II


Approach:
---------
We model the cost of moving between two digits on a circular dial.

Since the dial contains digits 0 to 9, the direct distance between two
digits `a` and `b` is:

    abs(a - b)

But because the dial is circular, we can also move through the other side
of the dial. That distance is:

    10 - abs(a - b)

Therefore, the minimum rotation cost between two digits is:

    min(abs(a - b), 10 - abs(a - b))

This calculation is handled by the `cost()` function.

For the original string, we calculate the total cost of moving through
all consecutive digits:

    0 -> s[0] -> s[1] -> s[2] -> ... -> s[n-1]

Then we consider reversing the suffix starting from every possible index
`k`.

When the suffix `[k ... n-1]` is reversed:
- The internal connections inside that suffix remain the same total cost
  because the circular distance is symmetric.
- Only the connection at the boundary changes.

For `k > 0`, the original boundary is:

    s[k - 1] -> s[k]

After reversing the suffix, the new boundary becomes:

    s[k - 1] -> s[n - 1]

So instead of recalculating the entire cost, we remove the old boundary
cost and add the new boundary cost.

For `k = 0`, the entire string is reversed. The internal costs remain
unchanged, while the initial connection from `0` to `s[0]` effectively
becomes the connection from `0` to `s[n-1]`.


Key Idea:
---------
The main optimization is that reversing a suffix does NOT require us to
recalculate all the digit-to-digit costs.

Because:

    cost(a, b) == cost(b, a)

reversing the order of a segment does not change the total cost of the
connections inside that segment.

Therefore, only the boundary connection needs to be changed.

For suffix starting at `k`:

    old cost = cost(s[k - 1], s[k])

    new cost = cost(s[k - 1], s[n - 1])

So:

    newCost = total
            - old boundary cost
            + new boundary cost

We check every possible `k` and keep the minimum value.

This reduces the solution from potentially recalculating the whole string
for every reversal to a single O(n) scan.


Example:
--------
Suppose:

    s = "1234"

The original cost is:

    cost(0,1) + cost(1,2) + cost(2,3) + cost(3,4)

Now suppose we reverse the suffix starting at `k = 2`:

    "12" + reverse("34")
    = "1243"

The internal connection between `3` and `4` has the same cost after
reversal because:

    cost(3,4) == cost(4,3)

So we only need to replace the boundary:

    cost(1,3)

with:

    cost(1,4)

This is exactly what the loop calculates.


Time Complexity:
----------------
O(n)

We first calculate the original total cost in O(n), and then check every
possible suffix reversal in another O(n) loop.

Overall:

    O(n)


Space Complexity:
-----------------
O(1)

Only a constant number of variables are used apart from the input string.
*/

class Solution {
public:
    int cost(int a, int b) {
        int d = abs(a - b);
        return min(d, 10 - d);
    }
    int minRotations(int n, string s) {
        long long total = cost(0, s[0] - '0');
        for (int i = 1; i < n; i++) {
            total += cost(s[i - 1] - '0', s[i] - '0');
        }
        long long ans = total;
        // Reverse entire string: k = 0
        ans = min(ans, total
            - cost(0, s[0] - '0')//old remove kr
            + cost(0, s[n - 1] - '0')); //new waala daal

        // Reverse suffix starting from k
        for (int k = 1; k < n; k++) {
            long long newCost = total
                - cost(s[k - 1] - '0', s[k] - '0')
                + cost(s[k - 1] - '0', s[n - 1] - '0');

            ans = min(ans, newCost);
        }
        return ans;
    }
};
