class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
            if (num > 0) {
                if (mp[-num]) {
                    ans = max(ans, abs(num));
                }
            } else if (num < 0){
                if (mp[-num]) {
                    ans = max(ans, abs(num));
                }
            }
        }
        return ans;
    }
};