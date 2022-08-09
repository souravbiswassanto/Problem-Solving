
// Problem: A Secret Mission
// Contest: LightOJ
// URL: https://lightoj.com/problem/a-secret-mission
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
#define   ll     long long
#define   LN    20
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define buga  cout<<1<<endl
#define bugb  cout<<2<<endl
#define bugc  cout<<3<<endl
#define bugd  cout<<4<<endl
#define buge  cout<<5<<endl

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
int Parent[200005], Max, pa[20][100000], occ[200005];
int depth[MAX], value[MAX], minn[20][100000];
vector<int> G[100000];
void INIT(int n){
    for(int i=0;i<=n;i++) Parent[i]=i;
}
int Find(int r){
    if(r==Parent[r]) return r;
    else return Parent[r] = Find(Parent[r]);
}

int Kruskal(int E)
{ 
    sort(Edges.begin(),Edges.end(),sourav);
    int cntr  = 0;
    for(int i = 0; i < E; i++){
        int X = Edges[i].U; int Y = Edges[i].V; int Cost = Edges[i].W;
        int PX = Find(X); int PY = Find(Y); 
        if(PX!=PY){
            Parent[PX]=PY;
            G[X].pb(Y);
            G[Y].pb(X);
            Max = max(Max, X);
            A[cntr] = X;
            B[cntr] = Y;
            C[cntr] = Cost;
            cntr++;
        }
    }
    return cntr;
}
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
	minn[0][cur] = value[cur]; 
	//cout << value[cur] << endl;
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
				minn[i][j] = max(minn[i - 1][j], minn[i-1][pa[i-1][j]]);
			}
		}
	}
}
int query(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	int Min = 0;
	for(int i=0; i < LN; i++){ 
	    if((diff >> i)&1){
	        Min = max(Min, minn[i][u]);//1 << i
	        u = pa[i][u];
	    }
	}
	if(u == v) return Min;
	for(int i=LN-1; i>=0; i--) {
    	if(pa[i][u] != pa[i][v]) {
    	    Min = max(minn[i][u], Min);
    	    Min = max(minn[i][v], Min);
    		u = pa[i][u];
    		v = pa[i][v];
    	}
    }
    Min = max(Min, minn[0][u]);
    Min = max(Min, minn[0][v]);
	return (int)Min;
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
        scanf("%lld %lld", &n, &m);
        INIT(n); Max = 0;
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 100000; j++){
                minn[i][j] = 0;
                pa[i][j] = -1;
                value[i] = 0;
            }
        }
        cntr = 0;
    	for(int i = 0; i < n; i++){
    	    G[i].clear();
    	    depth[i] = 0;
    	    occ[i] = 0;
    	}
        for(int i = 0; i < m; i++){
            scanf("%lld %lld %lld", &A[i], &B[i], &C[i]);
            Edges.pb(edge(--A[i],--B[i],C[i]));
        }
        cntr = Kruskal(m);
        Edges.clear();
        dfs(Max);
        value[Max] = 0;
        
        for(int i = 0; i < cntr; i++){
            
            if(depth[A[i]] > depth[B[i]]){
                value[A[i]] = C[i];
            }
            else value[B[i]] = C[i];
        }
        dfs1(Max);
        
        build(n);
        printf("Case %lld:\n", ++cnt);
        scanf("%lld", &q);
        for(int cs = 1; cs <= q; cs++){
            scanf("%lld %lld", &a, &b);
            printf("%d\n", query(--a, --b));
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
