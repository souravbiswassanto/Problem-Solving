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
T mysqrt (T x){if (x == 0 | x == 1)return x;int start = 1, End = x, ans;while (start <= End){int mid = (start + End) / 2;if (mid*mid == x)return mid;if (mid*mid < x){start = mid + 1;ans = mid;}else End = mid-1;}return ans;}

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

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
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

ll dp (int n,int a,int b){

    if(DP[n]==-1)return;
    if(path[n-1]==1){
            DP[n]=-1;
            return;
    }
    if(path[n-1]==0){
        dp(n-1);
    }
    if(n-a<=0){
        a=0;b=0;
    }

    for(int i=n-a;i>=n-b;i--){

    }
}

int main ()
{
    fastIO();
    ll a,b,c,n,m,k,p,q,r,t;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max= 0,Max1=-1e18+1;
    ll Min = 1e18;
    string s,s1,s3,s4;

    cin>>t;

    for(int k=1;k<=t;k++){
        ll min_j,max_j;
        cin>>n>>min_j>>max_j;

        ll parent[n+1];
        ll path[n+2];
        cout<<"Case "<<k<<": ";

        ll pos=0;
        for(int i=1;i<=n;i++){
            cin>>a;
            path[i]=a;
            if(a==0){
                parent[pos]=i;
                pos=i;
            }
        }
        if(path[1]==1||path[n]==1){
            cout<<"Google Can Not!"<<endl;
            continue;
        }



        if(check){
            cout<<"Google Can Not!"<<endl;
        }
        else cout<<"Google Can!"<<endl;
    }


    return 0;
}
