// https://leetcode.com/problems/minimum-jumps-to-reach-home

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        bool forbiddenidx[6001];
        int step[6001];
        for(int i = 0; i < 6001; i++){
            forbiddenidx[i] = false;
            step[i] = 10000000;
        }
        for(int i = 0; i < forbidden.size(); i++){
            forbiddenidx[forbidden[i]] = true;
        }
        step[0] = 0; int ans = 10000000;
        for(int i = 0; i <= 4000; i++){
            
            for(int j = 0; j <= 4000; j++){
                if(forbiddenidx[j] or j - a < 0)continue;
                step[j] = min(step[j - a] + 1, step[j]);
                ans = min(ans, step[x + b] + 1);
                ans = min(ans, step[x]);
                if(x - a >= 0)ans = min(ans, step[x - a] + 1);
                step[x] = ans;
                if(forbiddenidx[j - a] or forbiddenidx[j - a + b])continue;
                step[j] = min(step[j], step[j - a + b] + 2);
                ans = min(ans, step[x + b] + 1);
                ans = min(ans, step[x]);
                if(x - a >= 0)ans = min(ans, step[x - a] + 1);
                step[x] = ans;
            }
            //for(int j = 0; j <= x + 10; j++)cout << j <<" "<< step[j] << endl; cout << endl;
        }
        
        if(step[x] >= 10000000)return -1;
        else return step[x];
    }
};