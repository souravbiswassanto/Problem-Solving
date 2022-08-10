// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l, r;
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for(int i = 0; i <= n - 4; i++){
            for(int j = i + 1; j < n - 2; j++){
                l = j + 1;
                r = n - 1;
                long long sum = nums[i] + nums[j];
                long long need =  target - sum;
                while(l < r){
                    long long tsum = nums[l] + nums[r];
                    
                    if(tsum > need){
                        r--;
                    }
                    else if(tsum < need){
                        l++;
                    }
                    else{
                        vector<int> V;
                        V.push_back(nums[i]);
                        V.push_back(nums[j]);
                        V.push_back(nums[l]);
                        V.push_back(nums[r]);
                        res.push_back(V);
                        l++; r--;
                    }
                }
            }
        }
        return res;
    }
};