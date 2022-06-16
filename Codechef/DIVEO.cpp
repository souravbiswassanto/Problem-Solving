
// Problem: Division 
// Contest: CodeChef - CodeChef Starters 15 Division 1 (Unrated)
// URL: https://www.codechef.com/START15A/problems/DIVEO
// Memory Limit: 256 MB
// Time Limit: 500 ms
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
vector<int>prime;
bool mark[MAX1];
int N=32000;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}

int main ()
{
    int a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    int cntr=0, cnt, sum=0,ans=1,check=0;
    int Max= 0,Max1=-1,Min=0;
    string s,s1,s3,s4;

    //cin>>n;
    seive();
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &a, &b);
        m = n;
        for(int i = 0; prime[i] * prime[i] <= m; i++){
            if(m % prime[i])continue;
            while(m % prime[i] == 0){
                V.pb(prime[i]);
                m /= prime[i];
            }
        }
        if(m != 1)V.pb(m);
        int odd = 0; int even = 0; cntr = cnt = 0;
        for(int i = 0; i < V.size(); i++){
            if(V[i] % 2) odd += b, cntr++;
            else even += a, cnt++;
        }
        
        if(a >= 0 and b >= 0){
            printf("%d\n", odd + even);
        }
        else if(a < 0 and b < 0){
            if(n % 2)printf("%d\n", b);
            else printf("%d\n", a);
        }
        else if(cntr and cnt){
            if(a >= 0)
            printf("%d\n", even);
            else{
                printf("%d\n", odd + a);
            }
        }
        else if(cntr){
            printf("%d\n", max(b, odd));
        }
        else printf("%d\n", max(a, even));
        
        V.clear();
    }

    return 0;
}
