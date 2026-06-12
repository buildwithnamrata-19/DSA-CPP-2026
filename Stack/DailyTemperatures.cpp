/*
LeetCode 739

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> dailyTemperatures(
        vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> answer(n);

        stack<int> st;

        for(int i=n-1;i>=0;i--) {

            while(
                !st.empty() &&
                temperatures[st.top()]
                <= temperatures[i]
            )
                st.pop();

            if(!st.empty())
                answer[i] =
                    st.top() - i;

            st.push(i);
        }

        return answer;
    }
};
