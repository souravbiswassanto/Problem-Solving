// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int cntr = 0;
        int m = nums1.size();
        int n = nums2.size();
        vector<int>New;
        for(int i = 0 , j = 0; cntr < n + m; cntr++){
            if(j==n){
                New.push_back(nums1[i]);i++;continue;
            }
            if(i==m){
                New.push_back(nums2[j]);j++;continue;
            }
            if(nums1[i]>nums2[j]){
                New.push_back(nums2[j]);j++;
            }
            else {
                New.push_back(nums1[i]);i++;
            }
        }
        cntr = (n + m);
        double b=0.0;
        if(cntr % 2){
            b = New[cntr/2];
            return {b};
        }
        else {
            b = (New[cntr/2] + New[cntr/2 - 1])/2.0;
            return {b};
        }
    }
    
};