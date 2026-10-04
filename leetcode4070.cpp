/*
Problem:
---------
LeetCode 4070. Minimum Rotations to Dial a Number I


Approach:
---------
We simulate the rotation of a circular dial containing digits from 0 to 9.

Initially, the current position is `0`.

For every digit in the string:
- Convert the character into an integer using `ch - '0'`.
- Calculate the direct distance between the current digit and the target:

    abs(curr - target)

- Since the dial is circular, we can also rotate in the opposite direction.
  That distance is:

    10 - diff

- The minimum of these two distances is the number of rotations required
  to reach the target digit.
- Add this minimum cost to `ans`.
- Update `curr` to the target digit.

This process is repeated for every digit in the string.


Key Idea:
---------
The important observation is that the digits are arranged in a circular
manner:

    0 -> 1 -> 2 -> ... -> 9 -> 0

So, between any two digits, there are always two possible ways to rotate.

For example, from `0` to `8`:

Direct distance:

    |0 - 8| = 8

Circular distance:

    10 - 8 = 2

Therefore, we choose:

    min(8, 2) = 2

The same logic is applied for every consecutive target digit.

After reaching one digit, that digit becomes the starting position for
the next digit.


Example:
--------
Input:
s = "190"

Initially:
    curr = 0

For '1':
    diff = |0 - 1| = 1
    circular = 10 - 1 = 9
    cost = 1
    curr = 1

For '9':
    diff = |1 - 9| = 8
    circular = 10 - 8 = 2
    cost = 2
    curr = 9

For '0':
    diff = |9 - 0| = 9
    circular = 10 - 9 = 1
    cost = 1
    curr = 0

Total:

    1 + 2 + 1 = 4

Answer:
    4


Time Complexity:
----------------
O(n)

We visit every character of the string exactly once.


Space Complexity:
-----------------
O(1)

Only a few integer variables are used, regardless of the size of the
input string.
*/

class Solution {

public:

    int minRotations(string s) {

        int curr = 0;

        int ans = 0;

        for(char ch : s){

            int target = ch - '0';

            int diff = abs(curr - target);

            int circular = 10 - diff;

            ans += min(diff, circular);

            curr = target;

        }

        return ans;

    }

};
