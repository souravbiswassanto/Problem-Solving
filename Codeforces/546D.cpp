
// Problem: D. Soldier and Number Game
// Contest: Codeforces - Codeforces Round #304 (Div. 2)
// URL: https://codeforces.com/problemset/problem/546/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define   ll     int
#define   pb     push_back
#define   mp     make_pair
#define   MAX    5000006
#define   MAX1   10000008
#define   mem(a,v)   memset(a,v,sizeof(a))
#define   lcm(a, b)        ((a)*((b)/__gcd(a,b)))
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];


vector<ll>prime;
//bool mark[MAX1];
ll N=6e6;
ll spf[6000004];
void seive ()
{
    for(int i = 1; i <= N; i++)spf[i] = i;
    int limit = sqrt(N*1.0)+2; spf[1] = 1; spf[2] = 2;
    for (int i=4; i<=N; i += 2)spf[i]=2;
    prime.push_back(2);
    //i*i <=N kora jave
    for (int i=3; i<=N; i+=2)
    {
        if(spf[i]==i)
        {
            prime.push_back(i);
            if(i<=limit)
            {
                for (int j=i*i; j<=N; j+=i*2){
                    if(spf[j]==j)spf[j] = i;
                }
            }
        }
    }
}


int main ()
{
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;
    seive();
    for(int i = 2; i <= 5000000; i++){
        x = i; cntr = 0;
        while (x != 1){
            cntr++;
            x = x / spf[x];
        }
        A[i] = A[i - 1] + cntr;
    }
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &a, &b);
        printf("%d\n", A[a] - A[b]);

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
