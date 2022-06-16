
// Problem: C. Woodcutters
// Contest: Codeforces - Codeforces Round #303 (Div. 2)
// URL: https://codeforces.com/problemset/problem/545/C
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
int n;
int dp[MAX][3];

int calc(int idx, int step, ll Max){
    if(idx == n )return 0;
    int &ret = dp[idx][step];
    if(ret != -INT_MAX)return ret;
    ret = 0; int a = 0, b = 0, c = 0;
    if(A[idx] > Max and A[idx] + B[idx] < A[idx + 1]){
        a = calc(idx + 1, 2, A[idx] + B[idx]) + 1;
    }
    if(A[idx] - B[idx] > Max){
        b = calc(idx + 1, 1, A[idx]) + 1;
    }
    c = calc(idx + 1, 0, max(A[idx], Max));
    ret = max(max(a, b), c);
    return ret;
    
}

int main ()
{
    fastIO();
    ll a, b, c, d, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i] >> B[i];
    }
    A[n] = INT_MAX;
    for(int i = 0; i < n + 3; i++){
        for(int j= 0; j < 3;j ++)dp[i][j] = -INT_MAX;
    }
    ans = calc(0, 0, -INT_MAX);
    cout << ans << endl;
    
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
