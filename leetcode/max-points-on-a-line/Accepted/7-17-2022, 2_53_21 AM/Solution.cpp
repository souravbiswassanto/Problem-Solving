// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    bool isdegenrated_triangle(int ax,int ay, int bx, int by, int cx, int cy){
        int res = ax*(by-cy)+bx*(cy-ay) + cx*(ay-by);
        //cout<<res<<" res"<<endl;
        return res == 0?1:0;
    }
    int maxPoints(vector<vector<int>>& points) {
        int mx = 2;
        if(points.size() == 1)return 1;
        for(int i = 0; i < points.size(); i++){
           for(int j = 0; j < points.size(); j++){
               int cntr = 0; if(i == j)continue;
               for(int k = 0; k < points.size(); k++){
                   if(i == k or j == k)continue;
                   if(isdegenrated_triangle(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]))cntr++;
               }
                                                                                                mx = max(mx, cntr + 2);
           }
        }
        
        return mx;
    }
};