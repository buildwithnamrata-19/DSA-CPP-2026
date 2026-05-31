/*
Problem: LeetCode 56 - Merge Intervals
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for(auto interval : intervals) {

            if(result.empty() || result.back()[1] < interval[0])
                result.push_back(interval);

            else
                result.back()[1] =
                    max(result.back()[1], interval[1]);
        }

        return result;
    }
};
