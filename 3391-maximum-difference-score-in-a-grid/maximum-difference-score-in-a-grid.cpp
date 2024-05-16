class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0 and grid[i][j] - grid[i - 1][j] + dp[i - 1][j] >= 0) {
                    cnt++;
                    dp[i][j] = grid[i][j] - grid[i - 1][j] + dp[i - 1][j];
                }
                if (j - 1 >= 0 and grid[i][j] - grid[i][j - 1] + dp[i][j - 1] >= 0) {
                    cnt++;
                    dp[i][j] = max(dp[i][j], grid[i][j] - grid[i][j - 1] + dp[i][j - 1]);
                }
            }
        }
        int ans = INT_MIN;
        if (cnt == 0) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (i - 1 >= 0) {
                        ans = max(ans, grid[i][j] - grid[i - 1][j]);
                    }
                    if (j - 1 >= 0) {
                        ans = max(ans, grid[i][j] - grid[i][j - 1]);
                    }
                }
            }
            return ans;
        }
        ans = 0;
        for (auto vec : dp) {
            for (auto p : vec) {
                ans = max(ans, p);
            }
        }
        return ans;
    }
};