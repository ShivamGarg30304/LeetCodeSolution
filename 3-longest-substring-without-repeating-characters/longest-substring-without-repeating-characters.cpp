class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int ans = 1;
        int i = 0, j = 0;
        vector<int> vec(256, -1);
        while (j < s.size()) {
            if (vec[s[j]] != -1) {
                if (vec[s[j]] >= i) {
                    i = vec[s[j]] + 1;
                }
            }
            ans = max(ans, j - i + 1);
            vec[s[j]] = j;
            j++;
        }
        return ans;
    }
};