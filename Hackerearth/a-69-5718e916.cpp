// Problem: Light Up the Bulbs
// Contest: HackerEarth - July Circuits '22
// URL: https://www.hackerearth.com/challenges/competitive/july-circuits-22/algorithm/a-69-5718e916/
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
ll cntr = 0;
ll parent[MAX];

ll getroot(ll v){
	if(v == parent[v])return v;
	else return parent[v] = getroot(parent[v]);
}

bool attach(ll u, ll v){
	int a = getroot(u);
	int b = getroot(v);
	if(a != b){
		cntr--;
		if(rng() % 2)parent[b] = a;
		else parent[a] = b;
		return true;
	}
	return false;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> n;
    vector<pair<ll, pair<ll, ll>>> v;
    for(int i = 0; i < n; i++){
    	cin >> A[i] >> B[i];
    	parent[i + 1] = i + 1;
    }
    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		v.pb({abs(A[i] - A[j]) * abs(A[i] - A[j])+ abs(B[i] - B[j]) * abs(B[i] - B[j]), {i + 1, j + 1}});
    	}
    }
    sort(v.begin(), v.end()); cntr = n;
    for(int i = 0; i < v.size(); i++){
    	a = v[i].first;
    	b = v[i].second.first;
    	c = v[i].second.second;
    	
    	if(attach(b, c))sum += a;
    	if(cntr == 1)break;
    }
    cout << sum << endl;
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
