class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp; 
        for (auto ch : s) {
            mp[ch]++;
        }
        int ans = 0;
        int one = 0;
        for (auto m : mp) {
            ans += m.second / 2 * 2;
            if (m.second % 2 == 1) {
                one++;
            }
        }
        if (one) {
            return ans + 1;
        }
        return ans;
    }
};