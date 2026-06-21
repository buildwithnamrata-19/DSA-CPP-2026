class Solution {
public:
    int orangesRotting(
        vector<vector<int>>& grid) {

        queue<pair<int,int>> q;

        int fresh = 0;
        int minutes = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 2)
                    q.push({i,j});

                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};

        while(!q.empty() && fresh > 0) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                auto [x,y] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(nx >= 0 &&
                       ny >= 0 &&
                       nx < rows &&
                       ny < cols &&
                       grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;

                        q.push({nx,ny});
                    }
                }
            }

            minutes++;
        }

        return fresh == 0
               ? minutes
               : -1;
    }
};
