class Solution {
public:
    vector<int> asteroidCollision(
        vector<int>& asteroids) {

        stack<int> st;

        for(int asteroid : asteroids) {

            bool destroyed = false;

            while(
                !st.empty() &&
                asteroid < 0 &&
                st.top() > 0
            ) {

                if(st.top() < -asteroid) {

                    st.pop();
                    continue;
                }

                else if(
                    st.top() ==
                    -asteroid
                ) {

                    st.pop();
                }

                destroyed = true;
                break;
            }

            if(!destroyed)
                st.push(asteroid);
        }

        vector<int> answer(
            st.size()
        );

        for(int i =
            st.size()-1;
            i >= 0;
            i--) {

            answer[i] =
                st.top();

            st.pop();
        }

        return answer;
    }
};
