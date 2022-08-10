// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, pair<int,int>> m;
        vector<int>res(2);
        int cntr = 0;
        for(auto v:nums){
            m[v] = {1,cntr};
            int rem = target - v;
            if(m[rem].first and m[rem].second != cntr){
                res[0] = cntr;
                res[1] = m[rem].second;
               
            }
            cntr++;
        }
       
         return res;
    }
};