class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPro = 0;
        int minimum_price = INT_MAX;
        for (int i = 0; i < n; i++) {
            minimum_price = min(minimum_price, prices[i]);
            int curr_prof = prices[i] - minimum_price;
            maxPro = max(maxPro, curr_prof);
        }
        return maxPro;
    }
};