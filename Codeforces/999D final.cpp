#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  200006
#define  Max(a,b,c) max(a,max(b,c))
#define  Min(a,b,c) min(a,min(b,c))
#define  mem(a,v)   memset(a,v,sizeof(a))
#define  rep        for (int i=0;i<n;i++)
#define  Rep        for (int i=0;i<m;i++)

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll A[MAX];
ll B[MAX];
ll C[MAX];
ll printans[MAX];

ll rev (ll a,ll b){

    return a>b;
}

int main ()
{

    fastIO();
    vector<ll> V;
    set<ll>S;
    set<ll>::iterator it;

    ll a,b,c;
    ll n,m;
    ll cnt=0,cntr=0,sum=0,ans=1;
    ll p,q,r;
    ll v=1;
    ll check=0;
    ll x,y,z;
    ll Max=0,Min=INT_MAX;
    string s,s1,s3,s4;

    cin>>n>>m;


    for (int i=0;i<n;i++){
        cin>>A[i];
        B[i]=A[i]%m;
        if(i<m)S.insert(i);
    }

    for (int i=0;i<n;i++){
        it=S.lower_bound(B[i]);
        if (it==S.end())it=S.begin();
        ans=*it-B[i];
        if (ans<0){ans+=m;sum+=ans;}
        else sum+=ans;
        C[*it]++;
        printans[i]=A[i]+ans;
        if (C[*it]==n/m)S.erase(*it);
    }
    cout<<sum<<endl;
    for (int i=0;i<n;i++)cout<<printans[i]<<" ";

    return 0;
}
