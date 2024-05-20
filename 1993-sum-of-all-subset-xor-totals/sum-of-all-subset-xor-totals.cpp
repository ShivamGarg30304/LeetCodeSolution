class Solution {
private:
    int solve(int i, int xr, vector<int> &nums) {
        if (i >= nums.size()) return xr;
        return solve(i + 1, xr, nums) + solve(i + 1, xr ^ nums[i], nums);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(0, 0, nums);
    }
};