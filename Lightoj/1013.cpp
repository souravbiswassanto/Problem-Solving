
// Problem: 1013 - Love Calculator
// Contest: LightOJ
// URL: http://lightoj.com/volume_showproblem.php?problem=1013
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

string s,s1,s3,s4;
int lookup[50][50];
ll dp[50][50] ;

int lcs(int n, int m){
	if(n == 0 || m == 0){
		lookup[n][m] = 0;
		return 0;
	}
	if(lookup[n][m] != -1)return lookup[n][m];
	if(s[n-1] == s1[m-1]){
		return lookup[n][m] = max(0,lcs(n-1,m-1)+1);
	}
	else {
		return lookup[n][m] = max(lcs(n-1,m),lcs(n,m-1));
	}
	
}
ll Count(int i, int j){
	if(i==0||j==0){
		return 1LL;
	}
	ll& ret = dp[i][j];
	if(ret!=-1){
		return ret;
	}
	if(s[i-1] == s1[j-1]){
		ret = Count(i-1,j-1);
	}
	else {
		if(lookup[i-1][j]==lookup[i][j-1]){
			ret = Count(i-1,j) + Count(i,j-1);
		}
		else if(lookup[i-1][j]>lookup[i][j-1]){
			ret = Count(i-1,j);
		}
		else {
			ret = Count(i,j-1);
		}
	}
	return ret;
}

int main ()
{
    ll a,n,m,b,c,d,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;

    //cin>>n;
    scanf("%lld",&t);
   // cin>>t;

    for(int cs = 1; cs <= t; cs++){
        cin >> s >> s1;
        n = s.size();
        m = s1.size();
        mem(dp,-1);
        mem(lookup,-1);
        
        int ans = lcs(n,m);
        sum = Count(n,m);
        //cout<<sum<<endl;
        cout<<"Case "<<cs<<": "<<n+m-ans<<" "<<sum<<endl;
		//printf("Case %d: %d %lld\n",cs,n+m-ans,sum);
    }

    return 0;
}
