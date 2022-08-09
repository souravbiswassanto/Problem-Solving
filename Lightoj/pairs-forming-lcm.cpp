
// Problem: Pairs Forming LCM
// Contest: LightOJ
// URL: https://lightoj.com/problem/pairs-forming-lcm
// Memory Limit: 64 MB
// Time Limit: 2000 ms
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
vector<ll>prime;
bool mark[MAX1];
ll N = 1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}


int main ()
{
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;
    seive();
    cin >> t;
    // Wrong code.  Ac code ache lightoj te.

    while(t--){
        cin >> n;
        vector<pair<ll, int> > v;
        
        m = n;
        for(int i = 0;  i < prime.size() and prime[i] * 1LL * prime[i] <= m; i++){
            if(m % prime[i])continue;
            cntr = 0;
            while(m % prime[i] == 0){
                cntr++; m /= prime[i];
            }
            v.pb({prime[i], cntr});
        }
        if(m != 1){
            v.pb({m, 1});
        }
        cout << "Case "<<++cnt<<": ";
        if(n == 1){
            cout << 1 << endl;
        }
        else if(v.size() == 1){
            cout << v[0].second + 1 << endl;

        }
        else{
            ans = 1LL;
            for(auto it: v){
                ans *= (it.second + 1);
            }
            ll sum = ans;
            for(auto it: v){
                sum += (ans / it.first) - 1;
            }
            
            cout << sum << endl;
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
