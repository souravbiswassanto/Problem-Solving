#include <bits/stdc++.h>
using namespace std ;

#define  ll   unsigned long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  500006
#define  MAX1  10000008
#define  mem(a,v)   memset(a,v,sizeof(a))

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

ll power[MAX];
ll hashvalue[MAX];
ll Ans[MAX],A[MAX],B[MAX];
ll mod=1e9+7;
ll prime=137;
map<ll,ll>M;
vector<ll>V;
ll Counter;

//void prepowersave(){power[0]=1;for(int i=1;i<=100006;i++){power[i]=((power[i-1]%mod)*prime)%mod;}}

//ll bigmod(ll base,ll exponent){if(exponent==0)return 1;ll r=bigmod(base,exponent/2);if(exponent%2){return (((r%mod)*(r%mod))%mod*base)%mod;}else {return ((r%mod)*(r%mod))%mod;}}

//ll moduloinverse(ll base){return bigmod(base,mod-2);}

/*void prehash_calc(string s){
    hashvalue[1]=s[0]*prime;
    for(int i=2;i<=s.size();i++){
        hashvalue[i]=(hashvalue[i-1]%mod+(s[i-1]*power[i]%mod)%mod)%mod;
    }
}
*/

int main ()
{
    fastIO();
    ll a,b,c,n,m,k,p,q,r,l,x,y,z,t;
    ll cnt=0,cntr=0,sum=0,ans=0,check=0;
    double X,Y,Z;
    ll Max= 0,Max1=-1e18+1;
    ll Min = 1e18;
    string s,s1,s3,s4;

    //prepowersave();
    cin>>q;

    while(q--){
        cin>>n;
        ll C[n+6];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
    }

    return 0;
}

