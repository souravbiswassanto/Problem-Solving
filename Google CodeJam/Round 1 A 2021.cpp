
// Problem: Prime Time
// Contest: Google Coding Competitions - Round 1A 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000043585d/00000000007543d8
// Memory Limit: 1024 MB
// Time Limit: 45000 ms
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

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX], D[MAX];
vector<ll>prime;
bool mark[MAX1];
ll N = sqrt(50000) + 100;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;
    seive();

    while(t--){
        cin >> n;sum = 0; for(int i = 0; i <= 100000; i++)D[i] = C[i] = 0;
        for(int i = 1; i <= n; i++){
            cin >> A[i] >> B[i];
            sum += (A[i] * B[i]);
            D[A[i]] = B[i];
        }
        ans = 0; int res = 0;
        for(int i = sum; i >= 2; i--){
            m = i; vector<int> v; ans = 0;
            for(int j = 0; prime[j] * prime[j] <= m; j++){
                if(m % prime[j])continue;
                while(m % prime[j] == 0){
                    ans += prime[j]; C[prime[j]]++;
                    m /= prime[j];
                }
                v.pb(prime[j]);
            }
            if(m != 1){
                v.pb(m);
                ans += m;
                C[m]++;
            }
            
            check = 0;
            for(int j = 0; j < v.size(); j++){
                if(D[v[j]] == 0 or D[v[j]] < C[v[j]]){
                    //cout << D[v[j]] << " "<<C[v[j]]<<endl;
                    check = 1; C[v[j]] = 0;
                }
                C[v[j]] = 0;
            }
            
            //cout << i <<" "<< ans <<" "<< check << endl;
            if(check)continue;
            if(sum - ans == i){
                res = i; break;
            }
        }
        cout << "Case #"<<++cnt<<": "<< res <<"\n";

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
