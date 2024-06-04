class Solution {
public:
    bool isPowerOfTwo(long long n) {
        if (n == 0) return false;
        long long num = n - (n & (-n));
        return num == 0;
    }
};