/*
Problem:
LeetCode 153 - Find Minimum in Rotated Sorted Array

Approach:
Use Binary Search.
The minimum element lies in the unsorted half.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};
