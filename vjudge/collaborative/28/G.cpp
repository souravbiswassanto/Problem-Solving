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
    int t;
    cin >> t;
    while(t--){
	    ll n,v,ans=0;
	    cin>>n>>v;
	    ll a[n];
	    for(ll i=0;i<n;i++) cin>>a[i];
	    
	    for(ll i=0;i<n;i++){
	    	for(ll j=i;j<n;j++){
	    		ll ok=0;
	    		for(ll k=i;k<=j;k++){
	    			for(ll l=k;l<=j;l++){
	    				if(l==k) continue;
	    				if(a[k]%a[l]==v) ok=1;
	    			}
	    		}
	    		if(!ok) ans++;
	    	}
	    }
	    cout<<ans<<endl;
	}

    return (0 - 0 + 1 -  1 * 1);
}
