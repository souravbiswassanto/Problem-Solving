// https://leetcode.com/problems/two-sum

class Solution {
public:
    struct val{
        bool ok = false;
        int pos;
    };
    vector<int> twoSum(vector<int>& nums, int target) {
        struct val A[10000];
        vector<int>res(2);
        int cntr = 0;
        int mod = 9997;
        for(auto v:nums){
            int a = v  % mod; if(a<0)a+=mod;
            int rem = (target - v) % mod; if(rem<0)rem += mod;
            if(A[rem].ok and A[rem].pos != cntr){
                res[0] = cntr;
                res[1] = A[rem].pos;
            }
            A[a].ok = true;
            A[a].pos = cntr;
            cntr++;
        }
       
         return res;
    }
};