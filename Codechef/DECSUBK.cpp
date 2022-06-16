
// Problem: Non-Decreasing Subsequence of size K
// Contest: CodeChef - SnackDown 2021 - Online Pre-Elimination
// URL: https://www.codechef.com/SNCKPE21/problems/DECSUBK
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
int dp[202][202];
int main ()
{
    fastIO();
    ll a, b, c, d, n, m, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> m; mem(dp, 0);
        for(int i = 0; i <= n; i++){
            B[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            cin >> A[i]; B[A[i]]++;
        }
        vector<int> vec;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(B[j]){
                    a = dp[i - 1][j] + 1; B[j]--;
                    check = 1;
                    for(int k = j; k <= n; k++){
                        if(a + B[k] > m){
                            check = 0; break;
                        }
                    }
                    if(check == 1){
                        vec.pb(j);
                        for(int k = 1; k < j; k++){
                            dp[i][k] = dp[i - 1][k];
                        }
                        dp[i][j] = dp[i - 1][j] + 1;
                        for(int k = j + 1; k <= n; k++){
                            dp[i][k] = max(dp[i - 1][k], dp[i][j]);
                        }
                        
                        break;
                    }
                    B[j]++;
                }
            }
            if(vec.size() != i)break;
        }
        if(vec.size() != n)cout << -1 << endl;
        else{
            for(int i = 0; i < vec.size(); i++)cout << vec[i]<<" ";cout << endl;
        }

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
