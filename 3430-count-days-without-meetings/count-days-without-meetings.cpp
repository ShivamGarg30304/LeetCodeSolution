class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        int last_day = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (last_day >= meetings[i][0]) {
                last_day = max(last_day, meetings[i][1]);
            } else {
                ans += (meetings[i][0] - last_day - 1);
                last_day = meetings[i][1];
            }
        }
        ans += (days - last_day);
        return ans;
    }
};