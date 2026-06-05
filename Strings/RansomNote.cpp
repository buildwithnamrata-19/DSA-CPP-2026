/*
Problem:
LeetCode 383 - Ransom Note

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> freq(26, 0);

        for(char c : magazine)
            freq[c - 'a']++;

        for(char c : ransomNote) {

            if(freq[c - 'a'] == 0)
                return false;

            freq[c - 'a']--;
        }

        return true;
    }
};
