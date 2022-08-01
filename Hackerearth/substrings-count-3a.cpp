
// Problem: SUBSTRINGS COUNT
// Contest: HackerEarth
// URL: https://www.hackerearth.com/problem/algorithm/substrings-count-3/
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


// Problem: SUBSTRINGS COUNT
// Contest: HackerEarth
// URL: https://www.hackerearth.com/problem/algorithm/substrings-count-3/
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll      long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    500006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
const int mod1 = 999999937;
const int mod2 = 98998919;
const ll MOD = 3e18 + 7;
const int base1 = 293;
const int base2 = 239;
int h2[15], inv2[15], pwr2[15];
int h1[15], inv1[15], pwr1[15];
vector<int> V[MAX];

int add(int a, int b, int mod) {a += b; if(a >= mod) a -= mod; return a;}
int sub(int a, int b, int mod) {a -= b; if( a < 0) a += mod; return a;}
int mul(int a, int b, int mod) {
	return int(a * 1ll * b % mod);
}

int bin_pow(int o, int s, int mod) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2, mod);
    d = (d * 1LL * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}

void precalc(){
    for(int i = 0; i < 15; i++){
        h1[i] = inv1[i] = pwr1[i] = 0;
        h2[i] = inv2[i] = pwr2[i] = 0;
    }
    pwr1[0] = inv1[0] = 1;
    pwr2[0] = inv2[0] = 1;
    int Inv1 = bin_pow(base1, mod1 - 2, mod1);
    int Inv2 = bin_pow(base2, mod2 - 2, mod2);
    for(int i = 1; i <= 11; i++){
        pwr1[i] = mul(pwr1[i - 1], base1, mod1);
        inv1[i] = mul(inv1[i - 1], Inv1, mod1);
        
        pwr2[i] = mul(pwr2[i - 1], base2, mod2);
        inv2[i] = mul(inv2[i - 1], Inv2, mod2);
    }
}

void genhash(string s){
    for(int i = 0; i <= 11; i++){
        h1[i] = h2[i] = 0;
    }
    for(int i = 1; i <= s.size(); i++){
        h1[i] = add(h1[i - 1], mul(pwr1[i], s[i - 1] - 96, mod1), mod1);
        h2[i] = add(h2[i - 1], mul(pwr2[i], s[i - 1] - 96, mod2), mod2);
    }
}

ll gethash(int l, int r){
    int a = sub(h1[r], h1[l - 1], mod1);
    if(a < 0) a += mod1; a = mul(a, inv1[l], mod1);
    int b = sub(h2[r], h2[l - 1], mod2);
    if(b < 0) b += mod2; b = mul(b, inv2[l], mod2);
    ll c = a * 1LL * mod2 + b;
    return c;
}

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 1, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> n;
    precalc();
    unordered_map<ll , ll> M;
    for(int i = 1; i <= n; i++){
        cin >> s;
        genhash(s); unordered_map<ll , ll> mm;
        for(int j = 1; j <= s.size(); j++){
            
            for(int k = j; k <= s.size(); k++){
                ll P = gethash(j, k);
                if(M[P] == 0){
                    M[P] = cnt++;
                }
                if(mm[P])continue;
                mm[P] = 1;
                b = M[P];
                V[b].pb(i);
            }
        }
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> l >> r >> s;
        
        if(s.size() == 0){
            cout << r - l + 1 << endl; continue;
        }
        genhash(s);
        ll P = gethash(1, s.size());
        if(M[P] == 0){
            cout << 0 << endl; continue;
        }
        b = M[P];
        c = lower_bound(V[b].begin(), V[b].end(), l) - V[b].begin();
        d = upper_bound(V[b].begin(), V[b].end(), r) - V[b].begin();
        cout << d - c << endl;
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
