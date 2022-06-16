#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  300006
#define  mem(a,v)   memset(a,v,sizeof(a))


ll A[MAX];
ll B[MAX];
ll C[MAX];

int main ()
{

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    ll Min = 1e18;
    string s,s1,s3,s4;

    cin>>p>>q>>r;

    cin>>a>>b>>c;

    if (a<p||(a-p+b)<q||((a+b+c)-(p+q))<r)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;



    return 0;
}
