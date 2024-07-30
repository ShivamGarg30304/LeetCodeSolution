class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> count_a(n, 0);
        int a_count = 0;
        for (int i = n - 1; i >= 0; i--) {
            count_a[i] = a_count;
            if (s[i] == 'a') a_count++;
        }
        int b_count = 0;
        int min_deletions = n;
        for (int i = 0; i < n; i++) {
            min_deletions = min(min_deletions, count_a[i] + b_count);
            b_count += (s[i] == 'b');
        }

        return min_deletions;
    }
};