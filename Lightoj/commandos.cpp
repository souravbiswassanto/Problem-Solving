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
int dist[MAX][5];
int vis[MAX][5];
vector<int> g[MAX];

void bfs(int source, int root){
    vis[source][root] = 1;
    queue<int> Q;
    Q.push(source);
    dist[source][root] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(auto v: g[u]){
            if(vis[v][root])continue;
            vis[v][root] = 1;
            Q.push(v);
            dist[v][root] = dist[u][root] + 1;
        }
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
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        cin >> a >> b;
        bfs(a, 1);
        bfs(b, 2);
        
        Max = 0;
        for(int i = 0; i < n; i++){
            a = dist[i][1] + dist[i][2];
            Max = max(a, Max);
        }
        cout <<"Case "<<++cnt<<": "<< Max << endl;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            vis[i][1] = vis[i][2] = vis[i][3] = 0;
            dist[i][1] = dist[i][2] = dist[i][3] = 0;
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
