/*
Problem:
LeetCode 647 - Palindromic Substrings

Approach:
Expand Around Center

Time Complexity: O(n²)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countPalindrome(
        string s,
        int left,
        int right
    ) {

        int count = 0;

        while(
            left >= 0 &&
            right < s.size() &&
            s[left] == s[right]
        ) {

            count++;
            left--;
            right++;
        }

        return count;
    }

    int countSubstrings(string s) {

        int answer = 0;

        for(int i = 0; i < s.size(); i++) {

            answer += countPalindrome(
                s,
                i,
                i
            );

            answer += countPalindrome(
                s,
                i,
                i + 1
            );
        }

        return answer;
    }
};
