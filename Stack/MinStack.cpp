/*
LeetCode 155

Time Complexity:
push  -> O(1)
pop   -> O(1)
top   -> O(1)
getMin-> O(1)
*/

class MinStack {
public:

    stack<int> st;
    stack<int> minSt;

    MinStack() {}

    void push(int val) {

        st.push(val);

        if(minSt.empty())
            minSt.push(val);

        else
            minSt.push(min(val, minSt.top()));
    }

    void pop() {

        st.pop();
        minSt.pop();
    }

    int top() {

        return st.top();
    }

    int getMin() {

        return minSt.top();
    }
};
