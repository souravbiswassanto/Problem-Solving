
// Problem: D. Distance in Tree
// Contest: Codeforces - VK Cup 2012 Round 1
// URL: https://codeforces.com/problemset/problem/161/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
ll Max = 0, Min = 2e18;
string s, s1, s2;
int mat[50004][503];
int parent[50004];
vector<int> g[50004];

void dfs(int u, int par){
    for(auto v: g[u]){
        if(v == par)continue;
        parent[v] = u;
        dfs(v, u);
        cntr = 1; int cv = v;
        while(cntr <= k and parent[cv] != 0){
            mat[parent[cv]][cntr]++;
            cv = parent[cv]; cntr++;
        }
        
    }
}
void dfs2(int u, int par){
    for(auto v: g[u]){
        if(v == par)continue;
        dfs2(v, u);
    }
    cntr = 1; int cv = u; 
    while(cntr <= k and parent[cv] != 0){
        a = mat[parent[cv]][k - cntr];
        if(cntr != k)a -= mat[cv][k - cntr - 1];
        sum += max(a, 0LL);
        cv = parent[cv]; cntr++;
    }
    sum += mat[u][k];
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    parent[1] = 0;
    for(int i = 1; i <= n; i++){
        mat[i][0] = 1;
    }
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << sum / 2 << endl;
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
