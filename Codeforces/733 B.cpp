#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  100006
#define  Max(a,b,c) max(a,max(b,c))
#define  Min(a,b,c) min(a,min(b,c))
#define  mem(a,v)   memset(a,v,sizeof(a))
#define  rep        for (int i=0;i<n;i++)
#define  Rep        for (int i=0;i<m;i++)

void fastIO ()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll A[MAX];
ll B[MAX];
ll C[MAX];

ll rev (ll a,ll b)
{

    return a>b;
}

int main ()
{

    fastIO();
    vector<pair <int,int> > V[MAX];
    set<ll>S;
    set<ll>::iterator it;
    map<string,ll> M;
    map<string,ll>::iterator it1;

    ll a,b,c;
    ll n,m;
    ll cnt=0,cntr=0,sum1=0,sum2=0,ans=0,ans1=0,ans2=0;
    ll p,q,r;
    ll v=0;
    ll check=0;
    ll x,y,z;
    ll Max=0,Min=INT_MAX;
    string s,s1[MAX],s2[MAX],s3,s4;

    cin>>n;

    rep
    {
        cin>>A[i]>>B[i];
        sum1+=A[i];
        sum2+=B[i];
        cnt=abs(A[i]-B[i]);
        Max=max(Max,cnt);
    }
    v =abs(sum1-sum2);
    for (int i=0; i<n; i++)
    {
        ans1=(sum1-A[i])+B[i];
        ans2=(sum2-B[i])+A[i];
        ans=abs(ans1-ans2);
        if (ans>v)
        {
            v=ans;
            cntr=i+1;
        }
    }
    cout<<cntr<<endl;

    return 0;
}
