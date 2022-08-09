
// Problem: 1030 - Discovering Gold
// Contest: LightOJ
// URL: http://lightoj.com/volume_showproblem.php?problem=1030
// Memory Limit: 32 MB
// Time Limit: 2000 ms
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
double dp[1000];
bool vis[106];
int n;
double calc(int i){
	if(i == n-1)return A[i];
	double& ret = dp[i];
	if(vis[i])return ret;
	vis[i] = 1; ret = 0.0;
	
	int limit = min(6,n - i-1);
	//cout<<limit<<endl;
	for(int j = 1; j <= limit; j++){
		ret += calc(i+j) + A[i];
	}
	ret /= (double)limit;
	return ret;
}

int main ()
{
    ll a,b,c,d,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //cin>>n;
   	scanf("%lld",&t);
   	
   	for(int cs = 1; cs <= t; cs++){
   		scanf("%d",&n);
   		for(int i = 0; i < n; i++){
   			scanf("%lld",&A[i]);
   		}
   		mem(vis,0);
   		mem(dp,0);
   		a = A[0];
   		A[0] = 0;
   		double res = calc(0) + a;
   		printf("Case %d: %.10lf\n",cs,res);
   		
   	}

    return 0;
}
