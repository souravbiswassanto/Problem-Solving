
// Problem: D. Mysterious Present
// Contest: Codeforces - Codeforces Beta Round #4 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/4/D
// Memory Limit: 64 MB
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

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
int dp[MAX], res[MAX];

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> n >> a >> b;
    vector<pair<int, pair<int, int>>> vp;
    for(int i = 0; i < n; i++){
        cin >> c >> d;
        res[i] = i;
        vp.pb({c, {d, i}});
    }
    sort(vp.begin(), vp.end());
    for(int i = 0; i < n; i++){
        c = vp[i].first; d = vp[i].second.first;
        if(c > a and d > b)dp[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(vp[j].first < c and vp[j].second.first < d and dp[j]){
                if(dp[i] < dp[j] + 1){
                    res[vp[i].second.second] = vp[j].second.second;
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(Max < dp[i]){
            Max = dp[i];
            p = vp[i].second.second;
        }
    }
    cout << Max << endl;
    vector<int> v;
    if(Max){
        while(res[p] != p){
            v.pb(p + 1);
            p = res[p];
        }
        v.pb(p + 1);
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] <<" ";
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
