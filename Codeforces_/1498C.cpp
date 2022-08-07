
// Problem: C. Planar Reflections
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1498/C
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
const int mod = 1000000007;

int add(int a, int b) {a += b; if(a >= mod) a -= mod; return a;}
int sub(int a, int b) {a -= b; if( a < 0) a += mod; return a;}
int mul(int a, int b) {
	return int(a * 1ll * b % mod);
}

int bin_pow(int o, int s) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2);
    d = (d * 1LL * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}
int dp[2002][2002][3];
int n, m, k;

int calc(int K, int N, int Xor){
    //cout << K <<" "<< N<<" "<<Xor<<endl;
    if(N == 0 or N == n + 1)return 0;
    //cout << 1 << endl;
    int &ret = dp[K][N][Xor];
    //cout << 2<<endl;
    if(ret != -1)return ret;
    //cout <<3 << endl;
    ret = 0;
    if(K != 1){
        ret = add(ret, 1 + calc(K - 1, N + (Xor == 1? -1: 1), 1 ^ Xor));
        ret = add(ret, calc(K, N + (Xor == 0? -1: 1), Xor));
        
    }
    //cout <<4<<endl;
    return ret;
}
int main ()
{
    fastIO();
    ll a, b, c, d, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> k;
        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        ans = calc(k, 1, 1);
        cout << ans + 1 << endl;
        

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
