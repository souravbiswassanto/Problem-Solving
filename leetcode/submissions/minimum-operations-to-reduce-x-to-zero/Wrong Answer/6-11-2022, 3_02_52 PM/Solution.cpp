// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        unordered_map<int, int> M;
        M[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            M[sum] = i + 1;
        }
        int tot = 0; int ans = INT_MAX;
        if(M.find(x) != M.end()){
            ans = M[x];
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            tot += nums[i];
            if(M.find(x - tot) != M.end())ans = min((int)ans, (int)nums.size() - i + M[x - tot]);
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};