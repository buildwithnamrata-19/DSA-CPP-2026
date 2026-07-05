class Solution {
public:

    vector<int> parent;
    vector<int> rankv;

    int find(int x) {

        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int a, int b) {

        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return false;

        if (rankv[pa] < rankv[pb])
            swap(pa, pb);

        parent[pb] = pa;

        if (rankv[pa] == rankv[pb])
            rankv[pa]++;

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        rankv.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &edge : edges) {

            if (!unite(edge[0], edge[1]))
                return edge;
        }

        return {};
    }
};
