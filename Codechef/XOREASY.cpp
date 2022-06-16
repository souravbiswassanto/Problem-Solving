
// Problem: Wear the mask
// Contest: CodeChef - Alohomora 
// URL: https://www.codechef.com/ALMR2022/problems/XOREASY
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
ll A[MAX], B[MAX], C[22][22];

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;
    for(int i = 19; i >= 0; i--){
        for(int j = i - 1; j >= 0; j--){
            //C[]
        }
    }

    while(t--){
        cin >> n;cntr = 0;cnt = 0; map<int, int> M;
        for(int i = 1; i <= n; i++){
            cin >> B[i]; 
            for(int j = 0; j <= 19; j++){
                if(B[i] & (1 << j)){
                    B[i] = j + 1; break;
                }
            }
            M[B[i]]++;
        }
        
        for(auto i: M){
            if(i.second % 2 == 1){
                A[++cnt] = i.first;
            }
        }
        n = cnt; A[0] = 0;
        sort(A + 1, A + n + 1);
        for(int i = n; i >= 1; i -= 2){
            //cout << A[i] <<" "<< A[i - 1] << endl;
            cntr += (A[i] - A[i - 1]);
        }
        cout  << cntr << endl;
        /*if(n % 2){
            
            for(int i  = 1; i <= n; i++){
                for(int j = 0; j < 20; j++){
                    if(A[i] & (1 << j)){
                        cntr += (j + 1); break;
                    }
                }    
            }
            cout << cntr << endl;
        }
        else{
            a = 0;
            for(int j = 0; j < 20; j++){
                if(A[1] & (1 << j)){
                    a = j + 1; break;
                }
            }
            //cout << a<< endl;
            for(int i  = 1; i <= n; i++){
                for(int j = 0; j < 20; j++){
                    if(A[i] & (1 << j)){
                        cntr += (j + 1 - a); break;
                    }
                }    
            }
            cout << cntr << endl;
        }*/

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
