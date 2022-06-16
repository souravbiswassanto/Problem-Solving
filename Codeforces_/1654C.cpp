
// Problem: C. Alice and the Cake
// Contest: Codeforces - Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/C
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
ll A[MAX], B[MAX], C[MAX];
map<ll, ll> M; int gg;

bool solve(ll n){
    if(gg == 0){
        return 0;
    }
    if(n == 1){
        if(M[1]){  
             M[1]--;  return 1;
        }
        else {
            gg = 0; return 0;
        }
    }
    ll a, b; bool res = 1;
    a = n / 2; b = n / 2; if(n % 2)b++;
    if(b % 2)swap(a, b);
    if(M.find(n) == M.end()){
        res &= solve(a);
        res &= solve(b); 
        return res;
    }
    else{
        if(M[n]){
            M[n]--; 
            return 1;
        }
        else{
            res &= solve(a);
            res &= solve(b);
             return res;
        }
    }
}

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;
    loop:
    while(t--){
        cin >> n; gg = 1;
        M.clear(); sum = 0;
        for(int i = 0; i < n; i++){
            cin >> A[i];
            M[A[i]]++;
            sum += A[i];
        }
        ans = sum; map<ll, int> mm;
        while(ans >= 1){
            mm[ans] = 1;
            if(ans % 2){
                a = ans/2; b = ans / 2;
                if(ans % 2)a++;
                if(b % 2)swap(a, b);
                ans = a; mm[b] = 1; mm[a] = 1;
                if(ans == 1)break;
            }
            else{
                ans /= 2;
                mm[ans] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(mm[A[i]] == 0){
                no; goto loop;
            }
        }
        bool res = solve(sum);
        if(res)yes;
        else no;

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
