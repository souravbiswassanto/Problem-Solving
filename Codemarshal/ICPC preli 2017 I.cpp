
// Problem: I. Repeated Digit Sum
// Contest: CodeMarshal - ACM ICPC Dhaka Regional 2017 Online Preliminary Round Hosted by University of Asia Pacific
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-preli-2017/problems/I
// Memory Limit: 1500 MB
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
#define   ull    long long
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
vector< ll >V;
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

ull sod(ull n){
    ull sum = 0;
    while(n != 0){
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
ull f(ull n) {
   while (n >= 10) {
      n = sod(n);
   }
   return n;
}
vector<ll> res[11];
ll fun(char S[], ll Mod)
{
    ll num=0;
    int n = strlen(S);
    for(ll i=0;i< n;i++)
    {
        ll d=S[i]-'0';
        num=num*10+d;
        num %= Mod;

    }
    return num;
}
int main ()
{
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;
    
    for(int i = 1; i <= 9; i++){
        ull ss = 1;
        res[i].pb(-1);
        for(int j = 0; j <= 11; j++)A[j] = 0;
        for(int j = 1; j <= 10; j++){
            ss = 1ULL * ss * i;
            b = f(ss);
            if(A[b])break;
            res[i].pb(b);
            A[b] = 1;
        }
    }

    scanf("%lld", &t);
    char ch[50006], ch1[50006];
    
    for(int cs = 1; cs <= t; cs++){
        scanf("%s %s", ch, ch1);
        n =(int) strlen(ch);
        m =(int) strlen(ch1);
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += ch[i] - '0';
        }
        d =(ll)f(sum);
        
        printf("Case %d: ",cs);
        if(d == 0){
            printf("0\n"); continue;
        }
        if(m == 1 and ch1[0] == '0'){
            printf("1\n"); continue;
        }
        if( d == 3 or d == 6){
            if(d == 3 and m == 1 and ch1[0] =='1'){
                printf("3\n");
            }
            else if(d == 3){
                printf("9\n");
            }
            if(d == 6 and m == 1 and ch1[0] =='1'){
                printf("6\n");
            }
            else if(d == 6){
                printf("9\n");
            }
            continue;
        }
        ll pos = fun(ch1, res[d].size() - 1);
        if(pos == 0) pos = res[d].size() - 1;
        //cout << pos << endl;
        printf("%lld\n", res[d][pos]);
        // 0 er jonno alada kaj kore nite h obe.
    }

    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return 0;
}
