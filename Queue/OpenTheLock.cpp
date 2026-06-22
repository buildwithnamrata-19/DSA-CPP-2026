class Solution {
public:

    int openLock(
        vector<string>& deadends,
        string target) {

        unordered_set<string> dead(
            deadends.begin(),
            deadends.end());

        if(dead.count("0000"))
            return -1;

        queue<string> q;
        unordered_set<string> visited;

        q.push("0000");
        visited.insert("0000");

        int steps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                string curr =
                    q.front();

                q.pop();

                if(curr == target)
                    return steps;

                for(int i = 0; i < 4; i++) {

                    string up = curr;
                    string down = curr;

                    up[i] =
                    (curr[i] - '0' + 1) % 10 + '0';

                    down[i] =
                    (curr[i] - '0' + 9) % 10 + '0';

                    if(!dead.count(up)
                       && !visited.count(up)) {

                        visited.insert(up);
                        q.push(up);
                    }

                    if(!dead.count(down)
                       && !visited.count(down)) {

                        visited.insert(down);
                        q.push(down);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
