bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    return a.first > b.first;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> p;
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto m : mp){
            p.push_back({m.first, m.second});
        }
        sort(p.begin(), p.end(), compare);
        vector<int> ans;
        for(auto pa : p){
            for(int i = 0; i < pa.second; i++){
                ans.push_back(pa.first);
            }
        }
        return ans;
    }
};