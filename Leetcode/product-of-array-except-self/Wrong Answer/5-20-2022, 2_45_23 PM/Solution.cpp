// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cntzero = 0, cntminus1 = 0;
        vector<int> g1;
        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i]) >= 2)g1.push_back(nums[i]);
            if(nums[i] == 0)cntzero++;
            if(nums[i] == -1)cntminus1++;
        }
        vector<int> solution;
        if(cntzero >= 2){
            for(int i = 0; i < nums.size(); i++){
                solution.push_back(0);   
            }
            goto ans;
        }
        if(cntzero == 1){
            int res = 1;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i])res *= nums[i];   
            }
            for(int i = 0; i < nums.size(); i++){
                if(nums[i])solution.push_back(0);
                else solution.push_back(res);
            }
            goto ans;
        }
        for(int i = 0; i < nums.size(); i++){
            bool check = 0; int res = 1;
            if(cntminus1 % 2)res = -1;
            for(int j = 0; j < g1.size(); j++){
                if(nums[i] == g1[j] and check == 0){
                    check = 1; continue;
                }
                res *= g1[j];
            }
            solution.push_back(res);
        }
        
        ans:
        return solution;
    }
};