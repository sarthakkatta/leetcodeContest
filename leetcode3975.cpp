/*
Problem: 3975. Filter Occupied Intervals

Approach:
1. Sort all occupied intervals by start time.
2. Merge overlapping or adjacent intervals:
   - If current interval starts after
     merged.back().second + 1:
       → Start a new merged interval.
   - Otherwise:
       → Extend the current merged interval.
3. After merging, remove the free interval
   [freeStart, freeEnd].
4. For each merged interval:
   a) No overlap with free interval:
      - Keep the interval as it is.
   b) Partial overlap on left:
      - Keep [l, freeStart - 1]
   c) Partial overlap on right:
      - Keep [freeEnd + 1, r]
   d) Complete overlap:
      - Remove that portion entirely.
5. Store all remaining occupied parts.
6. Return the final list of intervals.

Key Idea:
- First merge intervals to simplify processing.
- Then subtract the free interval from every
  merged occupied interval.

Time Complexity: O(N log N)
  (sorting dominates)

Space Complexity: O(N)
*/

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(
        vector<vector<int>>& occupiedIntervals,
        int freeStart,
        int freeEnd) {

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Step 1: Merge overlapping or adjacent intervals
        vector<pair<long long, long long>> merged;

        for (auto &it : occupiedIntervals) {
            long long start = it[0];
            long long end = it[1];

            if (merged.empty() || start > merged.back().second + 1) {
                merged.push_back({start, end});
            } else {
                merged.back().second =
                    max(merged.back().second, end);
            }
        }

        // Step 2: Remove free interval [freeStart, freeEnd]
        vector<vector<int>> ans;

        for (auto &[l, r] : merged) {

            // No overlap
            if (r < freeStart || l > freeEnd) {
                ans.push_back({(int)l, (int)r});
                continue;
            }

            // Left portion remains
            if (l < freeStart) {
                ans.push_back({(int)l, freeStart - 1});
            }

            // Right portion remains
            if (r > freeEnd) {
                ans.push_back({freeEnd + 1, (int)r});
            }
        }

        return ans;
    }
};
