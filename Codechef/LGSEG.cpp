
// Problem: Longest Good Segment
// Contest: CodeChef - July Lunchtime 2021 Division 2
// URL: https://www.codechef.com/LTIME98B/problems/LGSEG
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
vector< ll >Ans;
map< ll,ll >M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){ll limit = sqrt(N*1.0)+2;mark[1]=1;for (ll i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (ll i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (ll j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
/*
ll sti(string a,ll base=10)
{
	ll k=0;
	for (ll i=0;i<(ll)a.size();++i)
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
vector<ll> G[MAX];

ll ans = 0, k;
bool visited[MAX];
void dfs(ll n){
    //cout << n << endl;
    visited[n] = true;
    for(auto i: G[n]){
        if(visited[i] == true)continue;
    
        V.pb(V.back() + n - i);
        //for(auto it: V)cout << it<<" "; cout << endl;
        if(V.size() <= k + 1){
            ans = max(ans, V.back());
            //cout<<"back "<< V.back()<< endl;
        }
        else {
            //cout <<"back "<< V.back()<<" "<<V[V.size() - k - 1]<< endl;
            ans = max(ans, V.back() - V[V.size() - k -1]);
        }
        //cout << ans<<" ans "<< endl;
        dfs(i);
        if(V.size())V.pop_back();
    }
}


int main ()
{
    
    ll a,b,c,d,n,m,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //cin>>n;
    scanf("%lld", &t);

    while(t--){
        scanf("%lld %lld %lld", &n, &k, &sum);
        vector<ll> VP;
        
        for(ll i = 0; i <= n + 4;i++){
            B[i] = 0;
            C[i] = 0;
            visited[i] = 0;
            G[i].clear();
        }
        
        for(ll i = 1; i <= n; i++){
            scanf("%lld", &a);
            B[i] = B[i - 1] + a;
            VP.pb(B[i]);
        }
        VP.pb(1e16);
        for(ll i = 1; i <= n; i++){
            auto pos = upper_bound(VP.begin(), VP.end(),B[i -1] + sum) -VP.begin();
            //if(a)G[a].pb(i);
            //else G[n + 1].pb(i);
            //cout << pos << endl;
            G[pos + 1].pb(i);
            //cout << i <<" "<<a << endl;
        }
        /*for(ll i = 0; i <= n + 2; i++){
            cout << i << endl;
            for(auto it: G[i])cout << it <<" "; cout << endl << endl;
        }*/
        V.pb(0);
        dfs(n + 1);
        printf("%lld\n", ans);
        ans = 0;
        V.clear();
    }
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return 0;
}
