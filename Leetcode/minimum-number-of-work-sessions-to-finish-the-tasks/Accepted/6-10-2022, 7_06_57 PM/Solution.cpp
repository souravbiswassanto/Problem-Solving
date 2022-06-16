// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int dp[1 << n][16][16];
        memset(dp, -1, sizeof dp);
        function<int(int, int, int)> calc = [&](int mask, int last, int k){
            //cout << mask <<" " << (1 << n) - 1 << endl;
            if((1<<n) - 1 == mask){
                //cout << mask << endl;
                return 0;
            }
            int &ret = dp[mask][last][k];
            if(ret != -1)return ret;
            
            ret = INT_MAX - 100; bool check = false;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i))continue;
                if(k >= tasks[i])check = 1;
            }
            
            if(check == false)k = sessionTime;
            
            for(int i = 0; i < n; i++){
                if(tasks[i] > k)continue;
                if(mask & (1 << i))continue;
                ret = min(ret, calc(mask | (1 << i), i, k - tasks[i]));
            }
            if(!check)ret++;
            //cout << ret << endl;
            return ret;
        };
        int ans = calc(0, 0, sessionTime);
        return ans + 1;
    }
};