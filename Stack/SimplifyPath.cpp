/*
Problem:
LeetCode 71 - Simplify Path

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string simplifyPath(string path) {

        vector<string> st;
        string current = "";

        path += '/';

        for(char c : path) {

            if(c == '/') {

                if(current == "..") {

                    if(!st.empty())
                        st.pop_back();
                }

                else if(
                    !current.empty() &&
                    current != "."
                ) {

                    st.push_back(current);
                }

                current = "";
            }

            else {

                current += c;
            }
        }

        string result = "";

        for(string dir : st) {

            result += "/" + dir;
        }

        return result.empty()
               ? "/"
               : result;
    }
};
