class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n, INT_MAX);
        for (int i = 1; i < n; i++) {
            prev[i] = min(prev[i - 1], nums[i - 1]);
        }
        vector<int> next(n, INT_MAX);
        for (int i = n - 2; i >= 0; i--) {
            next[i] = min(next[i + 1], nums[i + 1]);
        }
        int ans = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > prev[i] && nums[i] > next[i]) {
                ans = min(ans, prev[i] + nums[i] + next[i]);
            }
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};