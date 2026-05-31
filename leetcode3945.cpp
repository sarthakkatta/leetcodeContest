/*
Problem: Digit Frequency Score

Approach:
1. Create frequency array of size 10:
   - arr[i] stores count of digit i.
2. Extract digits of number:
   - Increment frequency of each digit.
3. Compute score:
   - score += digit × frequency
4. Return final score.

Key Idea:
- Weighted sum of digit frequencies.

Time Complexity: O(D)
  (D = number of digits)
Space Complexity: O(1)
*/

class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> arr(10,0);
        int num = n;
        while(num != 0){
            arr[num%10]++;
            num /= 10;
        }
        int sum = 0;
        for(int i = 0; i<10; i++){
            sum += i*arr[i];
        }
        return sum;
    }
};
