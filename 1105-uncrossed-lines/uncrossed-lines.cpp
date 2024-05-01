class Solution {
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2) {
        if (i >= nums1.size() or j >= nums2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, nums1, nums2);
        }
        return dp[i][j] = max(solve(i + 1, j, nums1, nums2), solve(i, j + 1, nums1, nums2));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp = vector<vector<int>> (501, vector<int> (501, -1));
        return solve(0, 0, nums1, nums2);
    }
};