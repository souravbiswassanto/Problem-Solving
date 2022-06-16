
// Problem: E. Cover it!
// Contest: Codeforces - Codeforces Round #565 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1176/E
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
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
vector<int> g[MAX];
void bfs(int n){
    int col[n + 5] = {0};
    bool vis[n + 5] = {0};
    queue<int> Q;
    vis[1] = 1;
    Q.push(1); col[1] = 1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(auto v: g[u]){
            if(vis[v])continue;
            vis[v] = 1;
            Q.push(v);
            col[v] = col[u] ^ 1;
        }
    }
    int cntr = 0;
    for(int i = 1; i <= n; i++){
        if(col[i])cntr++;
    }
    if(cntr > (n / 2)){
        cout << n - cntr << endl;
        for(int i = 1; i <= n; i++){
            if(col[i] == 0)cout << i <<" ";
        }
        cout << endl; 
    }
    else{
        cout << cntr << endl;
        for(int i = 1; i <= n; i++){
            if(col[i])cout << i << " ";
        }
        cout << endl;
    }
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
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        
        bfs(n);
        for(int i = 0; i <= n + 2; i++){
            g[i].clear();
        }

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
