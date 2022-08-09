// Problem: One Way Roads
// Contest: LightOJ
// URL: https://lightoj.com/problem/one-way-roads
// Memory Limit: 64 MB
// Time Limit: 1000 ms
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
vector<int> g[MAX];
map<pair<int, int>, int> M;

int dfs(int u, int par){
	int sum = 0;
	B[u] = 1;
	for(auto v: g[u]){
		if(B[v]){
			if(v == 1 and par != 1){
				sum = M[{v, u}];
			}
			continue;
		}
		sum += dfs(v, u);
	}
	return sum + M[{u, par}];
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
        cin >>  n;
        M.clear();
        for(int i = 0; i <= n; i++){
        	g[i].clear(); B[i] = 0;
        }
        
        for(int i = 1; i <= n; i++){
        	cin >> a >> b >> c;
        	M[{a, b}] = c;
        	g[a].pb(b);
        	g[b].pb(a);
        }
        for(int i = 1; i <= n; i++){
        	sort(g[i].begin(), g[i].end());
        }
        ans = dfs(1, -1);
        for(int i = 1; i <= n; i++){
        	sort(g[i].rbegin(), g[i].rend());
        	B[i] = 0;
        }
        ans = min(ans, (ll)dfs(1, -1));
        cout <<"Case "<<++cnt<<": "<< ans << endl;
        

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
