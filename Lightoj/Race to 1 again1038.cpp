#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   inf   INT_MAX
#define   minf  -1*INT_MAX
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

int A[MAX];
int B[MAX];
int C[MAX];
vector<int>V;
vector<int>Ans;
vector<pair<int, int>>VP;
map<int, int>M;
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
/*
void dfs(int source, int par){
	cnt[source] = 1;
	
	for(auto v:g[source]){
		if(v==par)continue;
		dfs(v,source);
		cnt[source] += cnt[v];
	}
}
*/
vector<int>divisor[100006];
double dp[100006];
bool vis[100006];
void div(){
	for(int i = 2; i <= 100000; i++){
		for(int j = i; j <= 100000; j += i){
			divisor[j].pb(i);
		}
	}
}

double calc(int n){
	if(n==1)return 0;
	double& ret = dp[n];
	if(vis[n])return ret;
	ret = 1;
	int Size = divisor[n].size();
	for(int i = 0; i < Size; i++){
		ret += calc(n/divisor[n][i]) + 1;
	}
	ret /= (double)Size;
	return ret;
}
int main ()
{
    fastIO();
    int a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    int cntr=0,sum=0,ans=1,check=0;
    string s,s1,s3,s4;

    //cin>>n;
    div();
    
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++){
    	scanf("%d",&n);
    	printf("Case %d: %.10lf\n",cs,calc(n));
    }

    return 0;
}
