
// Problem: D. Make Them Equal
// Contest: Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1633/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
ll dp[1002][15000];

void pre(){
    B[1] = 0; B[2] = 1; int sum = 0, val;ll maxx = 0;
    for(int i = 3; i <= 1000; i++)B[i] = 9999999;
    for(int i = 1; i <= 1000; i++){
        for(int j = i; j >= 1; j--){
            B[i + i / j] = min(B[i + i / j], B[i] + 1);
        }
    }
}

ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;

ll calc(int idx, int K){
    //cout << idx <<" "<< K << endl;
    if(idx == n){
        if(K >= 0)return 0;
        else return -INT_MAX;
    }
    if(K < 0)return -INT_MAX;
    ll &ret = dp[idx][K];
    if(ret != -1)return ret;
    ret = 0;
    ret = max(ret, calc(idx + 1, K - B[A[idx]]) + C[idx]);
    ret = max(ret, calc(idx + 1, K));
    return ret;
}

int main ()
{
    fastIO(); pre();
    
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> k;
        sum = 0;
        for(int i = 0; i < n; i++){
            cin >> A[i];
            sum += B[A[i]];
        }
        for(int i = 0; i < n; i++){
            cin >> C[i];
        }
        k = min(sum, k);
        for(int i = 0; i < n + 2; i++){
            for(int j = 0; j <= k + 30; j++)dp[i][j] = -1;
        }
        
        cout << calc(0, k) << endl;

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
