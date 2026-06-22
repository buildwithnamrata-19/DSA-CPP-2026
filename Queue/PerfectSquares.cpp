class Solution {
public:

    int numSquares(int n) {

        vector<int> squares;

        for(int i = 1;
            i * i <= n;
            i++) {

            squares.push_back(i * i);
        }

        queue<int> q;
        vector<bool> visited(
            n + 1,
            false);

        q.push(n);
        visited[n] = true;

        int level = 0;

        while(!q.empty()) {

            level++;

            int size = q.size();

            while(size--) {

                int curr =
                    q.front();

                q.pop();

                for(int sq : squares) {

                    int next =
                        curr - sq;

                    if(next == 0)
                        return level;

                    if(next < 0)
                        break;

                    if(!visited[next]) {

                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return level;
    }
};
