class Solution {
public:
    int m, n;
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& h,
             vector<vector<bool>>& vis,
             int r, int c) {

        vis[r][c] = true;

        for (auto &d : dir) {

            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (vis[nr][nc])
                continue;

            if (h[nr][nc] < h[r][c])
                continue;

            dfs(h, vis, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n));
        vector<vector<bool>> atl(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, pac, 0, j);
            dfs(heights, atl, m - 1, j);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};
