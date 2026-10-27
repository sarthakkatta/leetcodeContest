/*
Problem:
---------
3963. Create Grid With Exactly One Path


Approach:
---------
We create a 2D grid represented as a vector of strings.

Initially, we fill the entire grid with the character '#'.

    vector<string> grid(m, string(n, '#'));

This creates `m` rows, each containing `n` characters, all initialized
to '#'.

Next, we modify the grid in two steps:

1. Fill the first row with '.':
   We iterate through all columns using `j` and update:

       grid[0][j] = '.';

2. Fill the last column with '.':
   We iterate through all rows using `i` and update:

       grid[i][n - 1] = '.';

Finally, we return the modified grid.


Key Idea:
---------
The main idea is to initialize the entire grid with one character and
then overwrite the required cells with another character.

Initially:

    # # # #
    # # # #
    # # # #

After modifying the first row:

    . . . .
    # # # #
    # # # #

After modifying the last column:

    . . . .
    # # # .
    # # # .

The top-right cell belongs to both the first row and the last column,
but assigning '.' twice does not change the result.

The algorithm constructs the grid directly without needing a separate
visited array or additional data structure.


Example:
--------
Input:
m = 3
n = 4

Step 1: Initialize the grid.

    [
        "####",
        "####",
        "####"
    ]

Step 2: Fill the first row with '.'.

    [
        "....",
        "####",
        "####"
    ]

Step 3: Fill the last column with '.'.

    [
        "....",
        "###.",
        "###."
    ]

Output:
    ["....", "###.", "###."]


Time Complexity:
----------------
O(m * n)

Initializing the grid requires O(m * n) time.
The two loops take O(n + m) time.

Therefore, the total time complexity is O(m * n).


Space Complexity:
-----------------
O(m * n)

The grid stores `m` strings, each containing `n` characters.
*/


class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        for(int j = 0; j < n; j++){
            grid[0][j] = '.';
        }
        for(int i = 0; i < m; i++){
            grid[i][n-1] = '.';
        }
        return grid;
    }
};
