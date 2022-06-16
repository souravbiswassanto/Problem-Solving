
// Problem: Minimizing Coins
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1634
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
int A[106], B[2000006];
int main(){
    int n, x; scanf("%d %d", &n, &x);
    for(int i = 1; i <= n; i++){
        scanf("%d", &A[i - 1]);
    }
    sort(A, A + n);
    B[0] = 0;
    for(int i = 1; i <= x; i++){
        B[i] = INT_MAX;
    }
    for(int i = 0; i <= x; i++){
        if(B[i] == INT_MAX)continue;
        for(int j = 0; j < n; j++){
            B[i + A[j]] = min(B[i + A[j]], B[i] + 1);
            //cout << i + A[j] <<" "<< A[i] + 1 << endl;
        }
        //cout << A[i] << endl;
    }
    if(B[x] == INT_MAX)printf("-1\n");
    else printf("%d\n", B[x]);
    return 0;
}