/*
LeetCode 856

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;
        st.push(0);

        for(char c : s) {

            if(c == '(') {

                st.push(0);
            }

            else {

                int value =
                    st.top();

                st.pop();

                int score =
                    max(2 * value, 1);

                st.top() += score;
            }
        }

        return st.top();
    }
};
