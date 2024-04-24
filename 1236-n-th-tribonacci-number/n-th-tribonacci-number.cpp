class Solution {
    int dp[38];
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
    }
    int tribonacci(int n) {
        if (n <= 2) return dp[n];
        if (dp[n] != -1) return dp[n];
        else return dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};