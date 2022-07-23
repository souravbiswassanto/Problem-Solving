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


int main ()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    
    ll n,m;
    cin>>n>>m;
    
    string s[n];
    for(ll i=0;i<n;i++) cin>>s[i];
    
    queue<pair<ll,ll>> q;
    q.push({0,0});
    
    pair<ll,ll> vis[n][m];
    memset(vis,-1,sizeof(vis));
    vis[0][0]={0,0};
    
    pair<ll,ll> chk={-1,-1};
    
    while(!q.empty()){
    	pair<ll,ll> u=q.front();
    	q.pop();
    	
    	if(u.first+1<n && s[u.first+1][u.second]!='*' && vis[u.first+1][u.second]==chk){
    		vis[u.first+1][u.second]=u;
    		q.push({u.first+1,u.second});
    	}
    	
    	if(u.first-1>=0 && s[u.first-1][u.second]!='*' && vis[u.first-1][u.second]==chk){
    		vis[u.first-1][u.second]=u;
    		q.push({u.first-1,u.second});
    	}
    	
    	if(u.second+1<m && s[u.first][u.second+1]!='*' && vis[u.first][u.second+1]==chk){
    		vis[u.first][u.second+1]=u;
    		q.push({u.first,u.second+1});
    	}
    	
    	if(u.second-1>=0 && s[u.first][u.second-1]!='*' && vis[u.first][u.second-1]==chk){
    		vis[u.first][u.second-1]=u;
    		q.push({u.first,u.second-1});
    	}
    	//cout<<u.first<<" "<<u.second<<" "<<q.size()<<endl;
    }
    
    ll fx,fy;
    for(ll i=0;i<n;i++){
    	for(ll j=0;j<m;j++){
    		if(s[i][j]=='F'){
    			fx=i,fy=j;
    			break;
    		}
    	}
    }
    
    vector<pair<ll,ll>> path;
    path.pb({fx,fy});
    while(fx || fy){
    	ll temp=fx;
    	fx=vis[fx][fy].first;
    	fy=vis[temp][fy].second;
    	path.pb({fx,fy});
    }
    
    reverse(path.begin(),path.end());
    
    ll slr=0,sud=0,x=0,y=0;
    for(ll i=1;i<path.size();i++){
    	ll px,py;
    	if(path[i].first==path[i-1].first){
    		if(path[i].second>path[i-1].second){
    			if(!slr) cout<<"R"<<endl;
    			else cout<<"L"<<endl;
    			cin>>px>>py;
    		}
    		else{
    			if(!slr) cout<<"L"<<endl;
    			else cout<<"R"<<endl;
    			cin>>px>>py;
    		}
    		px--,py--;
    		if(px==x && py==y){
    			slr=1;
    			i--;
    		}
    		x=px,y=py;
    	}
    	
    	else{
    		if(path[i].first>path[i-1].first){
    			if(!sud) cout<<"D"<<endl;
    			else cout<<"U"<<endl;
    			cin>>px>>py;
    		}
    		else{
    			if(!sud) cout<<"U"<<endl;
    			else cout<<"D"<<endl;
    			cin>>px>>py;
    		}
    		px--,py--;
    		if(px==x && py==y){
    			sud=1;
    			i--;
    		}
    		x=px,y=py;
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
