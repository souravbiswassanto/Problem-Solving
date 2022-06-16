
// Problem: E. Weights Distributing
// Contest: Codeforces - Codeforces Round #636 (Div. 3)
// URL: https://codeforces.com/contest/1343/problem/E
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

class bfs{
    public:
    vector<int> level;
    vector<bool> vis;
    int source;
    bfs(int n, int source){
        this->source = source;
        level.resize(n + 2, 0);
        vis.resize(n + 2, 0);
    }
    void BFS(){
        vis[source] = 1;
        queue<int> Q;
        Q.push(source);
        level[source] = 0;
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            for(auto v: g[u]){
                if(vis[v])continue;
                vis[v] = 1;
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
    
};

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
        cin >> n >> m >> a >> b >> c;
        for(int i = 1; i <= m + 4; i++){
            B[i] = 0;
        }
        for(int i = 0; i < m; i++){
            cin >> A[i];
            
        }
        sort(A, A + m);
        for(int i = 1; i <= m; i++){
            B[i] = B[i - 1] + A[i - 1];
        }
        for(int i = 0; i < m; i++){
            cin >> p >> q; 
            g[p].pb(q);
            g[q].pb(p);
        }
        bfs bfsa(n, a); 
        bfs bfsb(n, b);
        bfs bfsc(n, c);
        
        bfsa.BFS();
        bfsb.BFS();
        bfsc.BFS();
        
        ans = 1e18;
        for(int i = 1; i <= n; i++){
            int da = bfsa.level[i];
            int db = bfsb.level[i];
            int dc = bfsc.level[i];
            //cout << da <<" "<< db <<" "<< dc << endl;
            if(da + db + dc > m)continue;
            //if(p - db == da){
                //cout << da + db + dc << " ";
                ans = min(ans, B[da + db + dc] + B[db]);
                //cout << ans << endl;
            //}
        }
        for(int i = 0; i <= n + 2; i++){
            g[i].clear();
        }
        cout << ans << endl;

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
