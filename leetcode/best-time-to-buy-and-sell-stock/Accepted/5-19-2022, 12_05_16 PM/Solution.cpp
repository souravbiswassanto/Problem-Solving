// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxtill[prices.size() + 2];
        int Max = 0;
        for(int i = prices.size() - 1; i >= 0; i--){
            Max = max(Max, prices[i]);
            maxtill[i] = Max;
        }
        Max = 0; maxtill[prices.size()] = 0;
        for(int i = 0; i < prices.size(); i++){
            Max = max(Max, maxtill[i + 1] - prices[i]);
        }
        return Max;
    }
};