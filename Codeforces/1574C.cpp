
// Problem: C. Slay the Dragon
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/C
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
ll A[MAX];
ll B[MAX];
ll C[MAX];

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    t = 1;

    while(t--){
        cin >> n;
        vector<ll> V;
        sum = 0;
        for(int i = 0; i < n;i++){
            cin >> a;
            V.pb(a);
            sum += a;
        }
        sort(V.begin(), V.end());
        cin >> m; Min = 2e18;
        for(int i = 0; i < m; i++){
            cin >> a >> b; c = 0;
            auto it = lower_bound(V.begin(), V.end(), a);
            if(it == V.end()){
                it--; c = 0;
                d = sum - *it;
                c = a - *it;
                if(d < b)c += (b - d);
            }
            else if(it == V.begin()){
                d = sum - *it;
                c = 0;
                if(d < b) c = b - d;
            }
            else{
                c = d = 2e18;
                p = sum - *it; it--; q = sum - *it;
                c = max(0LL, b - p);
                d = a - *it;
                if(b > q)d += (b - q);
                c = min(c, d);
                
            }
            cout << c << endl;
            //Min = min(c, Min);
        }

    }
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
