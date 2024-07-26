class Solution {
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 and arr[st.top()] > arr[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() > 0 and arr[st.top()] >= arr[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        vector<int> prev = prevSmaller(arr);
        vector<int> next = nextSmaller(arr);
        for (int i = 0; i < n; i++) {
            if (next[i] == -1) next[i] = n;
            int cnt1 = next[i] - i;
            int cnt2 = max(1, i - prev[i]);
            ans += 1LL * cnt1 * cnt2 * arr[i];
            ans = ans % 1000000007;
        }
        return ans;
    }
};