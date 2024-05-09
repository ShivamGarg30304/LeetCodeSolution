class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long prev = 0, ans = 0;
        for (int i = 0; i < k; i++) {
            if (happiness[i] - prev > 0) {
                ans += (happiness[i] - prev);
            } else {
                break;
            }
            prev++;
        }
        return ans;
    }
};