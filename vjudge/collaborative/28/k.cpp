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
#define   MAX    6006
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
string s, s1, s2;
ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;

const int N = 6000;
const ll mod = 1000058831;
const ll mod1 = 1e9 + 123;
const ll P = 193;
const ll Q = 37;
ll h[MAX], pwr[MAX], inv[MAX];
ll h1[MAX], pwr1[MAX], inv1[MAX];

ll bigMod(ll a, ll e, ll MOD){
	if(e == -1) e = MOD - 2;
	ll ret = 1;
	while(e) {
		if(e & 1) ret = ret * a % MOD;
		a = a * a % MOD, e >>= 1;
	}
	return ret;
}

void init_hash(){
	pwr[0] = inv[0] = 1;
	pwr1[0] = inv1[0] = 1;
	ll INV_P = bigMod(P, - 1, mod);
	ll INV_P1 = bigMod(Q, - 1, mod1);
	for(int i = 1; i < N; ++i){
		pwr[i] = pwr[i - 1] * P % mod;
		inv[i] = inv[i - 1] * INV_P % mod;
	}
	for(int i = 1; i < N; ++i){
		pwr1[i] = pwr1[i - 1] * Q % mod1;
		inv1[i] = inv1[i - 1] * INV_P1 % mod1;
	}
	
}
void build(){
	for(int i = 1; i <= n; i++){
		h[i] = (h[i - 1] + (s[i - 1] - 96) * 1LL * pwr[i - 1]) % mod;
		h1[i] = (h1[i - 1] + (s[i - 1] - 96) * 1LL * pwr1[i - 1]) % mod1;
	}
}

ll gethash(int l, int r){
	ll one = (h[r] - h[l - 1]) * inv[l] % mod;
	if(one < 0)return one += mod;
	return one;
}

ll gethash1(int l, int r){
	ll one = (h1[r] - h1[l - 1]) * inv1[l] % mod1;
	if(one < 0)return one += mod1;
	return one;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    init_hash();
	build();
	cin >> n;
    cin >> s;
    
    
    l = 0, r = n / 2;
    
    while(l <= r){
    	int mid = (l + r) / 2;
    	map<ll, ll> M;
    	map<ll, ll> M1;
    	for(int i = 0; i <= n - mid; i++){
    		a = gethash(i + 1, i + mid);
    		b = gethash1(i + 1, i + mid);
    		x = (a << 32) + b;
    		if(M.count(x) == 0) M[x] = i + 1;
    		M1[x] = i + 1;
    	}
    	check = 0;
    	for(auto it: M){
    		a = M1[it];
    		if(a >= it.second + mid){
    			check = 1; break;
    		}
    	}
    	if(check) l = mid + 1;
    	else r = mid - 1;
    } 
    cout << l - 1 << endl;
    
    
    
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
