// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int fmx = -INT_MAX - 1;
        int neginf = fmx;
        int smx = fmx;
        int tmx = fmx;
        
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
        if(tmx != neginf)return tmx;
        else return fmx;
    }
};