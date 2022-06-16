
// Problem: C. Alyona and the Tree
// Contest: Codeforces - Codeforces Round #358 (Div. 2)
// URL: https://codeforces.com/problemset/problem/682/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   LINF   1LL<<63
#define   ll     long long
#define   ull    unsigned long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define buga  cout<<1<<endl
#define bugb  cout<<2<<endl
#define bugc  cout<<3<<endl
#define bugd  cout<<4<<endl
#define buge  cout<<5<<endl

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

ll A[MAX];
ll B[MAX];
ll C[MAX];
vector< ll >V;
vector< ll >Ans;
vector< pair<ll,ll> >VP;
map< pair<ll,ll>,ll >M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

/*
ll bin_pow(ll o, ll s) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    ll d = bin_pow(o, s/2);
    d = (d * 1ll * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}
*/
ll cnt[MAX],res;
vector<int>g[MAX];

void dfs(int source,int par){
	cnt[source] = 1;
	for(auto v: g[source]){
		if(v == par)continue;
		dfs(v,source);
		cnt[source] += cnt[v];
	}
}

void dfs2(int source,int par,ll val){
	ll sum = 0;
	for(auto v : g[source]){
		if(v == par)continue;
		sum = val + M[{source,v}];
		sum = max(sum,M[{source,v}]);
		if(sum>A[v]){
			res += cnt[v] ; continue;
		}
		dfs2(v,source,sum);
	}
}

int main ()
{
    fastIO();
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //cin>>n;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
    	cin >> A[i];
    }
    for(int i = 2; i <= n; ++i){
    	cin >> a >> b;
    	g[a].pb(i);
    	g[i].pb(a);
    	M[{a,i}] = b; 
    	M[{i,a}] = b; 
    }
    dfs(1,-1);
    dfs2(1,-1,0);
    cout<<res<<endl;

    return 0;
}
