
// Problem: Digit Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2431
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
using namespace std;
using namespace __gnu_pbds;

#define   ll long long
#define   MAX 500006
#define   pb     push_back
#define   mp     make_pair
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   all(x) x.begin(),x.end()
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))

vector<ll>prime;
bool mark[10000007];
ll N=1e7;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
ordered set pair
	template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

*/

int main(){
    int test;
    ll ans = 1LL;
    vector<ll> V;
    for(int i = 0; i <= 18; i++){
        V.pb(ans);
        ans *= 10LL;
    }
    scanf("%d", &test);
    for(int cs = 1; cs <= test; cs++){
        ll n;
        cin >> n;
        if(n <= 9){
            cout << n << endl;continue;
        }
        int cntr = 1;
        ll last = 1LL, tot = 0LL;
        for(int i = 1; i <= 18; i++){
            ll gap = V[i] - V[i - 1];
            if(tot + (1LL * gap * i) >= n) break;
            tot += (1LL * gap * i);
            last = V[i];
            cntr++;
        }
        last--;
        ll baki = n - tot;
        ll div = baki / cntr;
        ll rem = baki % cntr;
        last += div;
        //cout << last <<" "<< div <<" "<<rem<< endl;
        if(rem == 0){
            cout << last % 10LL << endl;
        }
        else {
            last++;
            string s = to_string(last);
            cout << s[rem - 1] << endl;
        }
        
    }
    return 0;
}