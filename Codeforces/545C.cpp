
// Problem: C. Woodcutters
// Contest: Codeforces - Codeforces Round #303 (Div. 2)
// URL: https://codeforces.com/problemset/problem/545/C
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
ll dp[100006][3];
int main ()
{
    fastIO();
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;
    
    cin>>n;
    A[0] = -1 * INT_MAX; B[0] = 0; dp [0][0] = dp[0][1] = 0; A[n+1] = INT_MAX;B[n+1] = 1;

    for(int i = 1; i <= n; ++i){
    	cin>> A[i] >> B[i];
    }
    
    for(int i =1; i <= n; ++i){
    	
    	if(A[i - 1] + B[i-1] <  A[i] - B[i]){
    		dp[i][0] = dp[i-1][1] + 1;
    		dp[i][1] = dp[i][0];
    		B[i] = 0;
    	}
    	else {
    		if(A[i]+B[i]<A[i+1])dp[i][1] = max (dp[i -1][0],dp[i-1][1]) + 1;
    		else { B[i] = 0; dp[i][1] = max(dp[i -1][0],dp[i-1][1]) ;}
    	}
    }
    
    cout<<max(dp[n][0],dp[n][1])<<endl;

    return 0;
}
