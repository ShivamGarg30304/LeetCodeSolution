class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (abs(i - nums[i]) > 1) {
                return false;
            }
            i++;
        }
        return true;
    }
};