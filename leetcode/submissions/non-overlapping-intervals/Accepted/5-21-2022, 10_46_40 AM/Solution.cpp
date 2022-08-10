// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    vector<int> tree;
    void update(int node, int b, int e, int idx, int val){
        if(b > idx or e < idx)return;
        if(b == e){
            tree[node] = val;
            return;
        }
        int mid = (b + e) / 2;
        int left = node * 2;
        int right = left + 1;
        update(left, b, mid, idx, val);
        update(right, mid + 1, e, idx, val);
        tree[node] = max(tree[left], tree[right]);
        //cout << "Update "<< endl;
        //cout << b <<" " << e <<" "<< tree[node] << endl;
    }
    
    int query(int node, int b, int e, int l, int r){
        if(b > r or e < l)return 0;
        if(b >= l and e <= r)return tree[node];
        int mid = (b + e) / 2;
        int left = node * 2;
        int right = left + 1;
        int L = query(left, b, mid, l, r);
        int R = query(right, mid + 1, e, l, r);
        //cout << b <<" " << e << endl;
        //cout << L <<" " << R << " "<< left <<" "<<right << endl;
        return max(L, R);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int Max = 0;
        for(int i = 0; i < intervals.size(); i++){
            Max = max(Max, intervals[i][1]);
        }
        Max += 50001; 
        Max++;
        tree.resize(4 * Max, 0);
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(); int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            intervals[i][0] += 50001;
            intervals[i][1] += 50001;
            int res = query(1, 1, Max, intervals[i][1], Max);
            ans = max(ans, res + 1);
            //cout << intervals[i][0]<<" " << intervals[i][1]<<" " << res + 1 << endl;
            
            update(1, 1, Max, intervals[i][0], res + 1);
            
        }
        return n - ans;
        //[[1,2],[2,3],[3,4],[1,3]]
    }
};