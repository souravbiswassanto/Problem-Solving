
// Problem: C. Checkposts
// Contest: Codeforces - Codeforces Round #244 (Div. 2)
// URL: https://codeforces.com/contest/427/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define   ll     long long
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

vector<int> adj[MAX], adj_rev[MAX];
vector<bool> used;
vector<int> order, component;
vector<int> roots;
vector<int> root_nodes;
vector<vector<int>> adj_scc(MAX); // Eikhane Max er jaigai n hobe

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(A[v]);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

const int mod = 1000000007;
int add(int a, int b) {a += b; if(a >= mod) a -= mod; return a;}
int sub(int a, int b) {a -= b; if( a < 0) a += mod; return a;}
int mul(int a, int b) {
	return int(a * 1ll * b % mod);
}

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    // ... read n ...
    cin >> n;  
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    
    used.assign(n, false);
    reverse(order.begin(), order.end());
    roots.assign(n, 0);
    
    for (auto v : order){
        if (!used[v]) {
            dfs2 (v); Min = INT_MAX; map<int, int> M;
            // ... processing next component ...
            for(auto com: component){
                Min = min(Min, (ll)com); M[com]++;
            }
            sum+= Min;
            ans = mul(ans, M[Min]);
            component.clear();
        }
    }
    
    cout << sum <<" "<<ans << endl;
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
