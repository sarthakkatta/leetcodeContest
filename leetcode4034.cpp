/*
Problem: 4034. Minimum Bishop Moves to Reach Target

A bishop can move any number of squares diagonally in one move.

The important property of a bishop is that it always stays on the same
colored squares throughout its movement.

Return:
- 0 if source and target are already the same position.
- -1 if the target is unreachable.
- 1 if the target lies on the same diagonal as the source.
- 2 if the target is reachable but not on the same diagonal.

Approach:
---------
1. Check whether source and target are the same:
   - If `sr == tr` and `sc == tc`, no movement is required.
   - Return 0.

2. Check the color of both squares:
   - A square's color is determined by `(row + column) % 2`.
   - If both positions have different parity, they belong to different
     colored squares.
   - A bishop can never change its square color.
   - Therefore, the target is unreachable.
   - Return -1.

3. Check whether both positions lie on the same diagonal:
   There are two types of diagonals:
   
   - Main diagonal:
       row - column = constant
   
   - Opposite diagonal:
       row + column = constant

   If either of these values is equal for source and target, the bishop
   can directly move from source to target in one move.
   - Return 1.

4. If the squares have the same color but are not on the same diagonal:
   - The bishop cannot reach the target in one move.
   - However, for two squares of the same color, there always exists an
     intermediate square that lies on a diagonal with both positions.
   - Therefore, the bishop can reach the target in exactly 2 moves.
   - Return 2.

Key Idea:
---------
A bishop can ONLY move diagonally, so it can never change the color of
the square it is standing on.

For any position `(r, c)`:
    (r + c) % 2

determines its color.

Also, two positions are on the same diagonal if either:
    r - c is equal
or:
    r + c is equal

Therefore, the answer can only be 0, 1, 2, or -1.

Example:
--------
source = [2, 3]
target = [4, 5]

Both squares have:
    (2 + 3) % 2 = 1
    (4 + 5) % 2 = 1

So they have the same color.

Also:
    2 - 3 = -1
    4 - 5 = -1

They lie on the same diagonal, so the bishop can reach the target
directly in 1 move.

Answer = 1.

Example 2:
----------
source = [1, 1]
target = [2, 2]

Both positions have the same color and:
    1 - 1 = 0
    2 - 2 = 0

So they are on the same diagonal.

Answer = 1.

Example 3:
----------
source = [1, 1]
target = [1, 2]

Colors:
    (1 + 1) % 2 = 0
    (1 + 2) % 2 = 1

The colors are different, so the bishop can never reach the target.

Answer = -1.

Time Complexity:
----------------
O(1)

Only a constant number of arithmetic and comparison operations are
performed.

Space Complexity:
-----------------
O(1)

No extra data structures are used.
*/

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];
        // Same position
        if (sr == tr && sc == tc)
            return 0;
        // Different color -> impossible
        if ((sr + sc) % 2 != (tr + tc) % 2)
            return -1;
        // Same diagonal -> 1 move
        if (sr - sc == tr - tc || sr + sc == tr + tc)
            return 1;
        // Same color but different diagonal -> 2 moves
        return 2;
    }
};
