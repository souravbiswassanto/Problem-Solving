// https://leetcode.com/problems/number-of-ways-to-separate-numbers

class Solution {
public:
    const int mod = 1e9 + 7;
    int calc (int idx, int last, int n, string& num, vector<vector<int>>& isSmall, vector<vector<int>>& dp){
            //cout << idx <<" " << last << endl;
            if(idx > n)return 0;
            if(idx == n)return 1;
            int &ret = dp[idx][last];
            if(ret != -1)return ret;
            ret = 0;
            int start = (isSmall[idx][last] == 1)?last: last + 1;
            if(num[idx] =='0')return 0;
            for(int i = start; i <= n; i++){
                if(idx + i > n)break;
                ret = (ret + calc(idx + i, i, n, num, isSmall, dp)) % mod;
            }
            return ret;
        };
    int numberOfCombinations(string num) {
        int n = num.size();
        vector<vector<int>> isSmall(n + 4, vector<int>(n + 4, 0));
        vector<vector<int>> dp(n + 4, vector<int>(n + 4, -1));
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                if(i + j > n)break;
                if(i - j < 0)break;
                
                string s1 = num.substr(i - j, j);
                string s2 = num.substr(i, j);
                if(s2 >= s1){
                    isSmall[i][j] = 1;
                }
            }
        }
        
        int ans = calc(0, 0, n, num, isSmall, dp);
        return ans;
    }
};