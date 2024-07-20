class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        m--; n--;
        long long horizontalSections = 1, verticalSections = 1;
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        int i = 0, j = 0;
        long long ans = 0;
        while (i < m && j < n) {
            if (horizontalCut[i] > verticalCut[j]) {
                ans += (horizontalCut[i] * verticalSections);
                horizontalSections++;
                i++;
            } else {
                ans += (verticalCut[j] * horizontalSections);
                verticalSections++;
                j++;
            }
        }
        while (i < m) {
            ans += (horizontalCut[i] * verticalSections);
            horizontalSections++;
            i++;
        }
        while (j < n) {
            ans += (verticalCut[j] * horizontalSections);
            verticalSections++;
            j++;
        }
        return ans;
    }
};