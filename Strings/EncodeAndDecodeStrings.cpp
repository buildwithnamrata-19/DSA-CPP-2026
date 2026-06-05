/*
Problem:
Encode and Decode Strings

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Codec {
public:

    string encode(vector<string>& strs) {

        string result;

        for(string s : strs)
            result += to_string(s.size()) + "#" + s;

        return result;
    }

    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while(i < s.size()) {

            int j = i;

            while(s[j] != '#')
                j++;

            int len = stoi(s.substr(i, j-i));

            result.push_back(
                s.substr(j+1, len)
            );

            i = j + 1 + len;
        }

        return result;
    }
};
