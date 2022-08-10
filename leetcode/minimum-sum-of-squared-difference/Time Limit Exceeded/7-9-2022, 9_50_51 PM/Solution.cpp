// https://leetcode.com/problems/minimum-sum-of-squared-difference

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        multiset<long long, greater<long long >> ms;
        int n= nums1.size();
        for(int i= 0; i < n; i++){
            int a = abs(nums1[i] - nums2[i]);
            if(a)ms.insert(a);
        }
        int c = 0;
        c = k1 + k2 - c;
        for(int i = 0; i < c; i++){
            if(ms.size() == 0)break;
            auto it = ms.begin();
            int a = *it;
            a -= 1;
            ms.erase(it);
            if(a)ms.insert(a);
        }
        long long sum = 0;
        for(auto it: ms){
            sum += (it *1LL* it);
        }
        return sum;
    }
};