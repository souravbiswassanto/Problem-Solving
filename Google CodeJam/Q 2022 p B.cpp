
// Problem: 3D Printing
// Contest: Google Coding Competitions - Qualification Round 2022 - Code Jam 2022
// URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
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
ll A[5][5], B[MAX], C[MAX];

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        for(int i = 0; i < 4; i++){
            B[i] = INT_MAX;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                cin >> A[i][j];
            }
            for(int j = 0; j < 4; j++){
                B[j] = min(B[j], A[i][j]);
            }
        }
        cout <<"Case #"<<++cnt<<": ";
        sum = 0;
        for(int i = 0; i < 4; i++){
            sum += B[i];
        }
        if(sum < 1000000){
            cout<<"IMPOSSIBLE"<<endl; continue;
        }
        m = 1000000; ans = 0;
        for(int j = 0; j < 4; j++){
            if(m > 0){
                a = min(m, B[j]);
                cout << a <<" ";
                m -= a;
                ans += a;
            }
            else cout <<"0 ";
        }
        cout << endl;

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
