// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> A(n) ; A =  nums;
        int mindiff = INT_MAX;
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            
            while(l < r){
                mindiff = min(mindiff, abs(target - (A[i] + A[l] + A[r])));
                if(A[i] + A[l] + A[r] > target){
                    r--;
                }
                else if(A[i] + A[r] + A[l] < target){
                    l++;
                }
                else {
                    return target;
                }
            }
        }
        return mindiff;
    }
};