
// Problem: Controlled Inflation
// Contest: Google Coding Competitions - Round 1B 2022 - Code Jam 2022
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000accfdb
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
ll A[1005][1005], B[MAX], C[MAX];
vector<ll> g[1005];
ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
ll Max = 0, Min = 2e18;
string s, s1, s2;
ll dp[1004][2];

ll calc(int idx, int type, ll last){
    if(idx == n)return 0;
    ll &ret = dp[idx][type];
    if(ret != -1)return ret;
    ret = 0;
    ll a, b;
    if(last < C[idx]){
        b = B[idx] - last;
        a = b + B[idx] - C[idx];
    }
    if(last > B[idx]){
        a = last - C[idx];
        b = a + B[idx] - C[idx];
    }
    if(last >= C[idx] and last <= B[idx]){
        a = B[idx] - C[idx]; a += B[idx] - last;
        b = B[idx] - C[idx]; b += last - C[idx];
    }
    ret = min(calc(idx + 1, 1, B[idx]) + b, calc(idx + 1, 2, C[idx]) + a);
    return ret;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    

    cin >> t;

    while(t--){
        cin >> n >> p;
        for(int i = 0; i < n; i++){
            Max = 0; Min = INT_MAX;
            for(int j = 0; j < p; j++){
                cin >> A[i][j];
                Max = max(Max, A[i][j]);
                Min = min(Min, A[i][j]);
            }
            B[i] = Max; 
            C[i] = Min;
        }
        mem(dp, -1);
        ans = calc(0, 1, 0);
        cout <<"Case #"<<++cnt<<": "<<ans << endl;
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
