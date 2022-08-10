// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = matrix[0].size();
        pq.push({matrix[0][0], {0, 0}});
        pair<int, pair<int, int>> p; int cntr = 0;
        while(!pq.empty() and cntr < k){
            p = pq.top();
            int a = p.second.first;
            int b = p.second.second;
            int c = p.first;
            pq.pop();
            cntr++;
            if(a < n - 1)pq.push({matrix[a + 1][b], {a + 1, b}});
            if(b < n - 1)pq.push({matrix[a][b + 1], {a, b + 1}});
        }
        return p.first;
    }
};