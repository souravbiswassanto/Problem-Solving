// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n = nums.size();
        int cnt[n + 1];
        for(int i = 0; i <= n; i++)cnt[i] = 0;
        int cntr = 0, pos = -1;
        for(int i = 0; i < n; i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]] == 1){
                cntr++;
            }
            if(cntr == k){
                pos = i; 
                break;
            }
        }
        if(pos == -1)return 0;
        cntr = 1; int j = 0; long long sum = 0;
        //cout << pos << endl;
        for(int i = pos; i < n; i++){
            if(cnt[nums[i]] == 0){
                cntr = 1;
                while(j < i and cnt[nums[j]] != 1){
                    
                    cnt[nums[j]]--;
                    j++;
                }
                cnt[nums[j]]--; j++;
            }
            if(i != pos)cnt[nums[i]]++;
            while(j < i and cnt[nums[j]] != 1){
                cntr++;
                cnt[nums[j]]--;
                j++;
            }
            //cout << cntr <<" "<< i << " "<< j << endl;
            sum += cntr;
        }
        return sum;
    }
};