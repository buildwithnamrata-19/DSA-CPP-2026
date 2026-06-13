/*
Problem:
LeetCode 496 - Next Greater Element I

Approach:
Monotonic Stack

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElement(
        vector<int>& nums1,
        vector<int>& nums2) {

        unordered_map<int, int> nextGreater;
        stack<int> st;

        for(int num : nums2) {

            while(!st.empty() &&
                  st.top() < num) {

                nextGreater[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        while(!st.empty()) {

            nextGreater[st.top()] = -1;
            st.pop();
        }

        vector<int> answer;

        for(int num : nums1)
            answer.push_back(
                nextGreater[num]
            );

        return answer;
    }
};
