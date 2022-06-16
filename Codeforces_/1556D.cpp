
// Problem: D. Take a Guess
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int Or[100001], And[100001];
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    for(int i = 2; i <= n; i++){
        printf("or 1 %d\n", i);
        fflush(stdout);
        int OR ;
        scanf("%d", &OR);
        Or[i] = OR;
        printf("and 1 %d\n", i);
        fflush(stdout);
        int AND;
        scanf("%d", &AND);
        And[i] = AND;
    }
    int a = 0;
    int bor, band;
    //printf("or 2 3\n");
    //fflush(stdout);
    //scanf("%d", &bor);
    printf("and 2 3\n");
    fflush(stdout);
    scanf("%d", &band);
    int cntr;
    for(int i = 0; i <= 30; i++){
        for(int j = 2; j <= n; j++){
            if(And[j] & (1 << i)){
                a += (1 << i);
                break;
            }
        }
    }
    for(int i = 0; i <= 30; i++){
        cntr = 0;
        for(int j = 2; j <= n; j++){
            if((a & (1 << i))){
                break;
            }
            if(Or[j] & (1 << i))cntr++;
        }
        if(cntr == n - 1){
            bool ok, kk;
            ok = band & (1 << i);
            if(!ok)a += (1 << i);
        }
    }
    vector<int> ans;
    ans.pb(a);
    for(int i = 2; i <= n; i++){
        int b = 0;
        for(int j = 0; j <= 30; j++){
            if(And[i] & (1 << j)){
                b += (1 << j);
            }
            else{
                if((Or[i] & (1 << j)) and (!(a & (1 <<j)))) b += (1 << j);
            }
        }
        ans.pb(b);
    }
    sort(ans.begin(), ans.end());
    int res;
    for(int i = 0; i < k ; i++){
        res = ans[i];
    }
    printf("finish %d\n", res);
    fflush(stdout);
    
    return 0;
}