class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Creating the vector for taking the adjacent of the particular element.
        vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {0, 0}};
        // Dimensions of the img.
        int m = img.size(), n  = img[0].size();
        // Creating an answer 2d vector
        vector<vector<int>> ans(m, vector<int> (n, 0));
        // Traversing the img
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int s = 0, cnt = 0; 
                // considering all the adajacent element
                for (auto x : dir) {
                    int new_i = i + x[0];
                    int new_j=  j + x[1];
                    // If possible increment the count and add the value to the sum
                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
                        s += img[new_i][new_j];
                        cnt++;
                    }
                }
                // Update the value in the answer matrix..
                ans[i][j] = s / cnt;
            }
        }
        // Return the final answer/
        return ans;
    }
};
