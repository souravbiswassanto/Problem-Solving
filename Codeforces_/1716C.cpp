// Problem: C. Robot in a Hallway
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
ll A[2][MAX], B[MAX], C[MAX];
ll f[2][MAX], r[MAX];


struct SegmentTree{
	vector<ll> tree;
	vector<ll> arr;
	int n;
	SegmentTree(){}
	SegmentTree(int _n){
	    n = _n;
	    tree.clear();
	    tree.resize(n * 4);
	}
	void init(int _n){
		n = _n;
	    tree.clear();
	    tree.resize(n * 4);
	    arr.resize(n+ 4);
	}
	void build(int node, int tb, int te){
	    if(tb > te) return;
		if(tb == te){
			tree[node]  = arr[tb];//value goes here
			return;
		}
		int mid=(tb + te) >> 1; 
		int left = (node * 2);
		int right = node * 2 + 1;
		build(left, tb, mid);
		build(right, mid + 1, te);
		tree[node] = max(tree[left], tree[right]);
	}
	
	// Range query
	ll query(int node, int tb, int te, int qb, int qe){
        if(tb > te) return 0;
        if(qb > te || qe < tb)return 0;
        if(qb <= tb && te <= qe){
            return tree[node];
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        ll L = query(left, tb, mid, qb, qe);
        ll R = query(right, mid + 1, te, qb, qe);
        return max(L,R);
    }

}; 

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >>  n;
        for(int i = 0; i <= 2 * n + 2; i++){
        	f[0][i]= f[1][i] = 0;
        }
        
        for(int i = 0; i < 2; ++i) {
        	for (int j = 0; j < n; ++j) {
        		cin >> A[i][j]; if(i + j > 0 )A[i][j]++;
        	}
        }
        
        for (int i = 0; i < 2; ++i) {
        	for (int j = 0; j < n; ++j) {
        		f[i][j] = max(0LL, A[i][j] - j - i);
        	}
        	for (int j = 0; j < n; ++j) {
        		f[i][n + n - j - 1] = max(0LL, A[i ^ 1][j] - ((n + n - j) - (i ^ 1)));
        	}
        }
        
        SegmentTree st[2];
        
        st[0].init(2 * n);
        st[1].init(2 * n);
        
        for(int i = 0; i < 2; ++i) {
        	for (int j = 0; j < 2 * n; ++j) {
        		st[i].arr[j] = f[i][j];
        	}
        }
        
        st[0].build(1, 0, 2 * n - 1);
        st[1].build(1, 0, 2 * n - 1);
        int Xor = 1; int N = 2 * n;
        ll Counter = 0; ll tillNow = 0; ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
        	ll val = st[1 - Xor].query(1, 0, N - 1, i, N - i - 1);
        	val -= (tillNow - i - (1 - Xor));
        	ans = min(ans, tillNow + max(0LL, val) + N - i * 2 - 1);
        	tillNow = max(tillNow, max(Counter, A[1 - Xor][i])); 
        	tillNow++; Counter++;
        	ll val1 = st[Xor].query(1, 0, N - 1, i, N - i - 2); 
        	val1 -= (tillNow - i - Xor);
        	ans = min(ans, tillNow + max(0LL, val1) + N - (i + 1) * 2);
        	tillNow = max(tillNow, max(Counter, A[Xor][i]));
        	Counter++; tillNow++; Xor ^= 1;	
        }
        cout << min(tillNow - 1,ans) << endl;
        
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
