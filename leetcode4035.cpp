/*
Problem: 4035. Maximum Valid Split Positions I
Approach:
---------
1. Try every possible removal:
   - `remove = -1` means we do not remove anything.
   - `remove = 0, 1, 2, ...` means we remove that particular index.
   
   This ensures that every possible array after removing at most one
   element is checked.

2. Build the resulting array `arr`:
   - Copy every element from `nums` except the element at `remove`.

3. If the resulting array has fewer than 2 elements:
   - There is no possible split.
   - So skip this case.

4. Build the Prefix GCD array:
   - `pref[i]` stores the GCD of all elements from `arr[0]` to `arr[i]`.
   
   Therefore, for a split after index `i`:
       leftGCD = pref[i]

5. Build the Suffix GCD array:
   - `suff[i]` stores the GCD of all elements from `arr[i]` to
     `arr[m-1]`.
   
   Therefore, for a split after index `i`:
       rightGCD = suff[i + 1]

6. Check every possible split:
   - A split is valid if:
       leftGCD == rightGCD
   - If they are equal, increase `score`.

7. Keep the maximum score:
   - For every possible removal, calculate the number of valid splits.
   - Update `ans` with the maximum score found.

Key Idea:
---------
The important trick is using Prefix GCD and Suffix GCD.

For a split:

    [elements on left] | [elements on right]

we need:

    GCD(left) == GCD(right)

Instead of calculating the GCD of both sides from scratch for every
split, we precompute:

    pref[i] = GCD(arr[0...i])
    suff[i] = GCD(arr[i...m-1])

Then every split can be checked in O(1):

    leftGCD  = pref[i]
    rightGCD = suff[i + 1]

Since we also need to consider removing at most one element, we simply
try every possible removal and calculate the answer for that resulting
array.

Example:
--------
nums = [2, 4, 6, 8]

First, consider no removal:

arr = [2, 4, 6, 8]

Prefix GCD:
pref = [2, 2, 2, 2]

Suffix GCD:
suff = [2, 2, 2, 8]

Now check splits:

i = 0:
leftGCD  = 2
rightGCD = 2
Valid split -> score++

i = 1:
leftGCD  = 2
rightGCD = 2
Valid split -> score++

i = 2:
leftGCD  = 2
rightGCD = 8
Invalid split

So this particular array has 2 valid splits.

The algorithm repeats the same process after removing each possible
element and keeps the maximum number of valid splits.

Time Complexity:
----------------
There are O(n) possible removal choices.

For every removal:
- Building `arr`: O(n)
- Building Prefix GCD: O(n)
- Building Suffix GCD: O(n)
- Checking all splits: O(n)

Therefore:

    O(n) × O(n) = O(n²)

Total Time Complexity = O(n²)

Space Complexity:
-----------------
O(n)

We create:
- `arr`
- `pref`
- `suff`

Each can contain at most n elements.
*/

class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // remove = -1 means: don't remove anything
        // remove = 0,1,2... means: remove that index
        for (int remove = -1; remove < n; remove++) {
            // Build array after removing at most one element
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                if (i != remove) {
                    arr.push_back(nums[i]);
                }
            }
            int m = arr.size();
            if (m < 2)
                continue;

            // Prefix GCD
            vector<int> pref(m);
            pref[0] = arr[0];
            for (int i = 1; i < m; i++) {
                pref[i] = gcd(pref[i - 1], arr[i]);
            }

            // Suffix GCD
            vector<int> suff(m);
            suff[m - 1] = arr[m - 1];
            for (int i = m - 2; i >= 0; i--) {
                suff[i] = gcd(suff[i + 1], arr[i]);
            }

            // Score of THIS particular arr
            int score = 0;
            for (int i = 0; i < m - 1; i++) {
                int leftGCD = pref[i];
                int rightGCD = suff[i + 1];
                if (leftGCD == rightGCD) {
                    score++;
                }
            }
            // We want maximum score among all possibilities
            ans = max(ans, score);
        }
        return ans;
    }
};
