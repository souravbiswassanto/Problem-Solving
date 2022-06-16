
// Problem: D. Vertical Paths
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/D
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
int parent[MAX], vis[MAX];
vector<int> g[MAX];

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
        int root;
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            vis[i] = 0; g[i].clear();
        }
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            if(i == A[i])root = i;
            parent[i] = A[i];
            if(i != A[i]){
                g[A[i]].pb(i);
                g[i].pb(A[i]);
            }
        }
        if(n == 1){
            cout << 1 << endl << 1 << endl << 1 << endl; cout << endl; continue;
        }
        vector<vector<int>>res;
        for(int i = 1; i <= n; i++){
            if(vis[i])continue;
            if(g[i].size() > 1)continue;
            if(root == i)continue;
            vis[i] = 1;
            vector<int> v;
            v.pb(i);
            a = parent[i];
            while(vis[a] == 0){
                v.pb(a);
                vis[a] = 1;
                //cout << a <<" "<< parent[a] << endl;
                a = parent[a];
            }
            res.pb(v);
            
        }
        for(int i = 0; i < res.size(); i++){
            reverse(res[i].begin(), res[i].end());
        }
        cout << res.size() << endl;
        for(int i = 0; i < res.size(); i++){
            cout << res[i].size() << endl;
            for(int j = 0; j < res[i].size(); j++){
                cout << res[i][j] <<" ";
            }
            cout << endl;
        }
        cout << endl;
        

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
