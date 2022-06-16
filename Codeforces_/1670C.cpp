
// Problem: C. Where is the Pizza?
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int mod = 1000000007;

int add(int a, int b) {a += b; if(a >= mod) a -= mod; return a;}
int sub(int a, int b) {a -= b; if( a < 0) a += mod; return a;}
int mul(int a, int b) {
	return int(a * 1ll * b % mod);
}

int bin_pow(int o, int s) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2);
    d = (d * 1LL * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}
vector<int> g[MAX];
int vis[MAX];
map<int, int> M;
bool dfs(int source){
    vis[source] = 1;
    bool res = 1 - M[source];
    //cout << res <<" "<< M[source]<<" "<< source << endl;
    for(auto v: g[source]){
        if(vis[v])continue;
        res &= dfs(v);
    }
    //cout << res << endl;
    return res;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n; 
        for(int i = 1; i <= n; i++){
            cin >> A[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> B[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> C[i];
            M[C[i]] = 1;
        }
        for(int i = 1; i <= n; i++){
            if(A[i] != B[i])g[A[i]].pb(B[i]);
        }
        ll cycle = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i])continue;
            if(g[i].size() == 0)continue;
            cycle += dfs(i);
        }
        ans = 1LL;
        for(int i = 1; i <= cycle; i++){
            ans = mul(ans, 2LL);
        }
        cout << ans <<"\n";
        for(int i = 0; i <= n; i++){
            vis[i] = 0; g[i].clear();
            
        }
        M.clear();
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
