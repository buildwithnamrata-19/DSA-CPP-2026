/*
LeetCode 901
Time Complexity: O(1) Amortized
Space Complexity: O(n)
*/

class StockSpanner {
public:

    stack<pair<int,int>> st;

    StockSpanner() {}

    int next(int price) {

        int span = 1;

        while(!st.empty() &&
              st.top().first <= price) {

            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }
};
