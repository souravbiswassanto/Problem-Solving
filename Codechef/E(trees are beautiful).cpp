
// Problem: E. Trees Are Beautiful
// Contest: CodeMarshal - ICPC Dhaka Regional 2019 Organized by SEU
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-19-onsite-main/problems/E
// Memory Limit: 1500 MB
// Time Limit: 3000 ms
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

ll A[MAX];
ll B[MAX];
ll C[MAX];
vector< pair<ll,ll> >V;
vector< ll >Ans;
vector< pair<ll,ll> >VP;
map< ll,ll >M;
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

struct sourav{
	ll b,c;
	sourav(ll e, ll f){
		b = e;
		c = f;
	}
};
vector<sourav>g[MAX];
ll cnt[MAX];
bool vis[MAX];
ll n;
void dfs(int source,int par,int value){
	cnt[source] = 1;
	for(auto each:g[source]){
		int v = each.b;
		if(v == par)continue;
		dfs(v,source,each.c);
		cnt[source] += cnt[v];
	}
	if(source != 1&&vis[source]==0){
		vis[source] = 1;
		V.pb(mp((n - cnt[source]) * cnt[source],value));
	}
}

int main ()
{
    ll a,b,c,d,m,k,l,p,q,r,t,x,y;
    ll cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    scanf("%lld",&t);

    while(t--){
        scanf("%lld",&n);
        for(int i=0;i<=n+10;i++){
        	g[i].clear();
        	cnt[i] = 0;
        	vis [i] = false;
        }
        V.clear();
        for(int i = 0; i < n-1; ++i){
        	scanf("%lld %lld %lld",&a,&b,&c);
        	g[a].pb(sourav(b,c));
        	g[b].pb(sourav(a,c));
        }
		dfs(1,-1,0);
		sum = 0;
		sort(V.rbegin(),V.rend());
		for(int i = 0; i< V.size();i++){
			sum += V[i].first * V[i].second;
		}
		if(sum>=0){
			printf("Case %lld: 0\n",++cntr);
			continue;
		}
		ans = 0;
		for(int i = 0; i < V.size(); i++){
			if(V[i].second>=0)continue;
			sum += (V[i].first*(abs(V[i].second)));
			ans += abs(V[i].second);
			if(sum == 0){
				break;
			}
			if(sum>0){
				sum -= (V[i].first *(abs(V[i].second)));
				ans -= abs(V[i].second);
				a = abs(sum);
				b = a / V[i].first;
				if(a%V[i].first)b++;
				ans += b;
				break;
			}
		}
		printf("Case %lld: %lld\n",++cntr,ans);
    }

    return 0;
}
