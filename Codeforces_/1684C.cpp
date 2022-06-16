
// Problem: C. Column Swapping
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
        vector<int> v[n + 3], sv[n + 3];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a;
                v[i].pb(a);
                sv[i].pb(a);
            }
        }
        for(int i = 0; i < n; i++){
            sort(sv[i].begin(), sv[i].end());
        }
        check = 1;
        for(int i = 0; i < n; i++){
            if(sv[i] != v[i])check = 0;
        }
        if(check){
            cout << 1 <<" "<< 1 << endl; continue;
        }
        
        int col = -1; int row = -1;
        for(int i = 0; i < m; i++){
            check = 0;
            for(int j = 0; j < n; j++){
                if(sv[j][i] != v[j][i]){
                    check = 1;
                    row = j; col = i; break;
                }
            }
            if(check)break;
        }
        
        ans = -1;
        for(int i = m - 1; i > col; i--){
            if(sv[row][col] == v[row][i]){
                ans = i; break;
            }
        }
        //cout << row <<" "<< col <<" "<< ans << endl;
        if(ans == -1){
            cout << -1 << endl; continue;
        }
        
        for(int i = 0; i < n; i++){
            swap(v[i][col], v[i][ans]);
        }
        check = 1;
        for(int i = 0; i < n; i++){
            if(sv[i] != v[i])check = 0;
        }
        if(check){
            cout << col + 1 <<" "<< ans + 1 << endl;
        }
        else cout << -1 << endl;

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
