class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for(int i = 0; i < n;i++){
            vector<int> a(n, 0);
            ans.push_back(a);
        }
        int count = 1;
        int row = n - 1;
        int col = n - 1;
        int startcol = 0;
        int startrow = 0;
        int endcol = n - 1;
        int endrow = n - 1;
        while(count <= n * n){
            for(int i = startcol; count <= n * n && i <= endcol; i++){
                ans[startrow][i] = count;
                count++;
            }
            startrow++;
            for(int i = startrow; count <= n * n && i <= endrow; i++){
                ans[i][endcol] = count;
                count++;
            }
            endcol--;
            for(int i = endcol; count <= n * n && i >= startcol; i--){
                ans[endrow][i] = count;
                count++;
            }
            endrow--;
            for (int i = endrow; count <= n * n && i >= startrow; i--){
                ans[i][startcol] = count;
                count++;
            }
            startcol++;
        }
        return ans;
    }
};