#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0, cnt = 0, smallest = INT_MAX;
        for (auto num : nums) {
            if ((num ^ k) > num) {
                ans += (num ^ k);
                smallest = min(smallest, (ll)((num ^ k) - num));
                cnt++;
            } else {
                ans += num;
                smallest = min(smallest, (ll)(num - (num ^ k)));
            }
        }
        if (cnt % 2 == 0) return ans;
        return ans - smallest;
    }
};