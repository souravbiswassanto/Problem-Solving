#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  1000006

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll a[MAX];
ll b[MAX];
ll c[MAX];

int main ()
{

    ///freopen("output.txt","w",stdout);

    fastIO();
    ll n;
    ll m;
    ll cnt=0;
    ll p,q,r;
    ll cntr=0;
    ll v=0;
    ll check=0;
    ll x,y,z;
    string s,s1,s2;

    cin>>n>>m>>p>>q;

    v=min(n,min(p,q));
    cntr=v*256;

    n=n-v;
    cnt=min(n,m);
    cntr+=(cnt*32);

    cout<<cntr<<endl;

    return 0;
}



