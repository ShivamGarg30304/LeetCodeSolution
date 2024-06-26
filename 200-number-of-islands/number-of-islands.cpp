class Solution {
    void dfs(int i, int j, vector<vector<char>> &grid, int n, int m) {
        if (i >= n || j >= m) return;
        if (i < 0 || j < 0) return;
        if (grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(i - 1, j, grid, n, m);
        dfs(i + 1, j, grid, n, m);
        dfs(i, j - 1, grid, n, m);
        dfs(i, j + 1, grid, n, m);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};