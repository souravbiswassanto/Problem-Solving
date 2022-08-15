#define ll long long
#define MAX 2002
#define pb push_back
class Solution {
public:
    ll A[2002], B[2002], C[2002], cycle;
    ll in[2002], out[MAX], col[MAX];
    vector<int> g[MAX], rev[MAX];
    void dfs(int v, int p){
      col[v] = 1; 
      for(int w : g[v]){
        if(col[w] == 1){
          cycle = 1;
        }
        if(col[w] == 0) dfs(w, v);
      }
      col[v] = 2;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses; int m = prerequisites.size();
        for (int i = 0; i <= n; ++i) {
        	in[i] = out[i] = 0;
        	g[i].clear(); col[i] = 0;
        	rev[i].clear();
        }
        set<pair<int, int>> S;
        for (int i = 0; i < m; ++i) {
        	int a = prerequisites[i][0];
            int b = prerequisites[i][1];
        	g[a].pb(b);
        	rev[b].pb(a);
        	in[b]++;
        	out[a]++;
        }
        int color = 0; cycle = 0;
        for (int i = 0; i < n; ++i) {
        	S.insert({out[i], i});
        	if (col[i] == 0) {
        		dfs(i, -1);
        	}
        }
        vector<int> result;
        if (cycle) {
        	return result;
        }
        
        for (int i = 0; i < n; ++i) {
        	pair<int, int> p = *S.begin();
        	result.pb(p.second);
        	S.erase(p);
        	for (auto v: rev[p.second]) {
        		S.erase({out[v], v});
        		out[v]--;
        		S.insert({out[v], v});
        	}
        }
        return result;
    }
};
