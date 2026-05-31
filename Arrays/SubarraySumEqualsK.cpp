/*
Problem: LeetCode 560 - Subarray Sum Equals K

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> prefixCount;

        prefixCount[0] = 1;

        int currentSum = 0;
        int answer = 0;

        for(int num : nums) {

            currentSum += num;

            if(prefixCount.count(currentSum - k))
                answer += prefixCount[currentSum - k];

            prefixCount[currentSum]++;
        }

        return answer;
    }
};
