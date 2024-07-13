class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> st;
        for (auto x : nums) st.insert(x);
        for (auto x : st) {
            if (st.find(x - 1) != st.end()) continue;
            int cnt = 1;
            while (st.find(x + 1) != st.end()) {
                cnt += 1;
                x += 1;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};