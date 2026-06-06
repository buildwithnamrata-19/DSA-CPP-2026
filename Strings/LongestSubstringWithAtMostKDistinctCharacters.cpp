/*
Problem:
Longest Substring With At Most K Distinct Characters

Approach:
Variable Sliding Window

Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(
        string s,
        int k
    ) {

        unordered_map<char,int> freq;

        int left = 0;
        int answer = 0;

        for(int right = 0;
            right < s.size();
            right++) {

            freq[s[right]]++;

            while(freq.size() > k) {

                freq[s[left]]--;

                if(freq[s[left]] == 0)
                    freq.erase(s[left]);

                left++;
            }

            answer = max(
                answer,
                right - left + 1
            );
        }

        return answer;
    }
};
