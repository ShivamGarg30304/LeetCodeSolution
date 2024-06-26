class Solution {
public:
    void reverseString(vector<char> &s) {
        int n = s.size(), start = 0, end = n - 1;
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return;
    }
};