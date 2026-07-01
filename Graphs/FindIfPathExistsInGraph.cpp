class Solution {
public:
    bool dfs(int node, int destination,
             vector<vector<int>>& graph,
             vector<bool>& visited) {

        if (node == destination)
            return true;

        visited[node] = true;

        for (int next : graph[node]) {
            if (!visited[next]) {
                if (dfs(next, destination, graph, visited))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        return dfs(source, destination, graph, visited);
    }
};
