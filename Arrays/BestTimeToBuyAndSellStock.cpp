/*
Problem:
LeetCode 121 - Best Time to Buy and Sell Stock

Approach:
Track the minimum price seen so far.
Calculate maximum profit at each step.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int price : prices) {

            minPrice = min(minPrice, price);

            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
