
// Problem: H. Boundary
// Contest: Codeforces - SWERC 2021-2022 - Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1662/problem/H
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

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n,w, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> w >> l;
        q = w + (l - 2LL); q += q;
        r = min(w, l);
        vector<ll> res;vector<ll> v;
        for(ll i = 1; i * 1LL * i <= q; i++){
            if(q % i)continue;
            v.pb(i);
            if(i * 1LL * i != q)v.pb(q / i);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            a = w; b = l - 2;
            c = w - 2; d = l;
            if(a % v[i] == 0 and b % v[i] == 0){
                res.pb(v[i]);
            }
            else if(c % v[i] == 0 and d % v[i] == 0){
                res.pb(v[i]);
            }
            else if(w % v[i] == 1 and l % v[i] == 1){
                res.pb(v[i]);
            }
            else if(w % v[i] == 1 and l % v[i] == 0 and (l - 2) % v[i] == 0){
                res.pb(v[i]);
            }
            else if(l % v[i] == 1 and w % v[i] == 0 and (w - 2) % v[i] == 0){
                res.pb(v[i]);
            }
        }
        
        sort(res.begin(), res.end());
        //res.resize(unique(res.begin(), res.end()) - res.begin());
        cout << res.size() << " ";
        for(int i = 0; i < res.size(); i++){
            cout << res[i] <<" ";
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
