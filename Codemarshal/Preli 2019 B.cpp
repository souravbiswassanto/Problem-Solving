
// Problem: B. The Social Network
// Contest: CodeMarshal - ICPC Dhaka Regional Preliminary Contest, 2019 Hosted by Southeast University
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-19-preli/problems/B
// Memory Limit: 1500 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;
using namespace __gnu_pbds;

#define   Pi     2*acos(0.0)
#define   LINF   1LL<<62
#define   ll     long long
#define   ull    unsigned long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    100006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define buga  cout<<1<<endl
#define bugb  cout<<2<<endl
#define bugc  cout<<3<<endl
#define bugd  cout<<4<<endl
#define buge  cout<<5<<endl

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

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

vector<ll>List[MAX];
vector<ll>post[MAX];
//vector< oset< pair<ll,ll> > Set;
vector< oset <pair<ll,ll> > > Set(MAX);
int parent[MAX],cnt  = 0;

void make_set(int n){
	for(ll i =1 ; i <= n; ++i){
		parent[i] = i;
		List[i] = vector<ll>(1,i);
	}
}
void make_union(int u, int v){
	int a = parent[u];
	int b = parent[v];
	if(a != b){
		if(List[a].size()<List[b].size())swap(a,b);
		while(!List[b].empty()){
			int x = List[b].back();
			parent[x] = a;
			//cout<<a<<" "<<x<<" "<<parent[x]<<endl;
			List[b].pop_back();
			List[a].pb(x);
			//cout<<a<<" px "<<x<<endl;
		}
	//	cout<<b<<" "<<post[b].size()<<endl;
		for(auto it:Set[b]){
			Set[a].insert({it.first,it.second});
		}
		Set[b].clear();
		//cout<<a<<endl;
		//for(auto it:post[a])cout<<it<<" ";cout<<endl;
	}
}

int main ()
{
    fastIO();
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;
    cout<<(1LL<<62)<<endl;

    scanf("%lld",&t);

    while(t--){
        scanf("%lld %lld",&n,&q);
        printf("Case %lld:\n",++cntr);
        make_set(n);
        for(int j = 1; j <= q; ++j){
        	char ch;
        	scanf("%lld",&m);
        	//cout<<"cntrrrrr "<<j<<endl;
        	if(m == 0){
        		scanf("%lld %lld",&a,&b);
        		make_union(a,b);
        		//for(auto it:List[b])cout<<it<<" ";cout<<endl;
        	}
        	else if(m == 1){
        		scanf("%lld %lld",&a,&b);
        		p = parent[a];
        		Set[p].insert({b,++cnt});
        		//cout<<a<<" j "<<p<<endl;
        		//for(auto it:post[p])cout<<it<<" ";cout<<endl;
        	}
        	else {
        		scanf("%lld %lld %lld",&a, &b, &c);
        		p = parent[a];
        		l = 0; r = 0;
        		//l = Set.order_of_key({b-1,INT_MAX});
        		l = Set[p].order_of_key({b-1,100000000000});
        		//r = Set.order_of_key({c+1,0});
        		r = Set[p].order_of_key({c+1,0});
        		printf("%lld\n",r-l);
        	}
        }
		for(int i =0; i<=n ; ++i){
			List[i].clear();
			Set[i].clear();
		}
    }

    return 0;
}
