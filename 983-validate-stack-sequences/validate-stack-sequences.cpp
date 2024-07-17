class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) return false;
        int n = pushed.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[pushed[i]] = i;
        }
        int curr = 0;
        stack<int> st;
        for (int i = 0; i < popped.size(); i++) {
            int index = mp[popped[i]];
            if (index >= curr) {
                for (; curr <= index; curr++) {
                    st.push(pushed[curr]);
                }
                if (st.size() > 0 and st.top() == popped[i]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                if (st.size() > 0 && st.top() == popped[i]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};