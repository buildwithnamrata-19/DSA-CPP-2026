/*
Problem:
LeetCode 11 - Container With Most Water

Approach:
Use two pointers from both ends.
Calculate area and move the smaller height pointer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int maximumWater = 0;

        while(left < right) {

            int width = right - left;

            int currentWater =
                min(height[left], height[right]) * width;

            maximumWater = max(maximumWater, currentWater);

            if(height[left] < height[right])
                left++;
            else
                right--;
        }

        return maximumWater;
    }
};
