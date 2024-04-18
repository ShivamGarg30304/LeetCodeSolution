#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// pbds = find_by_value(), order_of_key()
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
template<class T> using minheap = priority_queue<T,vector<T>,greater<T> >; 
template<class T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>> using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ordered_set<pair<int, int>> st;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            st.insert({nums[i], i});
            ans[i] += st.order_of_key({nums[i], 0});
        }
        return ans;
    }
};