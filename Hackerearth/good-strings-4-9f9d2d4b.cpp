// Problem: Good strings
// Contest: HackerEarth - July Circuits '22
// URL: https://www.hackerearth.com/challenges/competitive/july-circuits-22/algorithm/good-strings-4-9f9d2d4b/
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
ll dp[100003][22];
ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
ll Max = 0, Min = 2e18;
const int mod = 1e9 + 7;
string s, s1, s2;

ll calc(int i, int j){
	if (j == k)return 1;
	if (i == n)return 0;
	ll &ret = dp[i][j];
	if (ret != -1) return ret;
	ret = 0;
	if(j == 0 and s[i] != 'a'){
		ret = (calc(i + 1, j + 1) * 1LL * (s[i] - 97)) % mod;
	}
	if(j){
		ret = (calc(i + 1, j + 1) * 1LL * 25) % mod;
	}
	ret = (ret + calc(i + 1, j) % mod) % mod;
	return ret;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    

    cin >> t;

    while(t--){
        cin >>  n >> k;
        cin >> s;
        for (int i = 0; i <= n + 1; ++i) {
        	for (int j = 0; j <= k; ++j) {
        		dp[i][j] = -1;
        	}
        }
        ans = calc(0, 0);
        cout << ans <<"\n";

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
