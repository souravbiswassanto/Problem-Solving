
// Problem: Festival
// Contest: Google Coding Competitions - Round F 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435bae/0000000000887dba
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define   Pi     2*acos(0.0)
#define   LINF   1LL<<62
#define   ll     long long
#define   ull    unsigned long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define buga  cout<<1<<endl
#define bugb  cout<<2<<endl
#define bugc  cout<<3<<endl
#define bugd  cout<<4<<endl
#define buge  cout<<5<<endl

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

ll A[MAX];
ll B[MAX];
ll C[MAX];
vector< ll >Ans;
vector< pair<ll,ll> >VP;
map< ll,ll >M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Sort{
    ll a, b, c;
    Sort(ll d, ll e, ll f){
        a = d;
        b = e;
        c = f;
    }
    bool operator<(Sort other)const{
        if(a == other.a){
            return b < other.b;
        }
        return a < other.a;
    }
};

int main ()
{
    fastIO();
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //cin>>n;
    cin>>t;

    while(t--){
        cin>> d >> n >> k; vector<Sort> V;
        for(int i = 0; i < n; i++){
            cin >> a >> b >> c;
            V.pb(Sort(b, 1, a));
            V.pb(Sort(c, 2, a));
        }
        sort(V.begin(), V.end());
        
        oset<ll> S; sum = 0;
        for(int i = 0; i < 2 * n; i++){
            if(V[i].b == 2){
                if(S.size() <= k){
                    sum -= V[i].c;
                    c = S.order_of_key(-V[i].c);
                    S.erase(S.find_by_order(c));
                }
                else{
                    c = S.order_of_key(-V[i].c);
                    if(c >= k){
                        S.erase(S.find_by_order(c));
                    }
                    else{
                        auto it = S.find_by_order(k);
                        a = *it; a = -a;
                        sum =sum - (V[i].c - a);
                        S.erase(S.find_by_order(c));
                    }
                }
            }
            else {
                if(S.size() < k){
                    S.insert(-V[i].c);
                    sum += V[i].c;
                }
                else{
                    auto it = S.find_by_order(k - 1);
                    a = *it; a = -a;
                    if(a < V[i].c){
                        sum += (V[i].c - a);
                    }
                    S.insert(-V[i].c);
                }
            }
            Max = max(Max, sum);
            
        }
        cout<<"Case #"<<++cnt<<": "<<Max<<endl;
        sum = Max = 0;
    }
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
