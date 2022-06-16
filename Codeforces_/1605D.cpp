
// Problem: D. Guess the Permutation
// Contest: Codeforces - Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/contest/1589/problem/D
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

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];

int main ()
{
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    scanf("%lld", &t);
    vector<ll> V;
    map<ll, ll> M;
    for(int i = 1; i <= 10000000; i++){
        sum += i;
        if(sum > 1000800000LL)break;
        V.pb(sum);
        M[sum] = i;
    }

    while(t--){
        scanf("%lld", &n);
        printf("? %lld %lld\n", 1LL, n);
        fflush(stdout);
        scanf("%lld", &a);
        for(int i = 0; i < V.size(); i++){
            //cout << V[i] << " "<<a - V[i]<<endl;
            if(binary_search(V.begin(), V.end(), a - V[i])){
                b = M[a - V[i]];
                a = i + 1;
                //cout << a - V[i]<< endl;
                break;
            }
        }
        ll start = 1; ll End = n;
        ll mid; ll res = 0;
        while(start <= End){
            mid = (start + End) / 2;
            printf("? %lld %lld\n", 1LL, mid);
            fflush(stdout);
            scanf("%lld", &ans);
            //cout << ans << endl;
            if(ans == 0){
                res = mid;
                start = mid + 1;
            }
            else End = mid - 1;
        }
        
        if(a < b)swap(a, b);
        printf("? %lld %lld\n", res, res + a);
        fflush(stdout);
//        cout << b << endl;
        scanf("%lld", &c);
        m = (a * (a + 1)) / 2;
        if(m == c){
            printf("! %lld %lld %lld\n", res , res + a + 1, res + a + 1 + b);
        }
        else {
            printf("! %lld %lld %lld\n", res , res + b + 1, res + a + 1 + b);
        }
        fflush(stdout);
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
