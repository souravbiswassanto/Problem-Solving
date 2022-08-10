// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<int, int> M;
        map<int, int> m;
        for(int i = 0; i < points.size(); i++){
           ////for(int j = i + 1; j < points.size(); j++){
               int x = points[i][0];
               
               
               int y = points[i][1];
               
               M[x + y]++;
              m[x -y]++;
        }
        int mx = 0;
        for(auto it: M){
            mx = max(mx, it.second);
        }
        for(auto it: m)mx = max(mx, it.second);
        return mx;
    }
};