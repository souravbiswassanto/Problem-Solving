
// Problem: Banana Bunches
// Contest: Google Coding Competitions - Round G 2021 - Kick Start 2021
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b44ef
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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
#define   ll     int 
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
    ll a, b, c, d, K, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> K;
        for(int i = 0; i <= 20000; i++){
            B[i] = 0; C[i] = INT_MAX;
        }
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            B[i] = B[i - 1] + A[i];
        }
        sum = 0; ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                sum = B[j] - B[i - 1];
                if(sum == K){
                    ans = min(ans, j - i + 1);
                }
            }
        }
        
        for(int i =  1; i <= n; i++){
            a = n - i; a = (a * a);
            cntr  = 0;int D[a + 3];
            for(int j = i + 1; j <= n; j++){
                for(int k = j; k <= n; k++){
                    sum = B[k] - B[j - 1];
                    if(sum >= K)continue;
                    C[sum] = min(C[sum], k - j + 1);
                    D[cntr++] = sum;
                }
            }
            for(int j = 1; j <= i; j++){
                sum = B[i] - B[j - 1];
                if(sum >= K)continue;
                if(C[K- sum] == INT_MAX)continue;
                ans = min(ans, i - j + 1 + C[K - sum]);
            }
            for(int j = 0; j < cntr; j++){
                C[D[j]] = INT_MAX;
            }
        }
        cout <<"Case #"<<++cnt<<": "<<(ans == INT_MAX?-1: ans) << "\n";

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
