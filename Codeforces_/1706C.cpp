// Problem: C. Qpwoeirut And The City
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
ll oddL[MAX], oddR[MAX], evenL[MAX], evenR[MAX];

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
        cin >>  n;
        for(int i = 0; i <= n + 5; i++){
        	oddL[i] = oddR[i] = evenL[i] = evenR[i] = INT_MAX;
        }
        for(int i = 1; i <= n; i++){
        	cin >> A[i];
        }
        cntr = 0; Min = 1e18;
        if(n % 2){
        	cntr = 0;
        	for(int i = 2; i < n; i += 2){
        		if(A[i] > A[i - 1] and A[i] > A[i + 1])continue;
        		cntr += (max(A[i - 1], A[i + 1]) - A[i]) + 1;
            }
            Min = cntr; cntr = 0;
            for(int i = n - 1; i > 1; i -= 2){
            	if(A[i] > A[i - 1] and A[i] > A[i + 1])continue;
        		cntr += (max(A[i - 1], A[i + 1]) - A[i]) + 1;
            }
            Min = min(Min, cntr);
        }
        else{
        	evenL[0] = 0; oddL[1] = 0; evenR[n] = 0; oddR[n + 1] = 0;
        	for(int i = 2; i < n - 1; i += 2){
        		if(A[i] > A[i - 1] and A[i] > A[i + 1]){
        			evenL[i] = evenL[i - 2];
        		}
        		else{
        			evenL[i] = evenL[i - 2] + (max(A[i - 1], A[i + 1]) - A[i]) + 1;
        		}
            }
            
            for(int i = n - 2; i > 1; i -= 2){
            	if(A[i] > A[i - 1] and A[i] > A[i + 1]){
            		evenR[i] = evenR[i + 2];
            	}
            	else{
            		evenR[i] = evenR[i + 2] + (max(A[i - 1], A[i + 1]) - A[i]) + 1;
            	}
            }
            
            for(int i = 3; i < n; i += 2){
        		if(A[i] > A[i - 1] and A[i] > A[i + 1]){
        			oddL[i] = oddL[i - 2];
        		}
        		else{
        			oddL[i] = oddL[i - 2] + (max(A[i - 1], A[i + 1]) - A[i]) + 1;
        		}
        		
            }
            
            for(int i = n - 1; i > 1; i -= 2){
            	if(A[i] > A[i - 1] and A[i] > A[i + 1]){
            		oddR[i] = oddR[i + 2];
            	}
            	else{
            		oddR[i] = oddR[i + 2] + (max(A[i - 1], A[i + 1]) - A[i]) + 1;
            	}
            }
            Min = min(Min, evenL[n - 2]);
            Min = min(Min, oddL[n - 1]);
            Min = min(Min, evenR[2]);
            Min = min(Min, oddR[3]);
            
            for(int i = 2; i < n; i++){
            	if(i % 2 == 0)Min = min(Min, evenL[i] + oddR[i + 3]);
            }
            for(int i = n - 1; i >= 2; i--){
            	if(i % 2 == 1)Min = min(Min, oddR[i] + evenL[i - 3]);
            }
        }
        cout << Min << endl;

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
