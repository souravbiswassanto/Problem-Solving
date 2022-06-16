// https://leetcode.com/problems/can-i-win

class Solution {
public:
    int n;
    int dp[1<<20];
    int canwin(int id, int mask, int k){
        if(id == n){
            if(k <= 0)return 1;
            else return 0;
        }
        if(k <= 0){
            return 1;
        }
        int &ret = dp[mask];
        if(ret != -1)return ret;
        ret = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i))continue;
            ret |= canwin(id + 1, mask | (1 << i), k - i - 1);
        }
        //cout << id <<" "<< ret << endl;
        return 1 - ret;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        n = maxChoosableInteger;
        if(n >= desiredTotal)return true;
        for(int i = 0 ; i < (1 << n); i++)dp[i] = -1;
        int ans = canwin(0, 0, desiredTotal);
        if(!ans)return true;
        else return false;
    }
};