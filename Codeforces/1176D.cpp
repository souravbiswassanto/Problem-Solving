
// Problem: D. Recover it!
// Contest: Codeforces - Codeforces Round #565 (Div. 3)
// URL: https://codeforces.com/contest/1176/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
ll A[MAX], B[2750131 + 110], C[MAX];
vector<ll>prime;
//bool mark[MAX1];
ll N=2750131 + 100;
ll spf[2750131 + 110];
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
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    seive();
    cin >> n;
    //cout << prime.size() << endl;
    for(int i = 1; i <= 200000; i++){
        B[prime[i - 1]] = i;
    }
    multiset<int> ms, bs;
    for(int i = 0; i < 2 * n ; i++){
        cin >> A[i + 1]; ms.insert(A[i + 1]);
    }
    sort(A + 1, A + 2 * n + 1);
    vector<int> v;
    while(!ms.empty()){
        int last = *--ms.end();
        if(spf[last] == last){
            bs.insert(last);
            ms.erase(ms.find(last)); 
            continue;
        }
        v.pb(last);
        ms.erase(ms.find(last));
        ms.erase(ms.find(last/spf[last]));
    }
    
    while(!bs.empty()){
        auto it = *--bs.end();
        v.pb(B[it]);
        bs.erase(bs.find(it));
        bs.erase(bs.find(B[it]));
        
    }
    for(auto it: v)cout << it <<" "; cout << endl;
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
