class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }
        for (auto x : nums) {
            cout << x << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) == n + 1) continue;
            int value = abs(nums[i]) - 1;
            cout << value << endl;
            if (nums[value] > 0) nums[value] = -nums[value];
        }
        for (int i = 0; i < n; i++) {
            // if (nums[i] == n + 1) continue;
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};