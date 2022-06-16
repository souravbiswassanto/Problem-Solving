
// Problem: Harshikaa and the Rain
// Contest: CodeChef - Exun 2021-22 Division 2 (Rated)
// URL: https://www.codechef.com/EXUN21B/problems/RAINDROPS
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int depth[MAX];
vector<int> g[MAX], V;
void dfs(int source, int par, int dept){
    int check = 0;
    for(auto v: g[source]){
        if(v == par)continue;
        check = 1;
        dfs(v, source, dept + 1);
    }
    if(check == 0){
        V.pb(dept);
    }
}

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            depth[i] = 0; g[i].clear(); B[i] = 0;
        }
        V.clear();
        for(int i = 1; i < n; i++){
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        for(int i = 1; i <= m; i++){
            cin >> A[i];
        }
        if(n == 1){
            cout << A[m] << endl; continue;
        }
        
        dfs(1, 0, 0); V.pb(INT_MAX);
        sort(V.begin(), V.end()); 
        A[0] = 0;
        for(int i = 1; i < V.size(); i++){
            B[i] = V[i - 1] + B[i -1];
            //cout << B[i] <<" ";
        }
        
        sum = 0;
        for(int i = 1; i <= m; i++){
            a = A[i] - A[i - 1];
            b = upper_bound(V.begin(), V.end(), a) - V.begin();
            c = b * a - B[b];
            sum += c;
        }
        cout << sum << endl;
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
