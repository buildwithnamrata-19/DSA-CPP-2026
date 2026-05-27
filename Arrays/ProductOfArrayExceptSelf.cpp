/*
Problem:
LeetCode 238 - Product of Array Except Self

Approach:
Use prefix and suffix products.
Store left product first, then multiply with right product.

Time Complexity: O(n)
Space Complexity: O(1) excluding output array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> answer(n, 1);

        int prefix = 1;

        for(int i = 0; i < n; i++) {

            answer[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;

        for(int i = n - 1; i >= 0; i--) {

            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};
