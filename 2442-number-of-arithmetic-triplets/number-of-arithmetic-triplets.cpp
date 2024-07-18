class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && nums[j] != nums[i] + diff) {
                j++;
            }
            int k = j + 1;
            while (k < n && nums[k] != nums[i] + 2 * diff) {
                k++;
            }
            if (k < n) cnt++;
        }
        return cnt;
    }
};