// Problem: F. 3SUM
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/F
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
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];

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
        vector<int> v[25];
        for(int i = 1; i <= n; i++){
        	cin >> A[i]; A[i] %= 10;
        	v[A[i]].pb(i);
        }
        for(int i = 0; i < 24; i++){
        	v[i].pb(INT_MAX);
        }
        check = 0;
        for(int i = 1; i <= n; i++){
        	a = 23 - A[i];
        	for(int j = a; j >= 0; j--){
        		b = a - j;
        		l = *lower_bound(v[j].begin(), v[j].end(), -1);
        		r = *upper_bound(v[b].begin(), v[b].end(), i);
        		if(l < i and r != INT_MAX)check = 1;
        	}
        	a = 13 - A[i];
        	
        	for(int j = a; j >= 0; j--){
        		b = a - j;
        		l = *lower_bound(v[j].begin(), v[j].end(), -1);
        		r = *upper_bound(v[b].begin(), v[b].end(), i);
        		if(l < i and r != INT_MAX)check = 1;
        	}
        	a = 3 - A[i];
        	if(a < 0)continue;
        	for(int j = a; j >= 0; j--){
        		b = a - j;
        		l = *lower_bound(v[j].begin(), v[j].end(), -1);
        		r = *upper_bound(v[b].begin(), v[b].end(), i);
        		if(l < i and r != INT_MAX)check = 1;
        	}
        	
        }
        
        if(check)yes;
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

