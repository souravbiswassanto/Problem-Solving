
// Problem: Max BIT Sum
// Contest: CodeChef - CodeChef Starters 33 Division 2 (Rated)
// URL: https://www.codechef.com/START33B/problems/MAXBITSUM
// Memory Limit: 256 MB
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

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX];
ll C[50][50][2]; ll D[50]; ll E[50];

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
        cin >> n;
        for(int i = 0; i < 35; i++){
            D[i] = E[i] = 0;
            for(int j = 0; j < 35; j++)C[i][j][1] = C[i][j][0] = 0;
        }
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        for(int i = 0; i < n; i++){
            cin >> B[i];
            for(int j = 0; j < 31; j++){
                if(B[i] & (1<<j))D[j]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 30; j >= 0; j--){
                if(B[i] & (1 << j)){
                    for(int k = 0; k < 31; k++){
                        if(B[i] & (1 << k)){
                            C[j][k][1]++;
                        }
                        else C[j][k][0]++;
                    }
                    break;
                }
            }
        }
        sum = 0;
        for(int i = 0; i < n; i++){
            int idx = -1;
            for(int j = 30; j >= 0; j --){
                if(A[i] & (1 << j)){
                    idx = j; break;
                }
            }
            for(int j = 30; j >= 0; j--){
                a = C[idx][j][1];
                if(A[i] & (1 << j)){
                    sum += (1 << j) * a;
                } 
            }
            
            for(int j = 30; j >= 0; j--){
                if(A[i] & (1 << j)){
                    a = n - D[j] - (idx == -1? 0: C[idx][j][0]);
                    sum += (1 << j) * a;
                }
                else {
                    a = D[j] - (idx == -1? 0: C[idx][j][ 1]);
                    sum += (1 << j) * a;
                }
            }
        }
        cout << sum << endl;

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
