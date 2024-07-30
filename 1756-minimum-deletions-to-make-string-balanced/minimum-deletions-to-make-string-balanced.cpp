class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length(), a_count = 0;
        for (int i = 0; i < n; i++) {
            a_count += (s[i] == 'a');
        }
        int b_count = 0;
        int min_deletions = n;
        for (int i = 0; i < n; i++) {
            a_count -= (s[i] == 'a');
            min_deletions = min(min_deletions, a_count + b_count);
            b_count += (s[i] == 'b');
        }

        return min_deletions;
    }
};