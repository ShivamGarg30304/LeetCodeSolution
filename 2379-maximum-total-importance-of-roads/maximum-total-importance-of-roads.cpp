class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for (auto road : roads) {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
        }
        sort(degree.begin(), degree.end());
        long long ans = 0;
        long long val = 1;
        for (auto deg : degree) {
            ans = ans + (val * deg);
            val++;
        }
        return ans;
    }
};