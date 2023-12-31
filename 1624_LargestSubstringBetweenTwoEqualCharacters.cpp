class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int ans = -1;
        vector<int> v(26, -1);
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            if (v[ch] == -1) {
                v[ch] = i;
            } else {
                ans = max(ans, i - v[ch] - 1);
            }
        }
        return ans;
    }
};
