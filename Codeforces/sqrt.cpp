#include <bits/stdc++.h>
using namespace std ;

#define  ll   long long
#define  pb  push_back
#define  mp  make_pair
#define  MAX  500006
#define  MAX1  10000008
#define  mem(a,v)   memset(a,v,sizeof(a))

template <typename T>
T mymax (T a,T b){return (a>b)?a:b;}
template <typename T>
T mymin (T a,T b){return (a<b)?a:b;}
template <typename T>
T myabs (T a){return (a<0)?(-1*a):a;}
template <typename T>
T mysqrt (T x){if (x == 0 || x == 1)return x;int start = 1, End = x, ans;while (start <= End){int mid = (start + End) / 2;if (mid*mid == x)return mid;if (mid*mid < x){start = mid + 1;ans = mid;}else End = mid-1;}return ans;}

void fastIO (){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
}

ll A[MAX];
ll B[MAX];
ll C[MAX];
vector< ll >V;
vector< ll >Ans;
vector< pair<ll,ll> >VP;
map< ll,ll >M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;

//void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

ll check (ll ans,ll l1,ll l2,ll n,ll m){
    ll a;
    ll left=l1;ll right=l2;ll mid;ll Ans=l2;
    while(left<=right){
            mid=(left+right)/2;
            a=mid*mid*2;
            //cout<<a<<endl;
            if(a<=m){left=mid+1;Ans=mid;}
            else if(a>m){right=mid-1;}
        }
        ans=ans-(l2-Ans);
        //cout<<ans<<endl;
        left=1;right=l1;Ans=l1;
        while(left<=right){
            mid=(left+right)/2;
            a=mid*mid*2;
            //cout<<a<<endl;
            if(a>=n&&a<=m){right=mid-1;Ans=mid-1;}
            else if(a<n){left=mid+1;}
            else if(a>m){right=mid-1;}
        }
        ans=ans+(l1-Ans);
        //cout<<ans<<endl;
        return ans;

}

int main ()
{
    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1;
    float x,y,z;
    ll Max= 0,Max1=-1e18+1;
    ll Min = 1e18;
    string s,s1,s3,s4;

    scanf("%lld",&q);
    while(q--){

        scanf("%lld%lld",&n,&m);
        ans=0;
        cnt=0;

        ll l1,l2;

        l1=mysqrt(n);
        l2=mysqrt(m);

        if(l1*l1!=n&&l2*l2!=m){
            ans=(l2-l1)*2;
            ans=check(ans,l1,l2,n,m);
        }
        if (l1*l1!=n&&l2*l2==m){
            ans=(l2-l1)*2;
            ans=check(ans,l1,l2,n,m);
        }
        if (l1*l1==n&&l2*l2!=m){
            ans=(l2-l1+1)*2;
            ans=check(ans,l1-1,l2,n,m);
        }
        if (l1*l1==n&&l2*l2==m){
            ans=(l2-l1+1)*2;
            ans=check(ans,l1-1,l2,n,m);
        }

//        if(limit1*limit1!=n){limit1++;}
//        //if(limit2*limit2!=m)limit2++;
//        if(limit1<=limit2)ans=(limit2-limit1+1)*2;
//        cout<<"ANS 1 "<<ans<<endl;
//        cout<<limit1<<" "<<limit2<<endl;

//        for(ll i=limit1-1;;i--){
//            a=i*i*2;
//            if(a<=n)break;
//            if(a<=m&&a>=n)ans++;
//        }
//        cout<<"ANS 2 "<<ans<<endl;
//        for(ll i=limit2;;i--){
//            a=i*i*2;
//            if(a<=m)break;
//            if(i>limitans--;
//        }
        printf("Case %lld: %lld\n",++cntr,ans);
    }

    return 0;
}
