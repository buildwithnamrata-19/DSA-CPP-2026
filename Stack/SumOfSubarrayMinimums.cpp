/*
LeetCode 907

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int sumSubarrayMins(
        vector<int>& arr) {

        const int MOD =
            1000000007;

        int n = arr.size();

        stack<int> st;

        vector<int> left(n);
        vector<int> right(n);

        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  arr[st.top()] >
                  arr[i]) {

                st.pop();
            }

            left[i] =
                st.empty()
                ? i + 1
                : i - st.top();

            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i = n - 1;
            i >= 0;
            i--) {

            while(!st.empty() &&
                  arr[st.top()] >=
                  arr[i]) {

                st.pop();
            }

            right[i] =
                st.empty()
                ? n - i
                : st.top() - i;

            st.push(i);
        }

        long long answer = 0;

        for(int i = 0;
            i < n;
            i++) {

            answer =
            (answer +
            (long long)
            arr[i] *
            left[i] *
            right[i])
            % MOD;
        }

        return answer;
    }
};
