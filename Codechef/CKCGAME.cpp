
// Problem: Chess Kings Chasing Game
// Contest: CodeChef - September Cook-Off 2021 Division 2
// URL: https://www.codechef.com/COOK133B/problems/CKCGAME
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wsign-compare"
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
//void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
int A[320][320];
ll dp[303][303][303];
int MXX[8]={1,1,1,-1,-1,-1,0,0},MYY[8]={1,-1,0,1,-1,0,1,-1};
int n, X, Y;

bool valid(int x, int y, int t){
    if(x <= 0 or y <= 0 or x > n or y > n){
        return 0;
    }
    
    return 1;
}
ll calc(int x, int y, int t){
    int a = max(abs(X-x), abs(Y- y));
    if(t >= a){
        return 0LL;
    }
    ll &ret = dp[x][y][t];
    if(ret != -1)return ret;
    ret = 0;
    for(int i = 0; i < 8; i++){
        int x1 = x + MXX[i];
        int y1 = y + MYY[i];
        if(valid(x1, y1, t + 1)){
            ret = max(ret, calc(x1, y1, t + 1) + A[x1][y1]);
        }
    }
    return ret;
}

int main ()
{
    
    int a, b, c, d, m, k, l, p, q, r, t;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;

    scanf("%d", &t);
    //cout << t << endl;
    while(t--){
        scanf("%d %d %d %d %d", &n, &a, &b, &X, &Y);
        //cin >> n >> a >> b >> X >> Y;
        mem(dp, -1);
        //mem(vis, 0);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                //cin >> A[i][j];
                scanf("%d", &A[i][j]);
            }
        }
        
        ans = calc(a, b, 0);
        printf("%lld\n", ans);
    }
    /* 
        always check the limit and make sure that is correct.
        lcm of first 40 numbers  can be calculated.
        sqrt of 10^9 is 31622.
        always usee 1LL while doing binary operations.
    */

    return (0 - 0 + 1 -  1 * 1);
}
