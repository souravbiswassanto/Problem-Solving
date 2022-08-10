// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i]++;
            m1[nums[i]] = nums[i];
        }
        int res, mx = 0;
        for(int i = 0; i < n; i++){
            if(m1[nums[i] != nums[i]])continue;
            res = nums[i];
            for(int j = nums[i]; m1[j] == j; j++){
                
                res = j;
            }
            m1[nums[i]] = res;
            mx = max(mx, res - nums[i] + 1);
        }
        return mx;
    }
};