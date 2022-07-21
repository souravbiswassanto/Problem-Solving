// Problem: Segmentation Fault
// Contest: CodeChef - July Cook-Off 2022 Division 2 (Rated)
// URL: https://www.codechef.com/COOK143B/problems/SEGFAULT
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
ll A[MAX], B[MAX], C[MAX], D[MAX];

bool compare(const pair<int, int>& p, const pair<int, int>& q){
    if(p.first == q.first)return p.second < q.second;
    return p.first < q.first;
}

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
        vector<pair<int, int>> v1, v2;
        for(int i = 1; i <= n; i++){
        	cin >> A[i] >> B[i];
        	v1.pb(mp(A[i], B[i]));
        	v2.pb(mp(B[i], A[i]));
        }
        sort(v1.begin(), v1.end(), compare);
        sort(v2.begin(), v2.end(), compare);
        
        for(int i = 0; i <= n + 2; i++){
        	C[i] = 0; D[i] = 0;
        }
        for(int i = 1; i <= n; i++){
        	a = lower_bound(v2.begin(), v2.end(), mp(i, 0), compare) - v2.begin();
        	C[i] = a;
        }
        for(int i = 1; i <= n; i++){
        	a = lower_bound(v1.begin(), v1.end(), mp(i + 1, 0), compare) - v1.begin();
        	a = n - a;
        	D[i] = a;
        }
        vector<int> res;cntr = 0;
        for(int  i = 1; i <= n; i++){
        	
        	if(C[i] + D[i] == 1){
        		if(A[i] > i or B[i] < i)res.pb(i);
        		
        	}
        }
        cout << res.size() << endl;
        for(int i = 0; i < res.size(); i++){
        	cout << res[i] << endl;
        }

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
