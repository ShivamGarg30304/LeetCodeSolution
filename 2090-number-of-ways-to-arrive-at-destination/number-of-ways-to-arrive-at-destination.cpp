#define ll long long
int mod = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>> adj(n);
        for (auto road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vector<ll> ways(n, 0), dist(n, 1e14);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                ll wt = it.second;
                ll v = it.first;
                if (wt + dis < dist[v]) {
                    ways[v] = ways[node];
                    dist[v] = wt + dis;
                    pq.push({dist[v], v});
                }
                else if (wt + dis == dist[v]) {
                    ways[v] += ways[node];
                }
                ways[v] = ways[v] % mod;
            }
        }
        return ways[n - 1];
    }
};