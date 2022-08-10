// https://leetcode.com/problems/number-of-ways-to-separate-numbers

class Solution {
public:
    const int mod = 1e9 + 7;
    
    vector<int>z_function(string& s){
    int n = (int) s.length();
    vector < int > Z(n);
    Z[0] = 0; 
    for (int i = 1, L = 0, R = 0; i < n; ++i)
    {
        if (i <= R) 
            Z[i] = min (R - i + 1, Z[i - L]); 
        else
            Z[i] = 0; 
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) 
            ++Z[i]; 
        if (i + Z[i] - 1 > R) 
            L = i, R = i + Z[i] - 1;
    }
        return Z;
}
    
    int calc (int idx, int last, int n, string& num, vector<vector<int>>& match, vector<vector<int>>& dp){
            //cout << idx <<" " << last << endl;
            if(idx > n)return 0;
            if(idx == n)return 1;
            int &ret = dp[idx][last];
            if(ret != -1)return ret;
            ret = 0;
            int start = (match[idx][last] == 1)?last: last + 1;
            if(num[idx] =='0')return 0;
            for(int i = start; i <= n; i++){
                if(idx + i > n)break;
                ret = (ret + calc(idx + i, i, n, num, match, dp)) % mod;
            }
            return ret;
        };
    int numberOfCombinations(string num) {
        int n = num.size();
        vector<vector<int>> match(n + 4, vector<int>(n + 4, 0));
        vector<vector<int>> dp(n + 4, vector<int>(n + 4, -1));
        
        for(int i = 0; i < n; i++){
            string s = "";
            for(int j = i; j < n; j++)s += num[j];
            s += '#';
            s += num;
            vector<int> Z = z_function(s);
            for(int j = 1; j < n; j++){
                if(i + j >= n)break;
                match[i][i + j] = Z[n + j + 1];
                //cout << i <<" " << i + j << " " << match[i][i + j] << endl;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                if(i + j > n)break;
                if(i - j < 0)break;
                
                int a = match[i - j][i];
                if(a >= j or num[i - j + a] <= num[i + a]){
                    match[i][j] = 1;
                }
                else match[i][j] = 0;
            }
        }
        
        int ans = calc(0, 0, n, num, match, dp);
        return ans;
    }
};