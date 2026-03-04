/*
Problem: Find Pair of Numbers with Different Frequencies


Approach:
1. Count frequency of each number using a hashmap.
2. Store all distinct numbers in a vector.
3. Sort the distinct numbers.
4. Check every pair of numbers.
5. Return the first pair whose frequencies are different.
6. If no such pair exists, return {-1, -1}.

Time Complexity: O(N + D^2)
Space Complexity: O(D)
*/


class Solution{
public:
    vector<int> minDistinctFreqPair(vector<int>& nums){
        unordered_map<int,int> freq;
        for(int x : nums){
            freq[x]++;
        }

        vector<int> distinct;
        for(auto &p : freq){
            distinct.push_back(p.first);
        }

        sort(distinct.begin(), distinct.end());

        int n = distinct.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x = distinct[i];
                int y = distinct[j];
                if(freq[x] != freq[y]){
                    return {x, y};
                }
            }
        }

        return {-1, -1};
    }
};
