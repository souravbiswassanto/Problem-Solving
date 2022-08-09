
// Problem: Greatest Parent
// Contest: LightOJ
// URL: https://lightoj.com/problem/greatest-parent
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   LINF   1LL<<62
#define   ll     int
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
vector< ll >V;
vector< ll >Ans;
vector< pair<ll,ll> >VP;
map< ll,ll >M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

struct edge{
    int U,V,W;
    edge(int a,int b,int c){
        U=a; V=b; W=c;}
};
vector <edge> Edges;
bool sourav(edge a,edge b){
    return a.W<b.W;
}
int Max, pa[20][100007];
int depth[MAX], value[MAX], minn[20][100007];
vector<int> G[100007];

void dfs(int cur, int prev = -1, int _depth = 0) {
	pa[0][cur] = prev;
	depth[cur] = _depth;
	minn[0][cur] = B[(prev == -1)?0:prev];
	for(int i=0; i<G[cur].size(); i++){
		if(G[cur][i] != prev) {
			dfs(G[cur][i], cur, _depth + 1);
		}
	}
}

void build(int n){
    for(int i=1; i<=LN; i++){
		for(int j=0; j<n; j++){
			if(pa[i-1][j] != -1){
				pa[i][j] = pa[i-1][pa[i-1][j]];
				minn[i][j] = min(minn[i - 1][j], minn[i-1][pa[i-1][j]]);
			}
		}
	}
}
pair<int, int> query(int u, int diff) {
	int Min = B[u];
	for(int i=0; i < LN; i++){ 
	    if((diff >> i)&1){
	        Min = min(Min, minn[i][u]);
	        u = pa[i][u];
	    }
	}
	return  {u, Min};
}

int Binary_search(int u,int pos, int val){
    int lo = 0, hi = pos; 
    int mid, node = u, v, Min ;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        pair<int, int> pi = query(u, depth[u]-mid);
        if((pi.second) >= val){
            node = pi.first;
            u = pa[0][pi.first];
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return node;
}

int main ()
{
    ll a,b,c,d,n,m,k,l,p,q,r,t,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    
    string s,s1,s3,s4;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &q);
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 100007; j++){
                minn[i][j] = INT_MAX;
                pa[i][j] = -1;
                value[i] = 0;
            }
        }
        cntr = 0;
    	for(int i = 0; i < n; i++){
    	    G[i].clear();
    	    depth[i] = 0;
    	}
    	B[0] = 1;
        for(int i = 1; i < n; i++){
            scanf("%d %d", &A[i], &B[i]);
            G[i].pb(A[i]);
            G[A[i]].pb(i);
        }
        dfs(0);
        build(n);
        printf("Case %d:\n", ++cnt);
        for(int cs = 1; cs <= q; cs++){
            scanf("%d %d", &a, &b);
            printf("%d\n", Binary_search(a, depth[a], b));
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
