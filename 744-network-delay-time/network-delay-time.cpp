class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto time : times) {
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (wt + dis < dist[v]) {
                    dist[v] = wt + dis;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dist[i]);
            cout << dist[i] << " ";
        }
        return (ans == 1e9) ? -1 : ans;
        cout << endl;
        return 0;
    }
};