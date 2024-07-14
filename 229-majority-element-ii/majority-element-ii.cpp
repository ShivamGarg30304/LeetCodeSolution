class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int val1 = INT_MAX, cnt1 = 0;
        int val2 = INT_MAX, cnt2 = 0;
        for (auto num : nums) {
            if (cnt1 == 0 && num != val2) {
                cnt1 = 1; val1 = num;
            } else if (cnt2 == 0 && num != val1) {
                cnt2 = 1; val2 = num;
            } else if (num == val1) {
                cnt1++;
            } else if (num == val2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (auto num : nums) {
            if (num == val1) cnt1++;
            if (num == val2) cnt2++;
        }
        vector<int> ans;
        if (cnt1 > n / 3) ans.push_back(val1);
        if (cnt2 > n / 3) ans.push_back(val2);
        return ans;
    }
};