class Solution {
    vector<int> kmp(string s) {
        vector<int> lps(s.size(), 0);
        for (int i = 1; i < lps.size(); i++) {
            int prev_idx = lps[i - 1];

            while (prev_idx > 0 && s[i] != s[prev_idx]) {
                prev_idx = lps[prev_idx - 1];
            }

            lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
        }
        return lps;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string sa = a + "#" + s;
        string sb = b + "#" + s;
        vector<int> va, vb;

        vector<int> v = kmp(sa);
        for (int i = a.size(); i < v.size(); i++) {
            int el = v[i];
            if (el == a.size()) {
                int id = i - 2 * a.size();
                if (id >= 0) {
                    va.push_back(id);
                }
            }
        }

        v = kmp(sb);
        for (int i = b.size(); i < v.size(); i++) {
            int el = v[i];
            if (el == b.size()) {
                cout << "j" << endl;
                int id = i - 2 * b.size();
                if (id >= 0) {
                    cout << "jhh" << endl;
                    vb.push_back(id);
                }
            }
        }

        vector<int> ans;
        if (vb.size() == 0 || va.size() == 0) return ans;
        for (int i = 0; i < va.size(); i++) {
            auto bi = lower_bound(vb.begin(), vb.end(), va[i]) - vb.begin();
            if (bi != vb.size() && abs(va[i] - vb[bi]) <= k) {
                ans.push_back(va[i]);
                continue;
            }
            if (bi != 0 && abs(va[i] - vb[bi - 1]) <= k) ans.push_back(va[i]);
        }
        return ans;
    }
};