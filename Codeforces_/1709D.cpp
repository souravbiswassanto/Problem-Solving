
// Problem: Rorororobot
// Contest: Codeforces
// URL: https://m1.codeforces.com/contest/1709/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];

struct SegmentTree{
	vector<ll> tree;
	int n;
	SegmentTree(int _n){
	    n = _n;
	    tree.clear();
	    tree.resize(n * 4);
	}
	void build(int node, int tb, int te){
	    if(tb > te) return;
		if(tb == te){
			tree[node]  = A[tb];//value goes here
			return;
		}
		int mid=(tb + te) >> 1; 
		int left = (node * 2);
		int right = node * 2 + 1;
		build(left, tb, mid);
		build(right, mid + 1, te);
		tree[node] = max(tree[left], tree[right]);
	}
	// point update
	void update(int node, int tb, int te,int idx, int newval){
        if(te < idx || idx < tb)return; 
        if(tb == te){
            tree[node] = newval;
            return;
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        update(left, tb, mid, idx, newval);
        update(right, mid + 1, te, idx, newval);
        tree[node] = max(tree[left],tree[right]);
    }
    // range update
    void rupdate(int node, int tb, int te, int qb, int qe){
        if(tb > te) return;
        if(qb > te || qe < tb)return;
        if(qb <= tb && te <= qe){
            tree[node] ^= 1;
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        rupdate(left, tb, mid, qb, qe);
        rupdate(right, mid + 1, te, qb, qe);
        
    }
	// Range query
	ll query(int node, int tb, int te, int qb, int qe){
        if(tb > te) return -INT_MAX;
        if(qb > te || qe < tb)return -INT_MAX;
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
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> A[i];
    }
    SegmentTree st(m);
    st.build(1,1, m);
    cin >> q;
    while(q--){
        cin >> a >> b >> x >> y >> k;
        if(abs(a - x) % k){
            no; continue;
        }
        if(abs(b - y) % k){
            no; continue;
        }
        Max = st.query(1, 1, m, min(b, y), max(b, y));
        
        ll diff = n - a;
        ll val = (diff / k) * k; val += a;
        //cout << q <<" " << Max << endl;
        if(Max >= val)no;
        else yes;
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
