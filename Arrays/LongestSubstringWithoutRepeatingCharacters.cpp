/*
Problem:
LeetCode 3 - Longest Substring Without Repeating Characters

Approach:
Variable Size Sliding Window

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int left = 0;
        int answer = 0;

        for(int right=0; right<s.size(); right++) {

            while(st.count(s[right])) {

                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            answer = max(answer, right-left+1);
        }

        return answer;
    }
};
