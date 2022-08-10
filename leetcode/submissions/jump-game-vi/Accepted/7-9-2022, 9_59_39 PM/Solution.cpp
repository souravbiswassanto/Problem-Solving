// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        dq.push_front({nums[0], 0});
        int n = nums.size();
        int ans;
        for(int i = 1; i < n; i++){
            while(!dq.empty() and dq.back().second + k < i)dq.pop_back();
            int a = dq.back().first + nums[i];
            while(!dq.empty() and dq.front().first <= a)dq.pop_front();
            dq.push_front({a, i});
            if(i == n - 1)ans = a;
        }
        if(n == 1)ans = nums[0];
        return ans;
    }
};