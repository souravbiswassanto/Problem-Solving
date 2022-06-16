#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   inf   INT_MAX
#define   minf  -1*INT_MAX
#define   ll     long long
#define   ull    unsigned long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
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

int A[MAX];
int B[MAX];
int C[MAX];
vector<int>V;
vector<int>Ans;
vector<pair<int, int>>VP;
map<pair <int, int> , int>M;
map<pair<int,int> , int>vis;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

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
int dp[1000];
/*
void dfs(int source, int par){
	cnt[source] = 1;

	for(auto v:g[source]){
		if(v==par)continue;
		dfs(v,source);
		cnt[source] += cnt[v];
	}
}
*/
int n,CC;
int call (int i, int j){
	vis[{i,j}] = 1;
	vis[{j,i}] = 1;
	int sum = 0;
	if(M[{i,j}] != 1){
		if(!vis[{i-1,j-1}])sum += call(i - 1, j -1) + 1; //up
	}
	if(M[{i,i+1}]!=1){
		if(!vis[{i-n,i}])sum += call(i - n, i) + 1; //left
	}
	if(M[{j,j+1}]!=1){
		if(!vis[{j,j+n}])sum += call(j, j + n) + 1; //right
	}
	if(M[{i+1,j+1}]!=1){
		if(!vis[{i+1,j+1}])sum += call(i + 1, j + 1) + 1; //down
	}
	return sum;
}
int main ()
{
    int a,b,c,d,m,k,l,p,q,r,t,x,y;
    int cntr=0,sum=0,ans=1,check=0;
    int Max= 0,Max1=0,Min=inf;
    string s,s1,s3,s4;

    scanf("%d",&t);

    for(int Case=1; Case <= t; Case++){
    	vector<string>vs;
    	scanf("%d %d",&n,&m);
		char ch[200];
    	for(int i = 1; i <= n; ++i){
    		scanf("%s",ch);
    		vs.pb(ch);
    	}
    	n += 1;
    	ans = 1;
    	M[{1,2}] = 1; M[{2,1}] = 1; M[{n*(m-1)+1,n*(m-1)+2}] = 1; M[{n*(m-1)+2,n*(m-1)+1}] = 1;
    	for(int i = 1; i <= m; i++){
    		for(int j = 1; j <= n; ++j){
    			
    			if(j == 1  ){
    				if(i!=m)M[{ans,ans+n}] = 1;
    				ans++;
    				continue;
    			}
				char chr = vs[j-2][i-1];
				if(chr == 'D'){
					M[{ans,ans+1}] = 1;
					M[{ans+1,ans}] = 1;
				}
				if(chr == 'R'){
					M[{ans,ans+n}] = 1;
					M[{ans+n,ans}] = 1;
				}
				if(chr == 'B'){
					M[{ans,ans+1}] = 1;
					M[{ans+1,ans}] = 1;
					M[{ans+n,ans}] = 1;
					M[{ans,ans+n}] = 1;
				}
    			ans++;
    		}
    	}
    	
    	sum = call(1,1 + n) - (m-1)+1;
    	printf("Case %d: %d\n",Case,sum);
    	M.clear();
    	vis.clear();
    }

    return 0;
}
