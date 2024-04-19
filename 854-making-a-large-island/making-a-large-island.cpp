class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};


class Solution {
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                for (auto move : moves) {
                    int newr = row + move.first;
                    int newc = col + move.second;
                    if (isValid(newr, newc, n) and grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjnodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjnodeNo);
                    }
                }
            }
        }
        // Step 2
        int ans = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                set<int> components;
                for (auto move : moves) {
                    int newr = row + move.first;
                    int newc = col + move.second;
                    if (isValid(newr, newc, n) and grid[newr][newc] == 1) {
                        int adjnodeNo = newr * n + newc;
                        components.insert(ds.findUPar(adjnodeNo));
                    }
                }
                int sizeTotal = 1;
                for (auto num : components) {
                    sizeTotal += ds.size[num];
                }
                ans = max(ans, sizeTotal);
            }
        }
        if (ans == 0) return n * n;
        return ans;
    }
};