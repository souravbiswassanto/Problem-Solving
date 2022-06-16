
// Problem: 2-D Point Meeting
// Contest: CodeChef - September Challenge 2021 Division 2 (Unrated)
// URL: https://www.codechef.com/SEPT21B/problems/POINTMEE
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

int main ()
{
    fastIO();
    ll a,b,c,d,n,m,k,l,p,q,r,t,x,y;
    ll cnt=0,cntr=0,sum=0,ans=1,check=0;
    ll Max= 0,Max1=-1e18+1,Min=LINF;
    string s,s1,s3,s4;

    //cin>>n;
    cin>>t;

    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int i = 0; i < n; i++)cin >> B[i];
        Min = 1e18;
        for(int i = 0; i <n; i++){
            cntr = 0;
            for(int j = 0; j < n; j++){
                if(i == j)continue;
                a = A[i] - A[j];
                b = B[i] - B[j];
                
                if(abs(a) ==abs(b))cntr++;
                else if(!a or !b)cntr++;
                else cntr += 2;
                //  cout << cntr << endl;
            }
            Min = min(Min, cntr);
            //cout << cntr << endl;
        }
        set<pair<int, int>>S;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a = (A[i] - A[j]);
                b = (B[i] - B[j]);
                p = -INT_MAX;
                if(a % 2){
                    c = (A[i] + A[j]) / 2;
                }
                else {
                     p
                }
                S.insert({a, b});
            }
        }
        for(auto it: S){
            cntr = 0; a = it.first; b = it.second;
            for(int j = 0; j < n; j++){
                if(A[j] == a and B[j] == b)continue;
                c = a - A[j];
                d = b - B[j];
                
                if(abs(c) ==abs(d))cntr++;
                else if(!c or !d)cntr++;
                else cntr += 2;
                //  cout << cntr << endl;
            }
            Min = min(Min, cntr);
            //cout << cntr << endl;
        }
        cout << Min << endl;

    }
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
