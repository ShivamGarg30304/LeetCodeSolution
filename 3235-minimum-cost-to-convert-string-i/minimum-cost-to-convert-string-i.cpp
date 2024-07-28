#define ll long long
class Solution {
    map<pair<int, int>, ll> mp;
    vector<vector<pair<int, int>>> graph;
    void Dijkstras(int source) {
        priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        vector<ll> distance(26, LONG_MAX);
        distance[source] = 0;
        pq.push({0, source});
        while (!pq.empty()) {
            int u = pq.top().second;
            ll dist = pq.top().first;
            pq.pop();
            for (auto it : graph[u]) {
                int v = it.first;
                int d = it.second;
                if (dist + d < distance[v]) {
                    distance[v] = dist + d;
                    pq.push({distance[v], v});
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            mp[{source, i}] = distance[i];
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        graph = vector<vector<pair<int, int>>> (26);
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w = cost[i];
            graph[u].push_back({v, w});
        }
        for (int i = 0; i < 26; i++) {
            Dijkstras(i);
        }
        ll ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (mp[{u, v}] == LONG_MAX) {
                return -1;
            }
            ans += mp[{u, v}];
        }
        return ans;
    }
};