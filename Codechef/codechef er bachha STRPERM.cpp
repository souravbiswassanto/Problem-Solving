// Problem: Strict Permutation
// Contest: CodeChef - Starters 48 Division 1 (Unrated)
// URL: https://www.codechef.com/START48A/problems/STRPERM
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
ll A[MAX], B[MAX], C[MAX], D[MAX], E[MAX];
ll ans[MAX];
set<ll> Set;
set<ll> S[MAX];

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >>  n >> m; Set.clear();
        for(int i= 0; i <= n; i++){
        	C[i] = INT_MAX;
        	S[i].clear(); ans[i] = 0;
        	D[i] = 0; E[i] = 0;
        	if(i)Set.insert(i);
        }
        for(int i = 1; i <= m; i++){
        	cin >> A[i] >> B[i];
        	C[A[i]] = min(C[A[i]], B[i]);
        }
        for(int i = 1; i <= n; i++){
        	if(C[i] != INT_MAX){
        		S[C[i]].insert(i);
        	}
        }
        for(int i = n; i >= 1; i--){
        	if(S[i].size()){
        		D[i] = *--S[i].end();
        		S[i].erase(D[i]);
        		E[D[i]] = i;
        	}
        	if(S[i].size()){
        		if(S[i - 1].size() < S[i].size()){
        			swap(S[i - 1], S[i]);
        		}
        		for(auto it: S[i])S[i - 1].insert(it);
        		
        	}
        }
        
        for(int i = 1; i <= n; i++){
        	if(!D[i]){
        		ans[i] = *Set.lower_bound(0);
        		D[E[ans[i]]] = 0;
        		Set.erase(ans[i]);
        	}
        	else{
        		ans[i] = D[i];
        		Set.erase(ans[i]);
        	}
        }
        if(S[0].size()){
        	cout << -1 << "\n"; continue;
        }
        for(int i = 1; i <= n; i++){
        	cout << ans[i] <<" ";
        }
        cout << "\n";
        

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
