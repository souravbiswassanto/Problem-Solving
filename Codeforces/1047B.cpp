#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  200006
#define  mem(a,v)   memset(a,v,sizeof(a))

ll A[MAX];
ll B[MAX];
ll C[MAX];

int main ()
{
    vector<ll> V;
    set<ll>S;
    set<ll>::iterator it;

    ll a,b,c,l,n,m,k,p,q,r,v;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0,Max=0,Min=INT_MAX;
    float d,e,f,x,y,z;
    string s,s1,s3,s4;

    cin>>n;

    for (int i=1;i<=n;i++){
        cin>>a>>b;

        sum=a+b;

        if (sum>Max)Max=sum;

    }
    cout<<Max<<endl;

    return 0;
}
