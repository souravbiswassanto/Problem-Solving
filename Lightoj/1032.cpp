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
map<int, int>M;
vector<ll>prime;
bool mark[MAX1];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

pair<ll,ll>dp[34][2][2];
bool vis[34][2][2];

pair<ll,ll> calc(int idx, int last, int tight){
	if(idx == 0){
		int chk = B[idx] and B[idx+1];
		if(last == 0)return {0,1};
		else return {0,2};
	}
	pair<ll,ll>& ret=dp[idx][last][tight];
	if(vis[idx][last][tight] == 1)return ret;
	vis[idx][last][tight] = 1;
	int limit = (tight==1)?1:A[idx];
	ret.first = 0;
	ret.second = 0;
	for(int i = 0; i<=limit; i++){
		B[idx] = i;
		pair<ll,ll> P;
		P = calc(idx-1,i,tight|(i<A[idx]));
		ret.first += P.first;
		ret.second = P.second;
	}
	ll a = 0;
	if(limit)a = (1LL<<idx) + (1LL<<(idx-1));
	if(last)ret.second += (1LL<<(idx));
	if(last&&limit)ret.first += (ret.second-a);
	
	return ret;
}
int main ()
{
    int a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    int cntr=0,sum=0,ans=1,check=0;
    int Max= 0;
    string s,s1,s3,s4;

    //cin>>n;
    scanf("%d",&t);

    for(int cs = 1; cs <=t ; cs++){
        scanf("%d",&n);
        mem(vis,0);
        mem(dp,0);
        cntr = 0;
        while(n){
        	A[++cntr] = n % 2;
        	n /= 2;
        }
        pair<ll,ll>Fol = calc(cntr,0,0);
        printf("Case %d: %lld\n",cs,Fol.first);
        for(int i = 0 ; i <= cntr; i++){
        	B[i] = A [i ] = 0;
        }

    }

    return 0;
}
