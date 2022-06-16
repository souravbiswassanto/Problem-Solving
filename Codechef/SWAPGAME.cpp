
// Problem: Make that Array!
// Contest: CodeChef - CodeChef Starters 13 Division 2 (Rated)
// URL: https://www.codechef.com/START13B/problems/SWAPGAME
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
ll A[MAX];
ll B[MAX];
ll C[MAX];
struct FT{
    int n;
    vector<ll> BIT;
    FT(int _n){
        n = _n;
        BIT.resize(n + 3, 0LL);
    }
    void update(int x, ll delta){
          for(; x <= n; x += x&-x) BIT[x] += delta;
    }
    ll query(int x, ll sum = 0LL){
         for(; x > 0; x -= x&-x) sum += BIT[x];
         return sum;
    }
};
int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n;
        map<int, vector<int>> M;
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            M[A[i]].pb(i);
        }
        for(auto it: M){
            reverse(M[it.first].begin(), M[it.first].end());
            //for(auto i: M[it.first])cout << i <<" "; cout <<endl;
        }
        for(int i = 1; i <= n; i++){
            cin >> B[i];
        }
        FT Sum(n), Count(n);
        for(int i = 1; i <= n; i++){
            Sum.update(i, A[i]);
            Count.update(i, 1);
        }
        ans = 0;
        for(int i = 1; i <= n; i++){
            a = M[B[i]].back();
            M[B[i]].pop_back();
            sum = Sum.query(a-1);
            cnt = Count.query(a - 1);
            //cout << sum <<" "<<cnt << endl;
            b = sum - (cnt * B[i]);
            ans += b;
            Sum.update(a, -B[i]);
            Count.update(a, -1);
            //cout << ans << endl;
        }
        cout << ans << endl;

    }
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
