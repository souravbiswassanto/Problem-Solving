
// Problem: B. Jumping Gollum
// Contest: CodeMarshal - DUET IUPC 2019
// URL: https://algo.codemarshal.org/contests/duet-iupc-19/problems/B
// Memory Limit: 1500 MB
// Time Limit: 5000 ms
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
int A[MAX], B[MAX], C[MAX];
const int N = 1000002, m = 240;
deque<pair<int, int> > dq[N + 10];
vector<int> factors[N + 1];
vector<int> V;
int dp[MAX];
vector<int>prime;
ll spf[N + 100];
void seive ()
{
    for(int i = 2; i <= N; i++)spf[i] = i;
    int limit = sqrt(N*1.0)+2; spf[1] = 1; spf[2] = 2;
    for (int i = 4; i<= N; i += 2)spf[i]=2;
    prime.push_back(2);
    //i*i <=N kora jave
    for (int i = 3; i <= N; i += 2)
    {
        if(spf[i] == i)
        {
            prime.push_back(i);
            if(i <= limit)
            {
                for (int j = i * i; j <= N; j += i * 2){
                    if(spf[j] == j)spf[j] = i;
                }
            }
        }
    }
    int cntr = 0;
    for(int i = 2; i < N; i++){
        int a = i;
        while(a != 1){
            factors[i].pb(spf[a]);
            a /= spf[a];
            cntr++;
        }
        sort(factors[i].begin(), factors[i].end());
        factors[i].resize(unique(factors[i].begin(), factors[i].end()) - factors[i].begin());
    }
}

int main ()
{
    int test;
    scanf("%d", &test);
    seive();

    for(int cs = 1; cs <= test; cs++){
        int n, k;
        scanf("%d %d", &n, &k);
        
        for(int i = 1; i <= n; i++){
            scanf("%d", &A[i]); dp[i] = INT_MAX;
        }
        dp[0] = -1;
        for(int i = 1; i <= n; i++){
            int curmin = dp[i - 1];
            for(auto v: factors[A[i]]){
                V.pb(v);
                while(!dq[v].empty() and dq[v].back().second < i - k){
                    dq[v].pop_back();
                }
                if(!dq[v].empty()){
                    curmin = min(curmin, dq[v].back().first);
                }
            }
            dp[i] = curmin + 1;
            for(auto v: factors[A[i]]){
                while(!dq[v].empty() and dq[v].front().first >= dp[i]){
                    dq[v].pop_front();
                }
                dq[v].push_front({dp[i], i});
            }
        }
        
        printf("Case %d: %d\n", cs, dp[n]);
        for(int i = 0; i < V.size(); i++){
            while(!dq[V[i]].empty())dq[V[i]].pop_front();
        }
        V.clear();
        
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
