// https://takeuforward.org/data-structure/rotten-oranges-min-time-to-rot-all-oranges-bfs/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            bool check = false;
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (auto move : moves) {
                    int nrow = row + move.first;
                    int ncol = col + move.second;
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n and grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        check = true;
                    }
                }
            }
            if (check) ans++;
        }
        for (auto vec : grid) {
            for (auto x : vec) {
                if (x == 1) return -1;
            }
        }
        return ans;
    }
};
