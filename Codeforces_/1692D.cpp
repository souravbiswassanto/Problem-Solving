// Problem: D. The Clock
// Contest: Codeforces - Codeforces Round #799 (Div. 4)
// URL: https://codeforces.com/contest/1692/problem/D
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
    
    ll a, b, c, d, n, m,h, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2, s3;

    cin >> t;

    while(t--){
        cin >>  s >> m;
        s1=""; s1 += s[0]; s1 += s[1];
        s2 = ""; s2 += s[3]; s2 += s[4];
        a = stoi(s1);
        b = stoi(s2);
        //cout << a << " "<< b << endl;
        
        h = a * 60 + b;
        s1 = s;
        reverse(s1.begin(), s1.end());
        cntr = 0;
        if(s == s1)cntr=1;
        map<int, int> M;
        M[h] = 1;
        h += m;
        h += 1440;
        while(M[h] != 1){
        	a = h / 60;
        	b = h % 60;
        	M[h] = 1;
        	if(a < 10){
        		s1 = "0";
        		s1  += to_string(a);
        	}
        	else s1 = to_string(a);
        	//cout << a <<" "<< b << endl;
        	if(b < 10){
        		s2 = "0";
        		s2 += to_string(b);
        	}
        	else s2 = to_string(b);
        	
        	s3 = s1; s3 += ':'; s3 += s2;
        	s = s3;
        	reverse(s.begin(), s.end());
        	//cout << s <<"   "<< s3 << endl;
        	if(s == s3)cntr++;
        	h += m;
        	h %= (1440);
        	
        }
        cout << cntr <<  endl;

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
