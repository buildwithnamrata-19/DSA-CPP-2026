/*
Problem:
LeetCode 217 - Contains Duplicate

Approach:
Store elements in an unordered_set.
If an element already exists, return true.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> st;

        for(int num : nums) {

            if(st.count(num))
                return true;

            st.insert(num);
        }

        return false;
    }
};
