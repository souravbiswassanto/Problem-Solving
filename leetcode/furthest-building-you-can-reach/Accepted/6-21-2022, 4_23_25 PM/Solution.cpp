// https://leetcode.com/problems/furthest-building-you-can-reach


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        oset<int> S; int cntr = 0;
       
        for(int i = 1; i < n; i++){
            if(heights[i] <= heights[i - 1])continue;
            
            if(S.size() >= ladders){
                auto it = S.find_by_order(S.size() - ladders);
                int a;
                if(it != S.end())a = *it;
                else a = heights[i] - heights[i - 1];
                //cout << a << endl;
                if(a >= heights[i] - heights[i - 1]){
                    bricks -= (heights[i] - heights[i - 1]);
                }
                else {
                    bricks -= a;
                    S.erase(it);
                }
            }
            S.insert(heights[i] - heights[i - 1]);
            if(bricks < 0)return i - 1;
        }
        return n - 1;
    }
};