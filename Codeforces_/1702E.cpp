
// Problem: E. Split Into Two Sets
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define yes   cout<<"YES\n"
#define no   cout<<"NO\n"

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
vector<int> g[MAX];
int vis[MAX], sz[MAX];
int cycle;

int dfs(int source, int par){
    vis[source] = 1;
    sz[source] = 1;
   // cout << source << endl;
    for(auto v: g[source]){
        if(vis[v]){
            cycle = true;
            continue;
        }
        sz[source] += dfs(v, source);
    }
    return sz[source];
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
        for(int i = 0; i <= n; i++){
            B[i] = 0;g[i].clear(); vis[i] = 0; sz[i] = 0;
        }
        check  = 0;
        set<pair<int, int>> S;
        for(int i= 0; i < n; i++){
            cin >> a >> b;
            if(a == b)check = 1;
            B[a]++;
            B[b]++;
            if(a > b)swap(a, b);
            S.insert({a, b});
        }
        for(int i = 1; i <= n; i++){
            if(B[i] >= 3)check = 1;
        }
        if(check){
            no; 
            continue;
        }
        //cout << 1 << endl;
        for(auto it: S){
            g[it.first].pb(it.second);
            g[it.second].pb(it.first);
        }
        //cout << a << endl;
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0){
                cycle = 0;
                //cout << t <<" " << i << endl;
                a = dfs(i, 0);
                if(cycle and a % 2)check = 1;
            }
        }
        if(check)no;
        else yes;

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
