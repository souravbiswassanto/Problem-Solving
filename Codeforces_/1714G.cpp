// Problem: G. Path Prefixes
// Contest: Codeforces - Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 300006
#define pb  push_back
ll pa[21][MAX];
ll depth[MAX];
vector<ll> G[MAX];
ll A[MAX], B[MAX], C[MAX], sumA[MAX], sumB[MAX];
struct LCA{
    ll n, LN;
    LCA(ll _n){
        n = _n;
        LN = log2(n);
    }
    void dfs(ll cur, ll prev, ll _depth = 0) {
    	pa[0][cur] = prev;
    	depth[cur] = _depth;
    	for(ll i=0; i< G[cur].size(); i++){
    		if(G[cur][i] != prev) {
    			sumA[G[cur][i]] = sumA[cur] + B[G[cur][i]];
    			sumB[G[cur][i]] = sumB[cur] + C[G[cur][i]];
    			dfs(G[cur][i], cur, _depth + 1);
    		}
    	}
    }
    
    void build(){
        for(ll i=1; i<=LN; i++)
			for(ll j=1; j<= n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];
    }
    
};
int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	ll t;
	cin >> t;
	while(t--){
		
	    ll n;
	    ll a, b;
	    cin >> n;
	    
	   	for(ll i = 0; i <= n; i++){
	   		G[i].clear();
	   		sumA[i] = sumB[i] = 0; depth[i] = 0;
	   	} 
	    for (ll i = 2; i <= n; i++){
	        cin >> A[i] >> B[i] >> C[i];
	        G[i].pb(A[i]);
	        G[A[i]].pb(i);
	    }
	    
	    LCA lca(n);
	    for(ll i = 0; i < 21; i++){
	    	for(ll j = 0; j < n + 2; j++) {
	    		pa[i][j] = -1;
	    	}
	    }
	    lca.dfs(1, 0, 0);
	    lca.build(); vector<ll> res;
	    
	    for(ll i = 2; i <= n; i++){
	    	
	    	ll level = depth[i];
	    	ll costA = sumA[i];
	    	ll costB = sumB[i];
	    	ll Log = log2(level);
	    	ll pos = i;
	    	if(costA >= costB){
	    		res.pb(depth[i]); continue;
	    	}
	    	for (ll j = Log; j >= 0; --j) {
	    		ll par = pa[j][pos];
	    		if(par == -1)continue;
	    		if(sumB[par] <= costA)continue;
	    		pos = pa[j][pos];
	    	}
	    	res.pb(depth[pa[0][pos]]);
	    }
	    for(auto it: res)cout << it <<" ";
	    cout << "\n";
	}
	return 0;
}