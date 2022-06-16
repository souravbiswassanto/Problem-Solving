
// Problem: Traffic Lights
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1163
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
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
ordered set pair
	template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

*/
map<ll, set<pair<int, int> >> M;
oset<int> os;
int main(){
    int n, m;
    cin >> n>> m;
    os.insert(0);
    int A[m + 5];
    for(int i = 0; i < m; i++){
        cin >> A[i];
    }
    os.insert(n);
    oset<int> res;
    res.insert(n);
    for(int i = 0; i < m; i++){
        int pos = os.order_of_key(A[i]);
        auto it = os.find_by_order(pos);
        int l , r = *it; it--;l = *it;
        os.insert(A[i]);
        res.insert(A[i] - l);
        res.insert(r - A[i]);
        pos = res.order_of_key(r - l);
        it = res.find_by_order(pos);
        res.erase(it);
        it = res.end(); it--;
        cout << *it << " ";
    }
    return 0;
}