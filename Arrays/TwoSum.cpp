/*
Problem:
LeetCode 1 - Two Sum

Approach:
Use an unordered_map to store previously seen elements.
For each element, check whether target - currentElement
already exists in the map.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int required = target - nums[i];

            if(mp.count(required))
                return {mp[required], i};

            mp[nums[i]] = i;
        }

        return {};
    }
};
