// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> M;
        bool res = false;
        for(int i = 0; i < nums.size(); i++){
            if(M.count(nums[i]))res = true;
            M[nums[i]] = true;
        }
        return res;
    }
};