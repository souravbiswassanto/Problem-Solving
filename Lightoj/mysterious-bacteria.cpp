
// Problem: Mysterious Bacteria
// Contest: LightOJ
// URL: https://lightoj.com/problem/mysterious-bacteria
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
vector<ll>prime;
bool mark[MAX1];
ll N = 100000 + 10;
void seive (){int limit = sqrt(N*1.0)+2;mark[1]=1;for (int i=4;i<=N;i+=2)mark[i]=1;prime.push_back(2);for (int i=3;i<=N;i+=2){if(!mark[i]){prime.push_back(i);if(i<=limit){for (int j=i*i;j<=N;j+=i*2)mark[j]=1;}}}}


int main ()
{
    
    int t, cnt = 0;
    
    seive();
    scanf("%d", &t);

    while(t--){
        ll n;
        scanf("%lld", &n);
        int cntr; bool flag = false;
        if(n < 0){
            flag = true;
        }
        ll m = abs(n); vector<pair<ll, int> > v;
        for(int i = 0; prime[i] * 1LL * prime[i] <= m; i++){
            if(m % prime[i])continue;
            cntr = 0;
            while(m % prime[i] == 0){
                cntr++; m /= prime[i];
            }
            v.pb({prime[i], cntr});
        }
        if(m != 1)v.pb({m, 1});
        
        ll ans = 1;
        for(int i = 2; i <= 40; i++){
            int check = 0;
            for(int j = 0; j < v.size(); j++){
                int a = v[j].second % i;
                if(a){
                    check = 1; break;
                }
                
            }
            if(check == 0)ans = i;
        }
        if(flag)while(ans % 2 != 1)ans /= 2; 
        printf("Case %d: %lld\n",++cnt, ans);

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
