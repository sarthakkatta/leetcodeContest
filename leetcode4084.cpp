/*
Problem:
---------
LeetCode 4084. Last Visited Cell in a Directional Grid

Approach:
---------
We first calculate the number of rows and columns in the grid.

Then, we create a 2D `visited` array to track which cells have already
been visited.

We start at the top-left cell:

    r = 0
    c = 0

We mark this cell as visited.

Inside the loop, we determine the next position based on the current
cell's character:

- 'L': Move one column to the left.
- 'R': Move one column to the right.
- 'U': Move one row upward.
- Otherwise: Move one row downward.

Before moving, we check whether the next position:
- Is outside the grid.
- Has already been visited.

If either condition is true, we stop the traversal.

Otherwise, we update the current position and mark the new cell as
visited.

Finally, we return the row and column of the last valid cell visited.


Key Idea:
---------
The main idea is to simulate the movement one step at a time while
preventing the traversal from leaving the grid or revisiting a cell.

The `visited` matrix prevents infinite loops when the direction
instructions lead back to a previously visited cell.

For example, if the current cell contains 'R', the next column becomes:

    nc = c + 1

Before updating `c`, we validate the next position.

The algorithm stops at the current cell if the next move is invalid.
Therefore, the returned coordinates represent the last valid cell
reached during the simulation.


Example:
--------
Suppose the grid is:

    [
        ['R', 'D', 'L'],
        ['U', 'R', 'D']
    ]

Starting position:

    (0, 0)

The cell contains 'R', so we move right to:

    (0, 1)

The cell contains 'D', so we move down to:

    (1, 1)

The cell contains 'R', so we move right to:

    (1, 2)

The cell contains 'D', so the next row would be outside the grid.
The traversal stops.

Returned coordinates:

    [1, 2]


Time Complexity:
----------------
O(n * m)

In the worst case, each cell is visited at most once, where `n` is the
number of rows and `m` is the number of columns.


Space Complexity:
-----------------
O(n * m)

The `visited` matrix stores one Boolean value for every grid cell.
*/


class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int r = 0, c = 0;
        visited[r][c] = true;
        while (true) {
            int nr = r, nc = c;
            if (grid[r][c] == 'L') {
                nc--;
            } else if (grid[r][c] == 'R') {
                nc++;
            } else if (grid[r][c] == 'U') {
                nr--;
            } else {
                nr++;
            }
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc]) {
                break;
            }
            r = nr;
            c = nc;
            visited[r][c] = true;
        }
        return {r, c};
    }
};
