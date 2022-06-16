
// Problem: D. Strip
// Contest: Codeforces - Codeforces Round #278 (Div. 2)
// URL: https://codeforces.com/contest/488/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

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
vector< ll >V;
vector< ll >Ans;
vector< pair<ll,ll> >VP;
map< ll,ll >M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
ll dp[MAX];
int main ()
{
    fastIO();
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //cin>>n;
    cin >> n >> k >> l;
    
    for (int i = 1; i <= n; i++){
        cin >> A[i];
    }
    deque<ll> q1, q2;
    int cur = 0;
    for (int i = 1; i <= n; i++){
        while(!q1.empty() and A[q1.front()] <= A[i]){
            q1.pop_front();
        }
        q1.push_front(i);
        while(!q2.empty() and A[q2.front()] >= A[i]){
            q2.pop_front();
        }
        q2.push_front(i);
        dp[i] = -1;
        while(i - cur >= l){
            if(dp[cur] != -1 and A[q1.back()] - A[q2.back()] <= k){
                dp[i] = dp[cur] + 1;break;
            }
            cur++;
            while(!q1.empty() and q1.back() <= cur)q1.pop_back();
            while(!q2.empty() and q2.back() <= cur)q2.pop_back();
        }
    }

    cout << dp[n] << endl;

    return 0;
}
