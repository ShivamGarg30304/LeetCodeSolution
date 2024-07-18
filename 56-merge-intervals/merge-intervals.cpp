class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (ans.size() == 0) {
                ans.push_back(intervals[i]);
            } else {
                auto last_interval = ans.back();
                int end = last_interval[1];
                int size = ans.size();
                if (intervals[i][0] > end) {
                    ans.push_back(intervals[i]);
                } else {
                    ans[size - 1][1] =  max(end, intervals[i][1]);
                }
            }
        }
        return ans;
    }
};