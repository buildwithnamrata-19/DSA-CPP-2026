/*
Problem:
LeetCode 53 - Maximum Subarray

Approach:
Use Kadane's Algorithm.
Track current subarray sum and maximum sum.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = 0;
        int maximumSum = nums[0];

        for(int num : nums) {

            currentSum += num;

            maximumSum = max(maximumSum, currentSum);

            if(currentSum < 0)
                currentSum = 0;
        }

        return maximumSum;
    }
};
