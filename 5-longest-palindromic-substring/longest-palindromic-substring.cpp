class Solution {
    int dp[1001][1001];
    bool solve(string &s, int l, int r) {
        if (l >= r) {
            return 1;
        }
        if (dp[l][r] != -1) return dp[l][r];
        
        if (s[l] == s[r]) {
            return dp[l][r] = solve(s, l + 1, r - 1);
        } else {
            return false;
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = INT_MIN;
        int startingIndex = 0;
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (j - i + 1 > maxLen) {
                        startingIndex = i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(startingIndex, maxLen);
    }
};