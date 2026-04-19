/*
Problem: 3903. Smallest Stable Index I

Approach:
1. Create two arrays:
   - maxi[i] → maximum value from index 0 to i
   - mini[i] → minimum value from index i to n-1
2. Fill maxi:
   - maxi[i] = max(nums[i], maxi[i-1])
3. Fill mini:
   - mini[i] = min(nums[i], mini[i+1])
4. For each index i:
   - Compute score = maxi[i] - mini[i]
   - If score <= k → valid index
5. Track the smallest such index.
6. If no valid index → return -1.

Key Idea:
- Precompute prefix max and suffix min for efficient queries.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maxi(n,INT_MIN);
        vector<int> mini(n,INT_MAX);
        maxi[0]=nums[0];
        mini[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
                maxi[i] = max(nums[i],maxi[i-1]);
            }
        for(int i=n-2;i>=0;i--){
                mini[i] = min(nums[i],mini[i+1]);
            }
        int idx=n;
        for(int i=0;i<n;i++){
                int score = maxi[i]-mini[i];
                if(score<=k){
                    idx=min(idx,i);
                }
            }
        return idx==n?-1:idx;
    }
};
