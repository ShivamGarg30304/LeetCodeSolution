class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxi = *max_element(difficulty.begin(), difficulty.end());
        vector<int> maxProfit(maxi + 1, 0);

        for (int i = 0; i < difficulty.size(); ++i) {
            maxProfit[difficulty[i]] = max(maxProfit[difficulty[i]], profit[i]);
        }

        for (int i = 1; i <= maxi; ++i) {
            maxProfit[i] = max(maxProfit[i], maxProfit[i - 1]);
        }

        int totalProfit = 0;
        for (int ability : worker) {
            if (ability > maxi) {
                totalProfit += maxProfit[maxi];
            } else {
                totalProfit += maxProfit[ability];
            }
        }

        return totalProfit;
    }
};