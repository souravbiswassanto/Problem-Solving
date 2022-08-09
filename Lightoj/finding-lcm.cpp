
// Problem: Finding LCM
// Contest: LightOJ
// URL: https://lightoj.com/problem/finding-lcm
// Memory Limit: 64 MB
// Time Limit: 1000 ms
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
ll N = 1e6;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;
    seive();
    cin >> t;

    while(t--){
        cin >> a >> b >> n;
        unordered_map<ll, int> ma, mb, mn; p = a; q = b; r = n;
        vector<ll> v; ans = 1LL;
        for(int i = 0; prime[i] * 1LL * prime[i] <= p; i++){
            if(p % prime[i])continue;
            cntr = 0;
            while(p % prime[i] == 0){
                cntr++; p /= prime[i];
            }
            v.pb(prime[i]);
            ma[prime[i]] = cntr;
        }
        if(p != 1){
            v.pb(p);
            ma[p] = 1;
        } 
        for(int i = 0; prime[i] * 1LL * prime[i] <= q; i++){
            if(q % prime[i])continue;
            cntr = 0;
            while(q % prime[i] == 0){
                cntr++; q /= prime[i];
            }
            v.pb(prime[i]);
            mb[prime[i]] = cntr;
        }
        if(q != 1){
            v.pb(q);
            mb[q] = 1;
        }
        for(int i = 0; prime[i] * 1LL * prime[i] <= r; i++){
            if(r % prime[i])continue;
            cntr = 0;
            while(r % prime[i] == 0){
                cntr++; r /= prime[i];
            }
            v.pb(prime[i]);
            mn[prime[i]] = cntr;
        }
        if(r != 1){
            v.pb(r);
            mn[r] = 1;
        }
        check = 0; 
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        for(int i = 0; i < v.size(); i++){
            a = v[i];
            if(ma[a] > mn[a] or mb[a] > mn[a]){
                check = 1; break;
            }
            if(ma[a] == mn[a])continue;
            if(mb[a] == mn[a])continue;
            //cout << a << endl;
                for(int j = 1; j <= mn[a]; j++){
                    ans *= a;
                }
            
        }s
        if(check) cout <<"Case "<<++cnt<<": impossible" << endl;
        else cout <<"Case "<<++cnt <<": "<< ans << endl;

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
