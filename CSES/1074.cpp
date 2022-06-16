
// Problem: Stick Lengths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1074
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
void seive (){ll limit = sqrt(N*1.0)+2;mark[1]=1;for (ll i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (ll i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (ll j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
ordered set pair
	template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>new_data_set;

*/

int main(){
    ll n;
    cin >> n;
    ll A[n + 3];
    for(ll i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A, A + n);
    ll med ,sum = 0, sum1 = 0;
    if(n % 2){
        med = A[n/2];
        for(ll i = 0; i < n; i++)sum += abs(med - A[i]);
    }
    else {
        med = (A[n/2] + A[n/2-1]) / 2;
        for(ll i = 0; i < n; i++)sum += abs(med - A[i]);med++;
        for(ll i = 0; i < n; i++)sum1 += abs(med - A[i]);
        sum = min(sum, sum1);
    }
    cout << sum ;
    return 0;
}