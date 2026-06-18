/*
LeetCode 933

Time Complexity: O(1) Amortized
Space Complexity: O(n)
*/

class RecentCounter {
public:

    queue<int> q;

    RecentCounter() {}

    int ping(int t) {

        q.push(t);

        while(q.front() < t - 3000) {

            q.pop();
        }

        return q.size();
    }
};
