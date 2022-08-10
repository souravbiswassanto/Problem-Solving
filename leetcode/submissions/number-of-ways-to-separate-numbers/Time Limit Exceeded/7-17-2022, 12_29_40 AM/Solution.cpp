// https://leetcode.com/problems/number-of-ways-to-separate-numbers

class Solution {
public:
    int numberOfCombinations(string num) {
        int n = num.size();
        int isSmall[n + 4][n + 4], dp[n + 4][n + 4];
        memset(isSmall, 0, sizeof isSmall);
        memset(dp, -1, sizeof dp);
        int mod = 1e9 + 7;
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
        function<int(int, int)> calc = [&] (int idx, int last){
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
                ret = (ret + calc(idx + i, i)) % mod;
            }
            return ret;
        };
        int ans = calc(0, 0);
        return ans;
    }
};