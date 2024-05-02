class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        int ans = 1;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                if (mp[s[j]] >= i) {
                    i = mp[s[j]] + 1;
                }
            }
            ans = max(ans, j - i + 1);
            mp[s[j]] = j;
            j++;
        }
        return ans;
    }
};