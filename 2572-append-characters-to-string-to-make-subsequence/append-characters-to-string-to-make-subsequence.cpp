class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        for (i = 0; i < n && j < m; i++) {
            if (s[i] == t[j]) j++;
        }
        return m - j;
    }
};