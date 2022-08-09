#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
//#pragma GCC diagnostic ignored "-Wformat"

using namespace std ;

#define   Pi     2*acos(0.0)
#define   LINF   1LL<<63
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


pair<ll,ll>dp[11][11][2][2];
bool vis[12][12][2][2];
ll n;
pair<ll,ll> calc(int idx,int tight, int last,int taken){
	if( idx == 0){
		if(last == 0) return {1,1}; 
		else return {1,0};
	}	
	pair<ll,ll>& ret = dp[idx][last][tight][taken];
	if(vis[idx][last][tight][taken ])return ret;
	vis[idx][last][tight][taken] = 1;
	ret.first = 0; ret.second = 0;
	int limit = (tight==0)?A[idx]:9;
	for(int k = 0; k <= limit; k++){
		pair<ll,ll>p;
		p = calc(idx-1,tight|(A[idx] > k),k,taken|(k>0)?1:0);
		ret.first += p.first;
		ret.second += p.second;
	}
	if(last == 0 && taken)ret.second += ret.first;
	return ret;
}
int main ()
{
    fastIO();
    ll a,b,c,d,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    cin>>t;

    while(t--){
        cin>>m>>n;
        pair<ll,ll>ans,sum; mem(vis,0);
        cntr = 0;
        cnt = 0; 
        m--;
    	if(n==0)A[++cntr] = 0;
        while(n){
        	A[++cntr] = n % 10; n /= 10;
        }
        n = cntr; 
    	ans = calc(n,0,4,0);mem(vis,0);
	   if(m == 0)A[++cnt] = 0;
	    while(m&&m>0){
	        A[++cnt] = m % 10;
	        m /= 10;
	     }
	    n =  cnt;
		sum = calc(n,0,9,0);
		if(m == -1)sum.second = 0;
		printf("Case %lld: %lld\n",++Max,ans.second-sum.second);
    }

    return 0;
}
