
// Problem: 1033 - Generating Palindromes
// Contest: LightOJ
// URL: http://lightoj.com/volume_showproblem.php?problem=1033
// Memory Limit: 32 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// Problem: Very Dirty String
// Contest: Toph
// URL: https://toph.co/p/very-dirty-string
// Memory Limit: 512 MB
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
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
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
vector< int >V;
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
int lookup[1005][1005] ;

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


int main ()
{
    fastIO();
    int a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    

    cin >> t;
    for(int k = 1; k <= t; ++k){
	    cin >> s;
	    n = s.size();
	    s1 = s; m = n;
	    reverse(s1.begin(),s1.end());
	    mem(lookup,-1);
		int ans = lcs(n,m);
		ans = n - ans;
		
		printf("Case %d: %d\n",k,ans);
		
		
	}
    return 0;
}