#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  300006
#define  mem(a,v)   memset(a,v,sizeof(a))

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll A[MAX];
ll B[MAX];
ll C[MAX];

int main ()
{

    fastIO();

    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max=-1e18;
    unsigned long long Min = 1e20;
    string s,s1,s3,s4;

    cin>>q;

    while(q--){
        cin>>n>>k;

        for(int i=0;i<n;i++)cin>>A[i];
        sort(A,A+n);

        if(A[0]+k<A[n-1]-k){
            B[cntr++]=-1;
            continue;
        }
        else {
            B[cntr++]=A[0]+k;
        }

    }
    for(int i=0;i<cntr;i++)cout<<B[i]<<endl;

    return 0;
}
