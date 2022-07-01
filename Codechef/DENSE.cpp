// Problem: Dense Bracket Sequence
// Contest: CodeChef - Starters 44 Division 2
// URL: https://www.codechef.com/START44B/problems/DENSE
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
#define   MAX    700006
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
        cin >> s1;
        s = "#";
        for(int j = 0; j < 2 * n + 4; j++){
        	A[j]= 0;B[j] = 0;
        }
        for(int i = 0; i < n; i++){
        	s += s1[i];
        	s += '#';
        }
        A[0] = 0;
        B[0] = 0;
        for(int i = 1; i <= s.size(); i++){
        	if(s[i - 1] == '(')A[i] = A[i - 1] + 1;
        	else A[i] = A[i - 1];
        	if(s[i - 1] == ')'){
        		B[i] = B[i - 1] + 1;
        	}
        	else B[i] = B[i - 1]; 
        }
        m = s.size(); Min = INT_MAX;
        for(int i = 1; i <= s.size(); i++){
        	if(s[i - 1] == '#'){
        		a = B[i];
        		b = A[m] - A[i];
        		c = max(A[i], B[m] - B[i]) - min(A[i], B[m] - B[i]);
        		Min = min(Min , a + b + c);
        	}
        }
        cout << Min <<"\n";
        

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
