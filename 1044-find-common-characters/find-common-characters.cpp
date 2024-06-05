class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> hsh(n, vector<int> (26, 0));
        for (int i = 0; i < n; i++) {
            for (auto ch : words[i]) {
                hsh[i][ch - 'a']++;
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            int mn = INT_MAX;
            for (int j = 0; j < n; j++) {
                mn = min(mn, hsh[j][i]);
            }
            for (int j = 0; j < mn; j++) {
                string temp = "";
                temp.push_back('a' + i);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};