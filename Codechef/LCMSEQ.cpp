// Problem: Subsequence LCM
// Contest: CodeChef - July Cook-Off 2022 Division 2 (Rated)
// URL: https://www.codechef.com/COOK143B/problems/LCMSEQ
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   maxn    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
ll cntr = 0;
const ll MOD = 1e9 + 7;
ll bin_pow(ll o, ll s, ll mod) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    ll d = bin_pow(o, s/2, mod);
    d = (d * 1LL * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}

ll inv[maxn],fact[maxn];
void pre(){
	fact[0]=inv[0]=1;
	for(ll i=1;i<maxn;i++){
		fact[i]=(fact[i-1]*i)%MOD;
	}
	inv[maxn-1]=bin_pow(fact[maxn-1],MOD-2,MOD);
	for(ll i=maxn-2;i>=1;i--){
		inv[i]=(inv[i+1]*(i+1))%MOD;
	}
}
ll ncr(ll n,ll r){
    if(n < 0 || r < 0 || n < r) return 0;
	ll x=fact[n];
	ll y=(inv[r]*inv[n-r])%MOD;
	return (x*y)%MOD;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0,  sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;
    pre();

    while(t--){
        cin >>  n; unordered_map<int, int> M;
        for(int i = 0; i < n; i++){
        	cin >> A[i];
        	M[A[i]]++;
        }
        vector<int> v;
        for(auto it: M)v.pb(it.first);
        for(int i= 0; i <= n + 2; i++)B[i] = 0;
		for(int i = 0; i < n; i++){
			a = sqrt(A[i]);
			for(int j = 1; j <= a; j++){
				if(A[i] % j == 0){
					B[j]++;
					if(A[i] / j <= n and j * j != A[i])B[A[i] / j]++;
				}
			}
		}     
		sum = 0;
		for(int i = 2; i <= n; i++){
			if(B[i] >= i) sum += ncr(B[i], i);
			sum %= MOD;
		}   
		for(auto u: v){
			a = M[u];
			for(int j = 2; j <= a; j++){
				if(j > u)sum += ncr(a, j);
				else{
					if(__gcd(j, u) != j)sum += ncr(a, j);
				}
				sum %= MOD;
			}
		}
		cout << sum << endl;
    }
    /* 
        precedence : ! * / % + - << >> 
        < > <= >= == != & ^ | && ||
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
