/*
Problem:
LeetCode 128 - Longest Consecutive Sequence

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int num : st) {

            if(!st.count(num - 1)) {

                int current = num;
                int length = 1;

                while(st.count(current + 1)) {

                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
