// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); int Max = 0;
        set<pair<int, int> > S; S.insert({INT_MAX, 0});
        for(int i = intervals.size() - 1; i >= 0; i--){
            auto it = S.upper_bound({intervals[i][1], -1});
            S.insert({intervals[i][0], it->second + 1});
            Max = max(Max, it->second + 1);
        }
        return intervals.size() - Max;
    }
};