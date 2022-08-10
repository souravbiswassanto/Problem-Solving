// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long fmx = -INT_MAX - 1;
        long long neginf = fmx - 1;
        long long smx = fmx;
        long long tmx = fmx - 1;
        
        for(int i = 0;  i < nums.size(); i++){
            if(fmx < nums[i]){
                swap(fmx, smx);
                swap(fmx, tmx);
                fmx = nums[i];
            }
            else if(smx < nums[i] and nums[i] != fmx){
                swap(smx, tmx);
                smx = nums[i];
            }
            else if(tmx < nums[i] and nums[i] != fmx and nums[i] != smx){
                tmx = nums[i];
            }
        }
        if(tmx != neginf)return (int)tmx;
        else return (int)fmx;
    }
};