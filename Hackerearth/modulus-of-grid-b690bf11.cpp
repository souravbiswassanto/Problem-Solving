// Problem: Modulus of Grid
// Contest: HackerEarth
// URL: https://www.hackerearth.com/problem/algorithm/modulus-of-grid-b690bf11/
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: Grids & Modulus
// Contest: Newton School - Newton's coding challenge April 2022
// URL: https://my.newtonschool.co/playground/code/0s1u2mbue0x8/
// Memory Limit: 128 MB
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
ll A[MAX], B[MAX], C[MAX], D[MAX];
ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
ll Max = 0, Min = 2e18;
string s, s1, s2;
void pre(){
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            C[j] += A[i]; 
        }
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = i; j <= m; j += i){
            D[j] += B[i]; 
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        A[__gcd((ll)i, n)]++;
    }
    for(int  i = 1; i <= m; i++){
        B[__gcd((ll)i, m)]++;
    }
    pre();
    /*for(int i = 1; i <= n; i++){
        cout << C[i]<<" ";
    }
    cout << endl;
    
    for(int i = 1; i <= m; i++){
        cout << D[i]<<" ";
    }
    cout << endl;*/
    C[n]--; D[m]--;
    cin >> q; 
    while(q--){
        cin >> a >> b >> x >> y;
        p = x - a; if(p <= 0) p += n;
        r = y - b; if(r <= 0) r += m;
        //cout << p <<" " << r << endl;
        cout << C[p] * 1LL * D[r] << endl;
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