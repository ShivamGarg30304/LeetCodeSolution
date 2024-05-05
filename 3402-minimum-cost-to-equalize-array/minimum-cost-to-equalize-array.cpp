#define ll long long
class Solution {
    ll total_sum, mn, mx, n;
    ll cost1, cost2;
    ll ans = 1e18;
    void solve(ll t) {
        ll sum = t * n - total_sum;
        ll maxi = t - mn;
        ll temp;
        if (maxi > sum - maxi) {
            temp = (sum - maxi) * cost2 + (maxi - (sum - maxi)) * cost1;
        } else {
            temp = sum / 2 * cost2 + (sum % 2) * cost1;
        }
        // cout << temp << endl;
        ans = min(ans, temp);
    }
public:
    int minCostToEqualizeArray(vector<int>& nums, int cos1, int cos2) {
        n = nums.size();
        mx = *max_element(nums.begin(), nums.end());
        mn = *min_element(nums.begin(), nums.end());
        total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        cost1 = cos1; cost2 = cos2;
        if (cost1 * 2 <= cost2) {
            return (1LL * (1LL * mx * n - total_sum) * cost1) % 1000000007;
        }
        for (ll i = mx; i <= mx * 2; i++) {
            solve(i);
        }
        return ans % 1000000007;
    }
};