/*
Problem:
LeetCode 347 - Top K Frequent Elements

Time Complexity: O(n log k)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        for(int num : nums)
            freq[num]++;

        priority_queue<pair<int,int>> pq;

        for(auto it : freq)
            pq.push({it.second, it.first});

        vector<int> result;

        while(k--) {

            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
