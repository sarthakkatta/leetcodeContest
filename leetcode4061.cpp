/*
Problem:
---------
LeetCode 4061. Minimum Queen Moves to Reach Target

Approach:
---------
1. Extract the row and column of the source and target positions.

2. First check whether the source and target positions are already the
   same:
   
       sr == tr && sc == tc

   If they are the same, no move is required.
   Return 0.

3. Check whether the source and target are in the same row or the same
   column:

       sr == tr
       OR
       sc == tc

   A queen can move any number of squares horizontally or vertically
   in one move.

   Therefore, return 1.

4. Check whether the source and target are on the same diagonal.

   Two positions are on the same diagonal when:

       abs(sr - tr) == abs(sc - tc)

   A queen can move diagonally any number of squares in one move.

   Therefore, return 1.

5. If none of the above conditions are true:
   - The queen cannot reach the target directly.
   - A queen can always reach any other square in at most two moves.
   - Therefore, return 2.

Key Idea:
---------
A queen has three types of movement:

    Horizontal:
        Same row

    Vertical:
        Same column

    Diagonal:
        Absolute row difference == absolute column difference

So the answer can only be:

    0 -> already at target
    1 -> same row, column, or diagonal
    2 -> otherwise

The diagonal condition:

    abs(sr - tr) == abs(sc - tc)

is the key condition for detecting whether two positions lie on the same
diagonal.

Example:
--------
source = [1, 1]
target = [1, 5]

Both positions have the same row:

    sr == tr

So the queen can directly move horizontally.

Answer = 1.

Example 2:
----------
source = [1, 1]
target = [4, 4]

Row difference:

    |1 - 4| = 3

Column difference:

    |1 - 4| = 3

Since both differences are equal, the positions are on the same
diagonal.

Answer = 1.

Example 3:
----------
source = [1, 1]
target = [3, 5]

They are:
- Not in the same row.
- Not in the same column.
- Not on the same diagonal.

Therefore, they cannot be reached in one queen move.

Answer = 2.

Time Complexity:
----------------
O(1)

Only a constant number of comparisons and arithmetic operations are
performed.

Space Complexity:
-----------------
O(1)

Only a few integer variables are used.
*/

class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];
        if(sr == tr && sc == tc) return 0;
        if(sr == tr || sc == tc) return 1;
        if(abs(sr - tr) == abs(sc - tc)) return 1;
        return 2;
    }
};
