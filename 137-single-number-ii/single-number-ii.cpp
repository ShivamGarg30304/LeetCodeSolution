class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int num : nums) {
                if (num & (1 << i)) sum++;
            }
            sum %= 3;
            ans = ans + (sum << i);
        }
        return ans;
    }
};