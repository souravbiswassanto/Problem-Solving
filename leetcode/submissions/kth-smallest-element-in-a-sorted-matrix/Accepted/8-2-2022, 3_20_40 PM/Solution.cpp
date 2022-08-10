// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        set<pair<int, pair<int, int>>> S; int cntr = 0;
        int n = matrix.size();
        pair<int, pair<int, int>> p;
        S.insert({matrix[0][0]   , {0, 0}});
        while(!S.empty() and cntr < k){
            p = *S.begin();
            int a = p.second.first;
            int b = p.second.second;
            int c = p.first;
            S.erase(p);
            cntr++;
            if(a < n - 1)S.insert({matrix[a + 1][b], {a + 1, b}});
            if(b < n - 1)S.insert({matrix[a][b + 1], {a, b + 1}});
        }
        return p.first;
    }
};