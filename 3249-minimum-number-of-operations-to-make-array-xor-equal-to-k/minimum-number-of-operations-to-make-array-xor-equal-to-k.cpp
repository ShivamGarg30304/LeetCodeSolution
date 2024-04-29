class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mp(30, 0), mp2(30, 0);
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < n; j++) {
                int newnum = 1 << i;
                if (nums[j] & newnum) {
                    mp[i]++;
                }
            }
        }
        for (int i = 0; i < 30; i++) {
            int newnum = 1 << i;
            if (k & newnum) {
                mp2[i]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            int num = i;
            int x = mp[i];
            int u, v;
            if (x % 2 == 0) u = 0;
            else u = 1;
            v = 0;
            if (mp2[num] == 1) {
                if (u == v) ans++;
            } else {
                if (u != v) ans++;
            }
        }
        return ans;
    }
};