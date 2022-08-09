// Problem: Min Max Roads
// Contest: LightOJ
// URL: https://lightoj.com/problem/min-max-roads
// Memory Limit: 64 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   LINF   1LL<<62
#define   ll     long long
#define   LN    20
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))

ll A[MAX];
ll B[MAX];
ll C[MAX];

int  pa[20][100007], maxx[20][100007];
int depth[MAX], value[MAX], minn[20][100007];
vector<int> G[100007];

void dfs(int cur, int prev = -1, int _depth = 0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	for(int i=0; i<G[cur].size(); i++){
		if(G[cur][i] != prev) {
			dfs(G[cur][i], cur, _depth + 1);
		}
	}
}
void dfs1(int cur, int prev = -1) {
	minn[0][cur] = (cur != 0)?value[cur]:INT_MAX;
	maxx[0][cur] = value[cur]; 
	for(int i=0; i<G[cur].size(); i++){
		if(G[cur][i] != prev) {
			dfs1(G[cur][i], cur);
		}
	}
}

void build(int n){
    for(int i=1; i<=LN; i++){
		for(int j=0; j<n; j++){
			if(pa[i-1][j] != -1){
				pa[i][j] = pa[i-1][pa[i-1][j]];
				minn[i][j] = min(minn[i - 1][j], minn[i-1][pa[i-1][j]]);
				maxx[i][j] = max(maxx[i - 1][j], maxx[i-1][pa[i-1][j]]);
			}
		}
	}
}
pair<int, int> query(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	int Min = INT_MAX, Max = 0;
	for(int i=0; i < LN; i++){ 
	    if((diff >> i)&1){
	        Min = min(Min, minn[i][u]);//1 << i
	        Max = max(Max, maxx[i][u]);//1 << i
	        u = pa[i][u];
	    }
	}
	if(u == v) return {Min,Max};
	for(int i=LN-1; i>=0; i--) {
    	if(pa[i][u] != pa[i][v]) {
    	    Max = max(maxx[i][u], Max);
    	    Max = max(maxx[i][v], Max);
    	    Min = min(minn[i][u], Min);
    	    Min = min(minn[i][v], Min);
    		u = pa[i][u];
    		v = pa[i][v];
    	}
    }
    Min = min(Min, minn[0][u]);
    Min = min(Min, minn[0][v]);
    Max = max(Max, maxx[0][u]);
    Max = max(Max, maxx[0][v]);
	return {(int)Min,(int)Max};
}

int main ()
{
    ll a,b,c,d,n,m,k,l,p,q,r,t,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //cin>>n;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 100001; j++){
                minn[i][j] = INT_MAX;
                maxx[i][j] = 0;
                pa[i][j] = -1;
                value[i] = 0;
            }
        }
        cntr = 0;
    	for(int i = 0; i < n; i++){
    	    G[i].clear();
    	    depth[i] = 0;
    	}
        for(int i = 1; i < n; i++){
            scanf("%lld %lld %lld", &A[i], &B[i], &C[i]);
            --A[i]; --B[i];
            G[A[i]].pb(B[i]);
            G[B[i]].pb(A[i]);
        }
        dfs(0);
        value[0] = 0;
        
        for(int i = 1; i < n; i++){
            
            if(depth[A[i]] > depth[B[i]]){
                value[A[i]] = C[i];
            }
            else value[B[i]] = C[i];
        }
        dfs1(0);
        
        build(n);
        printf("Case %lld:\n", ++cnt);
        scanf("%lld", &q);
        for(int cs = 1; cs <= q; cs++){
            scanf("%lld %lld", &a, &b);
            pair<int, int> pi = query(--a, --b);
            printf("%d %d\n", pi.first, pi.second);
        }
        
    }
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return 0;
}
