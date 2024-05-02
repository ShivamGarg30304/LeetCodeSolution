class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
            if (mp[-num]) {
                ans = max(ans, abs(num));
            }
        }
        return ans;
    }
};