/*
Problem:
LeetCode 49 - Group Anagrams

Time Complexity: O(n*k log k)
Space Complexity: O(n*k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(
        vector<string>& strs) {

        unordered_map<string,
                      vector<string>> mp;

        for(string str : strs) {

            string key = str;

            sort(key.begin(), key.end());

            mp[key].push_back(str);
        }

        vector<vector<string>> result;

        for(auto it : mp)
            result.push_back(it.second);

        return result;
    }
};
