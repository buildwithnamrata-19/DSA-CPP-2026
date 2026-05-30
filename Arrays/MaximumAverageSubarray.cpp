/*
Problem:
LeetCode 643 - Maximum Average Subarray I

Approach:
Fixed Size Sliding Window

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double windowSum = 0;

        for(int i=0;i<k;i++)
            windowSum += nums[i];

        double maxSum = windowSum;

        for(int i=k;i<nums.size();i++) {

            windowSum += nums[i];
            windowSum -= nums[i-k];

            maxSum = max(maxSum, windowSum);
        }

        return maxSum/k;
    }
};
