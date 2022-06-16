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
map< pair<ll,ll> ,ll >M1;
map< pair<ll,ll> ,ll >M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

int main ()
{
    fastIO();
    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max= 0,Max1=-1e18+1;
    ll Min = 1e18;
    string s,s1,s3,s4;

    cin>>q;

    while(q--){

        cin>>n;
        cin>>s;
        cntr=0;cnt=0;
        M[mp(cntr,cnt)]=1;
        M1[mp(cntr,cnt)]=0;
        ans=0;ll gap=0;
        p=0;r=0;Min=INT_MAX;
        for(int i=0;i<n;i++){
            if(s[i]=='R')cntr++;
            if(s[i]=='L')cntr--;
            if(s[i]=='U')cnt++;
            if(s[i]=='D')cnt--;

            if(M[mp(cntr,cnt)]){
                //cout<<cntr<<" "<<cnt<<" "<<M[mp(cntr,cnt)]<<" "<<M1[mp(cntr,cnt)]<<endl;
                a=M1[mp(cntr,cnt)];
                M1[mp(cntr,cnt)]=i+1;
                M[mp(cntr,cnt)]=1;
                gap=(i+1)-a;
                if(gap<Min){
                    p=a+1;
                    r=i+1;
                    Min=gap;
                }
            }
            else {
                M[mp(cntr,cnt)]=1;
                M1[mp(cntr,cnt)]=i+1;
            }
        }
        M.clear();
        M1.clear();
        if(Min>10000000){
            cout<<-1<<endl;
        }
        else cout<<p<<" "<<r<<endl;
    }

    return 0;
}

/*8
LURDLLRU*/
