
// Problem: Can You Reach The End
// Contest: CodeChef - October Cook-Off 2021 Division 2
// URL: https://www.codechef.com/COOK134B/problems/RECHEND
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
#define   MAX    1000006
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
vector<pair<int, int>>V, VP;
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
        for(int i = 1; i <= n; i++){
            A[i] = 0; B[i] = 0;
        }
        V.clear(); VP.clear();
        for(int i= 0; i < n;i++){
            cin >> a >> b;
            V.pb({a, b});
            VP.pb({n - a + 1, n - b + 1});
        }
        sort(V.begin(), V.end());
        sort(VP.begin(), VP.end());
        check = cnt = 0;
        sum = 0; ans = 0;
       
        cntr = V[0].second;
        ans = V[0].first + V[0].second;
        for(int i = 0; i < cntr; i++){
            sum = V[i].first + V[i].second;
            if(sum != ans){
                cnt = 1; break;
            }
        }
        if(cnt == 0){
            cout<<"NO\n";continue;
        }
        cnt = 0; ans = VP[0].first + VP[0].second;
        cntr = VP[0].second;
        for(int i = 0; i < cntr; i++){
            sum = VP[i].first + VP[i].second;
            if(ans != sum){
                cnt = 1; break;
            }
        }
        if(cnt == 0){
            cout<<"NO\n";continue;
        }
        cout <<"YES\n";

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
