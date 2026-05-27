/*
Problem:
LeetCode 125 - Valid Palindrome

Approach:
Use two pointers from both ends.
Skip non-alphanumeric characters and compare lowercase characters.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while(left < right) {

            while(left < right && !isalnum(s[left]))
                left++;

            while(left < right && !isalnum(s[right]))
                right--;

            if(tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};
