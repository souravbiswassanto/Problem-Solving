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

void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

int A[18];
int B[18];
int C[MAX];
vector<int>V;
vector<int>Ans;
vector<pair<int, int>>VP;
map<int, int>M;
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
int dp[1<<17];

bool isdegenrated_triangle(int ax,int ay, int bx, int by, int cx, int cy){
	int res = ax*(by-cy)+bx*(cy-ay) + cx*(ay-by);

	return res == 0?1:0;
}
int Max,n;
int calc( int mask){
	int& ret = dp[mask];
	if(ret != -1)return ret;
	if(mask == Max)return 0;
	int val = Max - mask;
	if((val&(val-1)) == 0)return 1;
	
	ret = 10000000;
	for(int i = 0; i < n; i++){
		int temp = mask;
		if(temp&(1<<i))continue;
		
		temp |= (1<<i);
		for(int j = i+1; j < n; j++){
			int tmp = temp;
			if( (tmp&(1<<j)))continue;
			tmp |= (1<<j);
			for(int k =  0; k < n; k++){
				if(tmp&(1<<k))continue;
				if(isdegenrated_triangle(A[i],B[i],A[j],B[j],A[k],B[k])){
					tmp = tmp | (1<<k);
				}
			}
			ret = min(ret,1 + calc(tmp));
		}
		break;
	}
	return ret;
}
int main ()
{
    fastIO();
    int a,b,c,d,m,k,l,p,q,r,t,x,y;
    int cntr=0,sum=0,ans=1,check=0;
    int Max1=0;
    string s,s1,s3,s4;

    //cin>>n;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n); Max = (1<<n)-1;
        for(int i = 0; i < n; i++){
        	scanf("%d %d",&A[i],&B[i]);
        }
        mem(dp,-1);
		printf("Case %d: %d\n",++cntr,calc(0));
    }

    return 0;
}
