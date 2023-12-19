
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; // Creating answer vector
        unordered_map<int, int> m; // Creating an unordered map that will store the freqency of any element
        for (int i = 0; i < nums.size(); i++) {
          // check wheater the element is present or not
          // If present then will return the answer
            if (m.find(target - nums[i])  != m.end()) {
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            m[nums[i]] = i; // Not present then increase the freaquency of the curr element and move to the next element
        }
        return ans; // Return ans 
    }
};
