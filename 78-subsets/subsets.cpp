class Solution {
public:
    void solve(vector<int>& nums, vector<int> op, vector<vector<int>>& ans, int i )
    {
        if(i == nums.size())
        {
            ans.push_back(op);
            return ;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op1.push_back(nums[i]);
        solve(nums, op1, ans, i + 1);
        solve(nums, op2, ans, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        vector<int> op;
        solve(nums, op, ans, i);
        return ans;
    }
};