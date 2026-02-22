/*
Problem: Score Difference Between Two Players


Approach:
1. Traverse the nums array.
2. Maintain turn of player1 using a boolean flag.
3. If number is odd, switch turn.
4. If index is multiple of 6 (i % 6 == 5), switch turn.
5. Add current number to respective player's score.
6. Return difference between player1 and player2.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int scoreDifference(vector<int>& nums){
        int player1 = 0;
        int player2 = 0;
        int n = nums.size();
        bool isplayer1turn = true;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 != 0) isplayer1turn = !isplayer1turn;
            if(i % 6 == 5) isplayer1turn = !isplayer1turn;
            if(isplayer1turn) player1 += nums[i];
            else player2 += nums[i];
        }
        return player1 - player2;
    }
};
