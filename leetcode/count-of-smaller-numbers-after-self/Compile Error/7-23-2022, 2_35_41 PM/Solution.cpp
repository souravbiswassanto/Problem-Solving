// https://leetcode.com/problems/count-of-smaller-numbers-after-self

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
class Solution {
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        oset<int> S;
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--){
            ans[i] = S.order_of_key(nums[i]);
            S.insert(nums[i]);
        }
        return ans;
    }
};

C