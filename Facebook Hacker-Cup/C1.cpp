#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   LINF   1LL<<62
#define   ll     long long
#define   ull    unsigned long long
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

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

ll A[MAX];
ll B[MAX];
ll C[MAX];
vector< ll >V;
vector< pair<ll,ll> >VP;
map< ll,ll >M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
/*
ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}
 
/*
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

set<ll> G[1000];
int parent[1000];
ll cost[1000], Ans, U;

void dfs(int source, int par, ll Cost){
    Ans = max(Ans, Cost);
    for(auto v: G[source]){
        if(v == par)continue;
        parent[v] = source;
        dfs(v, source, cost[v] + Cost);
    }
    if(Cost == Ans)U = source;
}
void removeEdge(int u){
    while(parent[u] != u){
        int v = parent[u];
        cost[u] = 0;
        G[u].erase(v);
        G[v].erase(u);
        u = v;
    }
}

int main ()
{
    fastIO();
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //freopen("H:/All study/Onedrive/1Programming/Facebook Hackercup/in.txt","r",stdin);
    //freopen("H:/All study/Onedrive/1Programming/Facebook Hackercup/out.txt","w",stdout);
    
    //cin>>n;
    cin>>t;

    while(t--){
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin >>  cost[i];
            parent[i] = i;
        }
        for(int i = 1; i < n; i++){
            cin >> a >> b;
            G[a].insert(b);
            G[b].insert(a);
        }
        Ans = 0;
        dfs(1, 0, cost[1]);
        sum = 0; sum += Ans; Ans = 0; parent[1] = 1;
        removeEdge(U); dfs(1, 0, 0);
        //cout << sum << endl;
        sum += Ans;
        cout <<"Case #"<<++cnt<<": ";
        cout << sum << endl;
        for(int i = 0; i <= n; i++){
            G[i].clear();
            parent[i] = i;
        }

    }
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
