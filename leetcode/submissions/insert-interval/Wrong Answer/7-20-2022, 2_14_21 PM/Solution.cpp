// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int> v;
        int x = newInterval[0]; int check = 0;
        int y = newInterval[1]; int mx = y, mn = x;
        for(int i = 0; i < intervals.size(); i++){
            if((x <= intervals[i][0] and y >= intervals[i][0]) or (x <= intervals[i][1] and y >= intervals[i][1])){
                mn = min(mn, intervals[i][0]);
                mx = max(mx, intervals[i][1]);
                check = 1;
            }
            else {
                if(check){
                    v.push_back(mn); mn = -1;
                    v.push_back(mx);
                    ans.push_back(v); check = 0; v.clear();
                }
                ans.push_back(intervals[i]);
            }
            
        }
        if(mn != -1){
            v.push_back(mn);
            v.push_back(mx);
            ans.push_back(v); check = 0;
        }
        return ans;
    }
};