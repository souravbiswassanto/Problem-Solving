
// Problem: C. Chat Ban
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/C
// Memory Limit: 512 MB
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

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> x;
        sum = (n * 1LL * (n + 1))/2; ans = sum;
        sum += (n * 1LL * (n - 1))/2;
        if(x >= sum){
            cout << 2 * n - 1 << endl; continue;
        }
        if(ans >= x){
            l = 1; r = n; b = 1;
            while(l <= r){
                m = (l + r)/ 2;
                a = (m * 1LL * (m + 1))/2;
                //cout << m << endl;
                if(x > a){
                    b = m + 1; l = m + 1;
                }
                else{
                    b = m; r = m - 1;
                }
            }
            cout << b << endl;
        }
        else{
            x -= ans;
            l = 1; r = n - 1; b = 1; c = r;
            while(l <= r){
                m = (l + r)/ 2;
                a = (n-m) * 1LL * (c + m); a /= 2;
                //cout << m <<" "<<a<< endl;
                if(x > a){
                    b = m - 1; r = m - 1;
                }
                else{
                    b = m; l = m + 1;
                }
            }
            //cout << b << endl;
            cout << n + (n - b) << endl;
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
