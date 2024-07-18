class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;
	    double prefix = 1, suffix = 1;
	    for (int i = 0; i < n; i++) {
	        if (prefix == 0) prefix = 1;
	        if (suffix == 0) suffix = 1;
	        
	        prefix *= nums[i];
	        suffix *= nums[n - i - 1];
	        ans = max((double)ans, max(prefix, suffix));
	    }
	    return ans;
    }
};