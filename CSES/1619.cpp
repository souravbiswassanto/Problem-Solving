
// Problem: Restaurant Customers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1619
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
struct sourav{
    int type, val;
    sourav(int a, int b){
        type = b;
        val = a;
    }
    bool operator<(sourav other)const{
        if(val == other.val)return type > other.type;
        return val < other.val; 
    }
};
int main(){
    int n, Max = 0, sum = 0;
    cin >> n;
    vector<sourav> vec;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vec.pb(sourav(a, 1));
        vec.pb(sourav(b, -1));
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < 2 * n; i++){
        sum += vec[i].type;
        Max = max(sum, Max);
    }   
    cout << Max << endl; 
    return 0;
}