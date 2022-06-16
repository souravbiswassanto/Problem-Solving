
// Problem: Prefix as a Substring
// Contest: CodeChef - CodeChef Starters 13 Division 2 (Rated)
// URL: https://www.codechef.com/START13B/problems/SSTRPREF
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std ;

#define   Pi     2*acos(0.0)
#define   ll     long long
#define   pb     push_back
#define   mp     make_pair
#define   MAX    1000006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX];
ll B[MAX];
ll C[MAX];

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
	// Range query
	int query(int node, int tb, int te, int qb, int qe){
        if(tb > te) return -INT_MAX;
        if(qb > te || qe < tb)return -INT_MAX;
        if(qb <= tb && te <= qe){
            return tree[node];
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        int L = query(left, tb, mid, qb, qe);
        int R = query(right, mid + 1, te, qb, qe);
        return max(L,R);
    }

}; 

vector<int> z_function(string s, string p)
{
    int m = (int) p.length();
    s = p + '#' + s;
    int n = (int) s.length();
    vector < int > Z(s.size());
    vector<int> new_z;
    Z[0] = 0; // Z[0] = 0 ধরে নিলাম
    for (int i = 1, L = 0, R = 0; i < n; ++i)
    {
        if (i <= R) // i সিগমেন্টের ভিতরে তা প্রথমেই চেক করে নিলাম
            Z[i] = min (R - i + 1, Z[i - L]); // সিগমেন্টে z[i] = z[i-L] থেকে কম বা সমান হতে পারে *শর্ত চেক
        else
            Z[i] = 0; // i সিগমেন্টের অংশ না হলে Z[i] এর মান শুন্য, মানে আমাদের Z[i] এর মান হিসাব করতে হবে।
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) // সিগমেন্টের বাহিরেও যদি অতিরিক্ত ক্যারেক্টার মিলে যায় তাহলে Z[i] এর মান বাড়াবো
            ++Z[i]; // মান বাড়ালাম
        if (i + Z[i] - 1 > R) // নতুন সিগমেন্ট পেলে সিগমেন্ট রেঞ্জ আপডেট করবো ।
            L = i, R = i + Z[i] - 1;
    }
    for(int i = m + 1; i < n; i++)new_z.pb(Z[i]);
    return new_z;
    //Z[0] =  n; প্রবলেমের উপর ভিত্তি করে Z[0]=n হতে পারে
}

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> s >> s1 >> s2;
        n = s.size(); m = s1.size(); k = s2.size();
        for(int i = 0; i < k + 2; i++){
            A[i] = 0;
        }
        auto z1 = z_function(s2, s);
        auto z2 = z_function(s2, s1);
        for(int i = 0; i < k; i++){
            A[i] = i + z2[i];
        }
        SegmentTree st(k);
        st.build(1, 0, k - 1);
        for(int i = 0; i < k; i++){
            int idx = st.query(1, 0, k - 1, i, i + z1[i]);
            //cout << idx << endl;
            sum += max(idx - i, z1[i]);
        }
        cout << sum << endl;
        sum = 0;
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
