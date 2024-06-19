class Solution {
    int Possible(vector<int> &bloomDay, int day, int M, int K) {
        int counter = 0;
        int bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                counter++;
            } else {
                bouquets += counter / K;
                counter = 0;
            }
        }
        bouquets += counter / K;
        return bouquets >= M;
    } 
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long required = 1LL * m * k;
        if (required > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (Possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};