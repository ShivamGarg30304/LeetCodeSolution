class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int ans = 0, sum = 0;
        for (int i = 0; i < n - k; i++) {
            sum += cardPoints[i];
        }
        ans = max(ans, totalSum - sum);
        for (int i = n - k; i < n; i++) {
            sum = sum - cardPoints[i - (n - k)] + cardPoints[i];
            ans = max(ans, totalSum - sum);
        }
        return ans;
    }
};