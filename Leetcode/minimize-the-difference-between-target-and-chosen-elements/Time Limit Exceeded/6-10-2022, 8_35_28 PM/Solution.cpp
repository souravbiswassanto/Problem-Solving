// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int dp[4901][71];
        memset(dp, -1, sizeof dp);
        
        function <int(int , int)> calc = [&] (int id, int sum){
            if(id == n) return abs(target - sum);
            int &ret = dp[sum][id];
            if(ret != -1)return ret;
            ret = INT_MAX;
            for(int i = 0; i < m; i++){
                ret = min(ret, calc(id + 1, sum + mat[id][i]));
            }
            return ret;
        };
        int ans = calc(0, 0);
        return ans;
    }
};