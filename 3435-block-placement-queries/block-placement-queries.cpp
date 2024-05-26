class FenwickTree{
public:
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this -> n = n;
        bit = vector<int> (n + 1, 0);
    }

    void add(int id, int val) {
        while (id <= n) {
            bit[id] = max(bit[id], val);
            id += (id & -id);
        }
    }

    int query(int id) {
        int maxAns = 0;
        while (id > 0) {
            maxAns = max(maxAns, bit[id]);
            id -= (id & -id);
        }
        return maxAns;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obstaclePoints;
        int n = min(5 * 10000, 3 * (int)queries.size()) + 1;
        obstaclePoints.insert(0), obstaclePoints.insert(n);

        FenwickTree ft(n);

        for (auto q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                obstaclePoints.insert(x);
            }
        }

        for (auto it = obstaclePoints.begin(); it != obstaclePoints.end(); ++it) {
            if (it == obstaclePoints.begin()) continue;

            auto prevIt = prev(it);
            int x = *it, gapSize = (*it - *prevIt);
            ft.add(x, gapSize);
        }

        vector<bool> ans;
        for (int i = queries.size() - 1; i >= 0; i--) {
            vector<int> &q = queries[i];
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                auto it = obstaclePoints.find(x);
                auto prv = prev(it);
                auto nxt = next(it);
                obstaclePoints.erase(it);
                ft.add(*nxt, (*nxt - *prv));
            } else {
                int x = q[1], sz = q[2];
                auto nxt = obstaclePoints.upper_bound(x);
                auto prv = prev(nxt);

                int maxGap = max(ft.query(*prv), x - *prv);
                ans.push_back(maxGap >= sz);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};