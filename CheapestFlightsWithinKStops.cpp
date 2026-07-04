class Solution {
public:
    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        vector<vector<pair<int,int>>> graph(n);

        for (auto &f : flights)
            graph[f[0]].push_back({f[1], f[2]});

        queue<vector<int>> q;
        q.push({src, 0, 0});

        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        while (!q.empty()) {

            auto cur = q.front();
            q.pop();

            int node = cur[0];
            int price = cur[1];
            int stops = cur[2];

            if (stops > k)
                continue;

            for (auto &[next, wt] : graph[node]) {

                if (price + wt < cost[next]) {

                    cost[next] = price + wt;
                    q.push({next, cost[next], stops + 1});
                }
            }
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
