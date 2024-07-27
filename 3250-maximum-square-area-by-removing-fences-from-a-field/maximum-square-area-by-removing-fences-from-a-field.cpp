class Solution {
    int MOD = 1000000007;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_map<int, bool> mp;
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                int length = hFences[j] - hFences[i];
                mp[length] = true;
            }
        }
        long long ans = -1;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int length = vFences[j] - vFences[i];
                if (mp.find(length) != mp.end()) {
                    ans = max(ans, 1LL * length);
                }
            }
        }
        if (ans == -1) return -1;
        return (ans * ans) % MOD;
    }
};