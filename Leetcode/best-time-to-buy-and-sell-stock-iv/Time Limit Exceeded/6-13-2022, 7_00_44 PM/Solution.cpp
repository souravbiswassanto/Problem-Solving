// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        int dp[n + 1][k + 1];
        memset(dp, -1, sizeof dp);
        function <int(int, int)> calc = [&](int idx, int kth){
            if(idx >= n or kth == k)return 0;
            int &ret = dp[idx][kth];
            if(ret != -1)return ret;
            ret = 0;
            for(int i = idx + 1; i < n; i++){
                //if(prices[idx] > prices[i])continue;
                int v = max(calc(i + 1, kth + 1) + prices[i] - prices[idx], calc(idx + 1, kth));
                ret = max(ret, v);
                //ret = max(ret, calc(i + 1, kth + 1) + (prices[i] - prices[idx]));
            }
            
            return ret;
        };
        int ans = calc(0, 0);
        return ans;
        
    }
};