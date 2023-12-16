// https://takeuforward.org/graph/flood-fill-algorithm-graphs/
class Solution {
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int inicolor, int newColor, vector<pair<int, int>> &moves) {
        ans[row][col] = newColor;
        int m = image.size(), n = image[0].size();
        for (auto move : moves) {
            int nrow = row + move.first;
            int ncol = col + move.second;
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, inicolor, newColor, moves);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int inicolor = image[sr][sc];
        vector<pair<int, int>> moves = {{+1, 0}, {0, +1}, {-1, 0}, {0, -1}};
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, inicolor, newColor, moves);
        return ans;
    }
};
