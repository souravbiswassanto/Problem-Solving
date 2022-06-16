
// Problem: C. National Bomb Defusing Squad
// Contest: CodeMarshal - ACM ICPC Dhaka Regional 2016
// URL: https://algo.codemarshal.org/contests/ICPCDH2016/problems/C
// Memory Limit: 1200 MB
// Time Limit: 8000 ms
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

vector<int> V;
int main(){
    int test;
    int n, q;
    while(1){
        scanf("%d %d", &n, &q);
        if(n == 0 and q == 0)break;
        
       // vector<point> VP;
        int A[ n + 3], B[n + 3];
        int a, b;
        
        for(int i = 1; i <= n; i ++){
            scanf("%d %d", &A[i], &B[i]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                a = abs(A[i] - A[j]);
                b = abs(B[i] - B[j]);
                a = a * a;
                b = b * b;
                //double distance = sqrt(a + b);
                //ll dist = (ll)ceil(distance);
                V.pb(a + b);
            }
            //sort(V[i].begin(), V[i].end());
        }
        sort(V.begin(),V.end());
        int r;
        //for(auto it: V)cout << it<<" "; cout << endl;
        double exval;
        for(int i = 1; i <= q; i++){
            scanf("%d", &r);
            exval = 0.0;
            r = r * r;
            int aa = upper_bound(V.begin(), V.end(), r) - V.begin();
            exval = (double)aa;
            printf("%.2lf\n", exval/(double)n);
        }
        printf("\n");
        V.clear();
    }
    return 0;
}