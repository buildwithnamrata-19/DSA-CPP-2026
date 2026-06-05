/*
Problem:
LeetCode 438 - Find All Anagrams in a String

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> result;
        vector<int> pCount(26,0);
        vector<int> sCount(26,0);

        for(char c : p)
            pCount[c-'a']++;

        int k = p.size();

        for(int i=0;i<s.size();i++) {

            sCount[s[i]-'a']++;

            if(i >= k)
                sCount[s[i-k]-'a']--;

            if(sCount == pCount)
                result.push_back(i-k+1);
        }

        return result;
    }
};
