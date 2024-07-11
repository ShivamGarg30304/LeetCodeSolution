class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int maxSumSoFar = 0;
        for(int i = 0; i < nums.size(); i++){
            maxSumSoFar += nums[i];
            if(maxSum < maxSumSoFar){
                maxSum = maxSumSoFar;
            }
            if(maxSumSoFar < 0){
                maxSumSoFar = 0;
            }
        }
        return maxSum;
    }
};