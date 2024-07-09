class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) cnt++;
            if (nums[i] == 0) cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};