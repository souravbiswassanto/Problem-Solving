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


vector<ll> V;

bool Check (int j)
{

    while (j)
    {
        int rem=j%10;
        j/=10;
        if (rem!=4&&rem!=7)return false;
    }
    return true;
}

void fun()
{
    int ans=1;
    int check=0;

    for (int i=1; i<=9; i++)
    {
        if (check==1)break;
        for (int j=4*ans; j<5*ans; j++)
        {
            if (j%10==4||j%10==7)
            {
                if (Check(j)==true)
                {
                    V.pb(j);
                }
            }
        }
        for (int j=7*ans; j<8*ans; j++)
        {
            if (j>777777777)
            {
                break;
                check=1;
            }
            if (j%10==4||j%10==7)
            {
                if (Check(j)==1)
                {
                    V.pb(j);
                }
            }
        }
        ans*=10;
    }


}

ll rev (ll a,ll b)
{

    return a>b;
}

int main ()
{

    fastIO();
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
    int Ans;
    ll Max=0,Min=INT_MAX;
    string s,s1[MAX],s2[MAX],s3,s4;
    fun();
    cin>>n;

    cout << lower_bound(V.begin(),V.end(), n) -V.begin()+1;

    return 0;
}
