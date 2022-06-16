
// Problem: C. Not Assigning
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/contest/1627/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
ll A[MAX], B[MAX], C[MAX], cntr;
vector<ll> g[MAX];
map<pair<ll, ll>, ll> M;

void dfs(ll source, ll par){
    //cout << source <<" "<< par << endl;
     cntr++;
    for(auto v: g[source]){
        if(v == par)continue;
        //cout << v << endl;
        if(cntr % 2 == 0){
            M[{source, v}] = 2;
            M[{v, source}] = 2;
        }
        else {
            M[{source, v}] = 5;
            M[{v, source}] = 5;
        }
       // cout << 11 << endl;
        dfs(v, source);
    }
}

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0,  sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n; M.clear();
        for(int i = 0; i <= n;i++){
            g[i].clear();
        }
        for(int i = 1; i < n; i++){
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
            A[i] = a; B[i] = b;
        }
        check = 0; int leaf;
        for(int i = 1; i <= n; i++){
            if(g[i].size() > 2){
                check = 1;
            }
            if(g[i].size() == 1){
                leaf = i;
            }
        }
        if(check){
            cout << -1 << endl; continue;
        }
        cntr = 0; //cout << leaf << endl;
        dfs(leaf, 0);
        //cout << M[{1, 3}] << endl;
        for(int i = 1; i < n ;i++){
            cout <<M[{A[i], B[i]}]<<" ";
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
