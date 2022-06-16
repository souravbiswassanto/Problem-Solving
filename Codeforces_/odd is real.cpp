#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  500006
#define  MAX1  10000008
#define  mem(a,v)   memset(a,v,sizeof(a))

template <typename T>
T mymax (T a,T b)
{
    return (a>b)?a:b;
}
template <typename T>
T mymin (T a,T b)
{
    return (a<b)?a:b;
}
template <typename T>
T myabs (T a)
{
    return (a<0)?(-1*a):a;
}
//template <typename T>
ll mysqrt (ll x)
{
    if (x == 0 | x == 1)
        return x;
    ll start = 1, End = x, ans;
    while (start <= End)
    {
        ll mid = (start + End) / 2;
        if(mid>1e9+7){
            End=mid-1;
            continue;
        }
        if (mid*mid == x)
            return mid;
        if (mid*mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            End = mid-1;
    }
    return ans;
}

void fastIO ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}


int find1(int n)
{

    ll mid;
    ll l=1;
    ll r=mysqrt(n)+6;

    while(l<=r){

    }

}

int main ()
{
    fastIO();
    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max= 0,Max1=-1e18+1;
    ll Min = 1e18;
    string s,s1,s3,s4;

    while(cin>>n){
        a=mysqrt(n);
        b=sqrt(n);
        cout<<b<<" "<<a<<endl;
        cout<<(a*a)<<endl;
    }
    return 0;
}
