/*
Problem:
LeetCode 152 - Maximum Product Subarray

Approach:
Track both maximum and minimum products.
Negative numbers can swap minimum and maximum.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currentMax = nums[0];
        int currentMin = nums[0];
        int answer = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] < 0)
                swap(currentMax, currentMin);

            currentMax = max(nums[i], currentMax * nums[i]);

            currentMin = min(nums[i], currentMin * nums[i]);

            answer = max(answer, currentMax);
        }

        return answer;
    }
};
