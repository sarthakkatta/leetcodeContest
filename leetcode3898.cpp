/*
Problem: Find the Degree of Each Vertex

Approach:
1. Given an adjacency matrix of a graph:
   - matrix[i][j] represents connection between node i and j.
2. For each row i:
   - Sum all elements in that row.
   - This gives degree of node i (number of connections).
3. Store each row sum in result vector.
4. Return the result.

Time Complexity: O(N * M)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> res;
        for(int i = 0 ; i < matrix.size(); i++){
            int sum = 0; 
            for(int j = 0; j < matrix[0].size(); j++){
                sum += matrix[i][j];
            }
            res.push_back(sum);
        }
        return res;
    }
};
