// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int n = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(nums[mid] > nums[n]){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return nums[l];
    }
};