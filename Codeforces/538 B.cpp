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

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll A[MAX];
ll B[MAX];
ll C[MAX];

int Size;
int MAXX;

void Check (int j)
{
    int c=0;
    while (j)
    {
        int rem=j%10;
        j/=10;
        A[c++]=rem;
        MAXX=max(MAXX,rem);
        Size++;
    }
}

ll rev (ll a,ll b){

    return a>b;
}

int main ()
{

    fastIO();
    vector<ll> V;
    set<ll>S;
    set<ll>::iterator it;
    map<string,ll> M;
    map<string,ll>::iterator it1;

    ll a,b,c;
    ll n,m;
    ll cnt=0,cntr=0,sum=0,ans=1;
    ll p,q,r;
    ll v=1;
    ll check=0;
    ll x,y,z;
    ll Max=0,Min=INT_MAX;
    float ss;
    string s,s1[MAX],s2[MAX],s3,s4;

    cin>>n;

    Check(n);

    for (int i=Size-1;i>=0;i--){
        for (int j=1;A[i]>0;j++){
                ss=pow(10,i);
                B[j-1]+=ss;
                A[i]--;
        }
    }
    cout<<MAXX<<endl;
    for (int i=0;i<MAXX;i++)cout<<B[i]<<" ";

    return 0;
}
