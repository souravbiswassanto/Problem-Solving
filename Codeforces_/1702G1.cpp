
// Problem: G1. Passable Paths (easy version)
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/G1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 300006
#define pb  push_back
int pa[20][MAX];
int depth[MAX];
vector<int> G[MAX];
struct LCA{
    int n, LN;
    LCA(int _n){
        n = _n;
        LN = 19;
    }
    void dfs(int cur, int prev, int _depth = 0) {
    	pa[0][cur] = prev;
    	depth[cur] = _depth;
    	for(int i=0; i<G[cur].size(); i++){
    		if(G[cur][i] != prev) {
    			dfs(G[cur][i], cur, _depth + 1);
    		}
    	}
    }
    
    void build(){
        for(int i=1; i<LN; i++)
			for(int j=0; j<n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
    }
    int query(int u, int v) {
    	if(depth[u] < depth[v]) swap(u,v);
    	int diff = depth[u] - depth[v];
    	for(int i=0; i < LN; i++) if((diff>>i)&1) u = pa[i][u];
    	if(u == v) return u;
    	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
    		u = pa[i][u];
    		v = pa[i][v];
    	}
    	return pa[0][u];
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    int a, b;
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    int q;
    LCA lca(n);
    memset(pa, -1, sizeof pa);
    lca.dfs(0, -1, 0); lca.build();
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int> v, set1, set2;
        int check = 0;
        ll mx = -1;
        int fnode, fnod = -1; map<int,int> m;
        for(int i = 0; i < k ; i++){
            cin >> a; a--;
            if(depth[a] > mx){
                mx = depth[a];
                fnode = a;
            }
            v.pb(a);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < k; i++){
            if(lca.query(v[i], fnode) == v[i]){
                set1.pb(v[i]); m[v[i]] = 1;
            }
        }
        mx = -1; 
        for(int i = 0; i < k ; i++){
            if(m[v[i]])continue;
            a = v[i];
            if(depth[a] > mx){
                mx = depth[a];
                fnod = a;
            }
        }
        if(fnod != -1){
            for(int i = 0; i < k; i++){
                if(m[v[i]])continue;
                if(lca.query(v[i], fnod) == v[i]){
                    set2.pb(v[i]);
                }
            }
            if(set1.size() + set2.size() < k){
                check = 1;
            }
            int Lca = lca.query(fnode, fnod);
            int reqdepth = depth[Lca];
            
            for(int i = 0; i < set1.size(); i++){
                if(depth[set1[i]] < reqdepth)check = 1;
            }
            for(int i = 0; i < set2.size(); i++){
                if(depth[set2[i]] < reqdepth)check = 1;
            }
        }
        if(check)cout <<"NO\n";
        else cout <<"YES\n";
    }
    
}