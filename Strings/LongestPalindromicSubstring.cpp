/*
Problem:
LeetCode 5 - Longest Palindromic Substring

Approach:
Expand Around Center

Time Complexity: O(n²)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string expand(string s, int left, int right) {

        while(left >= 0 &&
              right < s.size() &&
              s[left] == s[right]) {

            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {

        string answer = "";

        for(int i = 0; i < s.size(); i++) {

            string odd = expand(s, i, i);

            if(odd.size() > answer.size())
                answer = odd;

            string even = expand(s, i, i + 1);

            if(even.size() > answer.size())
                answer = even;
        }

        return answer;
    }
};
