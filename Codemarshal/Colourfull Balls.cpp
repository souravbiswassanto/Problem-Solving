
// Problem: H. Colorful Balls
// Contest: CodeMarshal - ACM ICPC Dhaka Regional Online Preliminary Contest, 2018 Hosted by Daffodil International University
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-preli-18/problems/H
// Memory Limit: 1500 MB
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
ll mod = 1000000007,n;
ll dp[100004][6];
ll calc(int i, int last, int cur){
	
	if(i>n)return 1;
	if(cur==last)return 0;
	
	ll sum = 0;
	if(A[i]!=0){
		if(dp[i][cur]!=-1)return dp[i][cur]%mod;
		sum = calc(i + 1, cur,A[i+1]) %mod;
		dp[i][cur] = sum;
		return sum;
	}
	else {
		ll a = 0;
		sum =0;
		if(last!=1){
			if(dp[i][1]==-1){
				sum = calc(i+1,1,A[i+1]); sum %= mod;
				dp[i][1] = sum;
				a+=sum;
			}
			else a+=max(0LL,dp[i][1]);
		}
		sum = 0;
		if(last!=2){
			if(dp[i][2]==-1){
				sum = calc(i+1,2,A[i+1]); sum %= mod;
				dp[i][2] = sum;
				a += sum;
			}
			else a+=max(0LL,dp[i][2]);
			
		}
		sum = 0;
		if(last!=3){
			if(dp[i][3]==-1){sum = calc(i+1,3,A[i+1]); sum %= mod;
				dp[i][3] = sum;
				a += sum;
			}
			else a+=max(0LL,dp[i][3]);
		}
		return a;
	}
}

int main ()
{
    fastIO();
    ll a,b,c,d,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //cin>>n;
    scanf("%lld",&t);

    while(t--){
    	char ch[100006];
        scanf("%s",ch);
        n = strlen(ch);
        
        for(int i = 1; i <= n; ++i){
        	if(ch[i-1]=='W')A[i] =  0;
        	if(ch[i-1]=='R')A[i] =  1;
        	if(ch[i-1]=='G')A[i] =  2;
        	if(ch[i-1]=='B')A[i] =  3;
        }
        mem(dp,-1);
		ans = calc(1,-2,A[1])%mod;
		printf("Case %lld: %lld\n",++cntr,ans);
    }

    return 0;
}
