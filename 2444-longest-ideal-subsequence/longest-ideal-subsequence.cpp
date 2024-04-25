class Solution {
    int solve(int i, string &s, char last, int k, vector<vector<int>> &dp) {
        if (i == s.size()) return 0;
        if (dp[i][last - 'a'] != -1) return dp[i][last - 'a'];
        int take = 0, nottake = 0;
        if (last == '{' or abs(s[i] - last) <= k) {
            take = 1 + solve(i + 1, s, s[i], k, dp);
        }
        nottake = solve(i + 1, s, last, k, dp);
        // return max(take, nottake);
        return dp[i][last - 'a'] = max(take, nottake);

    }
public:
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int> (28, -1));
        return solve(0, s, '{', k, dp);
    }
};