
// Problem: LCM Extreme
// Contest: LightOJ
// URL: https://lightoj.com/problem/lcm-extreme
// Memory Limit: 64 MB
// Time Limit: 3000 ms
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
#define   ll     unsigned long long
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
const int N = 3000006;
vector<int> phi(N + 2);
ll phisum[N + 2];
ll cumsum[N + 2];

void phidiv() {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= N; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= N; i++)
        for (int j = 2 * i; j <= N; j += i)
              phi[j] -= phi[i];
}

void divisors(){
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i){
            phisum[j] += (ll)i * phi[i];
        }
    }
}

void precompute(){
    for(ll i = 1; i <= N; i++){
        ll a = ((phisum[i] + 1)) / 2ULL;
        a *= (ll)i;
        cumsum[i] = cumsum[i - 1] + a;
        cumsum[i] -= i;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;
    phidiv();
    divisors();
    precompute();

    while(t--){
        cin >> n;
        ll Ans = cumsum[n];
        cout <<"Case "<<++cnt<<": "<< Ans << endl;

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
