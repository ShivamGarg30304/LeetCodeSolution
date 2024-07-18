class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 1e9, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return sum;
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
                if (sum > target) k--;
                else j++;
            }
        }
        return ans;
    }
};