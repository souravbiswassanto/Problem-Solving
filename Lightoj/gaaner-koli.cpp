
// Problem: Gaaner Koli
// Contest: Toph
// URL: https://toph.co/p/gaaner-koli
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
int taken[27],firstch[27];
int particular[24][27],n;
char ch[100006];
int dp[27][1<<22];

bool winorloss(int k,int mask,int ch){
	if(k == n)return 1;
	int& ret= dp[ch][mask];
	if(ret != -1)return 1^ret;
	ret = 0;
	for(int i = 0; i < n; i++){
		if((!(mask&(1<<i))) and firstch[i] == ch){
			for(int j = 0; j < 26; j++){
				if(!particular[i][j])continue;
				ret = winorloss(k+1,mask|(1<<i),j);
				if(ret)return 0;
			}
		}
	}
	return 1^ret;
}
int main ()
{
    int a,b,c,d,m,k,l,p,q,r,t,x,y;
    int cntr=0,sum=0,ans=1,check=0;
    int Max= 0;
    string s,s1,s3,s4;

    //cin>>n;
    scanf("%d",&t);

    while(t--){
    	scanf("%d",&n);
    	
    	for(int i = 0; i < 27; i++){
    		firstch[i] = -1;
    		taken[i]=0;
    	}
    	mem(particular,0);
    	mem(dp,-1);
    	for(int i = 0; i < n; i++){
    		scanf("%s",ch);
    		for(int j = 0; ch[j]; ++j){
    			particular[i][ch[j]-'a']++;
    		}
    		firstch[i] = ch[0] - 'a';
    		taken[ch[0] - 'a'] = 1;
    	}
    	ans = 1;
    	for(int i = 0 ; i < 26; i++){
    		ans = 1;
    		if(taken[i]){
    			ans &= winorloss(0,0,i);
    			if(!ans)break;
    		}
    	}
    	if(ans==1)printf("Case %d: NO\n",++cntr);
    	else printf("Case %d: YES\n",++cntr);
		
    }

    return 0;
}

