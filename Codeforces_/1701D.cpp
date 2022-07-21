
// Problem: D. Permutation Restoration
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
ll A[MAX], B[MAX], C[MAX];

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n;
        // I had found the idea but didn't knew how to implement
        // Tourist's code helped me to implement it
        // Idea was to generate n range, then take one element from
        // each range and form a permutation
        // Range Concept: 5 / i = 1, this could happen for
        // i = 3, 4, 5. So we will form a range 3 - 5 
        // will do the same for all n input values
        set<pair<int, int>>S;
        vector<int> Lower(n + 1), Upper(n + 1), ans(n + 1);
        vector<pair<int,int>> idx[n + 1]; 
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            if(A[i]){
                Lower[i] = i / (A[i] + 1); // this will give 3 for above example
                Lower[i]++;
                Upper[i] = i / A[i];   // this will give 5 for above ex;
            }
            else{
                Lower[i] = i + 1;
                Upper[i] = n;
            }
            idx[Lower[i]].pb({Upper[i], i}); 
        }
        
        for(int i = 1; i <= n; i++){
            for(auto j: idx[i]){
                S.insert({j.first, j.second});
            }
            if(S.size() == 0)continue;
            ans[S.begin()->second] = i;
            S.erase(S.begin());
        }
        for(int i = 1; i <= n; i++){
            cout << ans[i]<<" ";
        }
        cout <<"\n";

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
