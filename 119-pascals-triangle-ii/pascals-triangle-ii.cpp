class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> ans(n + 1);
        long long res = 1;
        ans[0] = 1;
        for (int i = 1; i <= n; i++) {
            res *= (n - i + 1);
            res /= i;
            ans[i] = res;
        }
        return ans;
    }
};