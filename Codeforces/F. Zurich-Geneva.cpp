//#include<bits/stdc++.h>
//using namespace std;
//
//#define ll long long
//#define MAX 200006
//#define logn 20
//#define MAX_N 200010
//
//
//int tree[4*MAX],A[MAX],paisi,value;
//
//void build (int node,int b,int e){
//
//    if(b==e){
//        tree[node]=1;return;
//    }
//    int mid=(b+e)/2;
//    int l=node*2;
//    int r=node*2+1;
//    build(l,b,mid);
//    build(r,mid+1,e);
//    tree[node]=tree[l]+tree[r];
//}
//
//void rmq(int node,int b,int e,int l,int r,int ck){
//
//    if(paisi)return;
//    if(b>r||e<l)return;
//    if(l<=b&&e<=r&&tree[node]==0)return;
//    if(b==e&&tree[node]!=0){
//        paisi=1;
//        value=b;return;
//    }
//    int lr=node*2;
//    int rr=node*2+1;
//    int mid=(b+e)/2;
//    if(ck){
//        rmq(lr,b,mid,l,r,ck);
//        rmq(rr,mid+1,e,l,r,ck);
//    }
//    else {
//        rmq(rr,mid+1,e,l,r,ck);
//        rmq(lr,b,mid,l,r,ck);
//    }
//}
//
//void update (int node,int b,int e,int unode){
//
//    if(unode<b||unode>e)return;
//    if(b==e){
//        tree[node]=0;return;
//    }
//    int mid=(b+e)/2;
//    int l=node*2;
//    int r=node*2+1;
//    update(l,b,mid,unode);
//    update(r,mid+1,e,unode);
//    tree[node]=tree[l]+tree[r];
//}
//
//int main(){
//
//    int n,m;
//    cin>>n>>m;
//
//    build(1,1,m);
//    for(int i=1;i<=n;i++){
//        value = -1e9;
//        int a;
//        cin>> a;
////        if(A[a]==0){
////            cout<<a<<" ";
////            A[a]=1;update(1,1,m,a);continue;
////        }
//        rmq(1,1,m,1,a,0);paisi=0;
//
//        int b=value;
//        value = 1e9;
//        if(a!=m)rmq(1,1,m,a+1,m,1);paisi=0;
//        int c = value;
//        int selected = b==-1e9? c: b;
//        update(1,1,m,selected);
//
//        cout<<selected<<" ";
//    }
//
//
//
//    return 0;
//}
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

int main ()
{
    fastIO();
    ll a,b,c,n,m,k,p,q,r;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    float x,y,z;
    ll Max= 0,Max1=-1e18+1;
    ll Min = 1e18;
    string s,s1,s3,s4;

    cin>>n>>m;
    set<ll>S;
    for(int i=1;i<=m;i++){
        S.insert(i);
    }

    for(int i=1;i<=n;i++){
        cin>>a;
        if(A[a]==0){
            cout<<a<<" ";
            A[a]=1;
            S.erase(a);continue;
        }
        auto it=S.begin();
        cout<<*it<<" ";
        A[*it]=1;
        S.erase(it);
    }

    return 0;
}
