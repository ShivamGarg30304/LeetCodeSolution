class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), cnt = 0;
        unordered_map<int, int> mp;
        for (auto x : nums4) {
            for (auto y : nums3) {
                mp[x + y]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int req = -(nums1[i] + nums2[j]);
                cnt += mp[req];
            }
        }
        return cnt;
    }
};