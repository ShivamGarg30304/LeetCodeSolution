class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());

        int count = 0;
        for (int i = 0; i < sortedHeights.size(); ++i) {
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        return count;
    }
};