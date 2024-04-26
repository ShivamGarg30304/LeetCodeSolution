class Solution {
    int maxSum(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (a[i] - b[i]);
            cout << sum << endl;
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        return ans;
    }
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int ans1 = sum1 + maxSum(nums2, nums1);
        int ans2 = sum2 + maxSum(nums1, nums2);
        return max(ans1, ans2);
    }
};