
// Problem: G. Pairs Forming GCD
// Contest: CodeMarshal - ICPC Dhaka Regional Preliminary Contest, 2019 Hosted by Southeast University
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-19-preli/problems/G
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
const int N = 10000010;
int lp[N + 3];
int phi[N + 3];
vector<int> pr;
ll cumsum[N + 3];

void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for(int i = 1; i <= N; i++){
        cumsum[i] = cumsum[i - 1] + phi[i];
        //if(i <= 6)cout << cumsum[i] << endl;
    }
}

int main ()
{
    int t;
    int n;
    calc_sieve();
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++){
        int a, b; ll p;
        scanf("%d %lld", &a, &p);
        int ans = 1;
        int l = 1; int r = a;
        if(cumsum[a] < p){
            printf("Case %d: -1\n", cs); continue;
        }
        while(l <= r){
            int mid = (l + r) / 2;
            int g = a / mid;
            
            if(cumsum[g] >= p){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
            
        }
        printf("Case %d: %d\n", cs, ans);
        
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
