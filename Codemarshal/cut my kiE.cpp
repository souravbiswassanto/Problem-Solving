
// Problem: E. Carry My Stuff
// Contest: CodeMarshal - Brain Craft Ltd. - SUB Inter University Programming Contest 2019
// URL: https://algo.codemarshal.org/contests/sub_iupc_19/problems/E
// Memory Limit: 2000 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
/*
ll sti(string a,int base=10)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=base;
		k+=a[i]-'0';
	}
	return k;
}
 
/*
/*
ll bin_pow(ll o, ll s) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    ll d = bin_pow(o, s/2);
    d = (d * 1ll * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}
*/
struct sourav {
    int val, type;
    sourav (int v, int d){
        val = v; type = d;
    }
    bool operator <(sourav other) const{
        if (val == other.val) return type < other.type;
        else return val < other.val;
    }
};
vector <sourav> V;

int main ()
{
    int a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    int cnt=0,cntr=0,sum=0,ans=1,check=0;
    string s,s1,s3,s4;

    //cin>>n;
    int test;
    scanf("%d", &test);
    for (int cs = 1; cs <= test; cs++){
        scanf("%d %d %d", &p, &n, &t);
        //map<int, deque<int>> mq;
        unordered_map<int, deque<int>> mq;
        deque <int> q;
        int Max= -1,Min=INT_MAX;
        for (int i = 0; i < n; i++){
            scanf("%d %d", &a, &b);
            V.pb(sourav(b, a));
        }
        for (int i = 0; i < t; i++){
            scanf("%d",&a);
            V.pb(sourav(a, INT_MAX));
        }
        sort(V.begin(), V.end());
        for (int i = 0; i < V.size(); i++){
            
            if(V[i].type > 1000000006LL){
                int sz = q.size();
                for (int j = 0; j <sz; j++){
                    a = q.front();
                    q.pop_front();
                    if(mq[a].size() > 1){
                        q.push_back(a);
                    }
                    sum = mq[a].front();mq[a].pop_front();
                    Max = max(Max, V[i].val - sum);
                    //cout << sum << " " << a << endl;
                }
            }
            else {
                a = V[i].type;
                if(mq[a].size() == 0){
                    q.push_back(a);
                    //cout << a << endl;
                }
                mq[a].push_back(V[i].val);
            }
        }
        check =  0;
        for (auto it: mq){
            if(it.second.size()){
                check = 1;
            }
        }
        if(check or Max == -1){
            printf("Case %d: -1\n", cs);
        }
        else {
            printf("Case %d: %d\n", cs, Max);
        }
        V.clear();
    }

    return 0;
}
