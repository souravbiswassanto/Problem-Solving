
// Problem: 1021 - Painful Bases
// Contest: LightOJ
// URL: http://lightoj.com/volume_showproblem.php?problem=1021
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

int A[MAX];

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
int n, base, k;
ll dp[20][1<<16];
ll calc(int rem, int j, int mask){
	if(j == n){
		if(rem == 0)return 1;
		else return 0;
	}
	ll& ret = dp[rem][mask];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = 0; i < n; i++){
		if(!(mask&(1<<i))){
			int val = (rem * base) + A[i];
			ret += calc(val % k, j + 1, mask|(1<<i));
		}
	}
	return ret;
}

int main ()
{
    int a,b,c,d,m,l,p,q,r,t,x,y;
    string s,s1,s3,s4;

    scanf("%d",&t);
    
    for(int cs = 1; cs <= t; cs++){
    	char ch[20];
    	scanf("%d %d",&base,&k);
    	scanf("%s",ch);
    	string s(ch);
    	n = s.size();
    	for(int i = 0; i < n; i++){
    		if(s[i]>=65){
    			A[i] = 10 + s[i] - 65;
    		}
    		else A[i] = s[i] - '0';
    	}
    	mem(dp,-1);
    	printf("Case %d: %lld\n",cs,calc(0,0,0));
    }

    return 0;
}
