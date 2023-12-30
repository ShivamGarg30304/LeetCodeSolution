class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26, 0);
        for (auto str : words) {
            for (auto ch : str) {
                cnt[ch - 'a']++;
            }
        }
        int n = words.size();
        for (auto x : cnt) {
            if (x % n != 0) return false;
        }
        return true;
    }
};
