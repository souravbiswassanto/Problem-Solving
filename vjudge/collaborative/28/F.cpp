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
#define   MAX    100006
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



int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    //ll  b, c, d, n, m, k, l, p, q, r, t, x, y;
    //ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;
	int t=1;
	//cin >> t;
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    
	    ll a[n+7];
	    for(ll i=0;i<n;i++) cin>>a[i];
	    
	    ll id[100007],inv[n+1];
	    mem(id,-1);
	    mem(inv,-1);
	    
	    for(ll i=n-1;i>=0;i--){
	    	for(ll j=1;j*j<=a[i]-k;j++){
	    		
	    		if((a[i]-k)%j==0){
	    			if(j>k && id[j]!=-1){
	    				inv[id[j]]=max(inv[id[j]],i);
	    			}
	    			if(j!=(a[i]-k)/j){
	    				ll x=(a[i]-k)/j;
	    				if(x>k && id[x]!=-1){
	    					inv[id[x]]=max(inv[id[x]],i);
	    				}
	    			}
	    		}
	    	}
	    	id[a[i]]=i;
	    }
	    
	    ll idx=-1;
	    for(ll i=0;i<n;i++){
	    	if(a[i]==k){
	    		idx=i;
	    		continue;
	    	}
	    	if(a[i]>k) inv[i]=max(inv[i],idx);
	    }
	    
	    ll invalid=-1,ans=0;
	    for(ll i=0;i<n;i++){
	    	invalid=max(invalid,inv[i]);
	    	ll d=i-invalid;
	    	ans+=d;
	    	//cout<<i+1<<" "<<d<<endl;
	    }
	    cout<<ans<<endl;
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
