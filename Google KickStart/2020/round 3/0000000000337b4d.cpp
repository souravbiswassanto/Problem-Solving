
// Problem: Candies
// Contest: Google Coding Competitions - Round C 2020 - Kick Start 2020
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
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

ll A[MAX], B[MAX], C[MAX];

struct FT{
    int n;
    vector<ll> BIT;
    vector<int> bitcnt;
    void init(int _n){
        n = _n;
        BIT.clear();
        bitcnt.clear();
        BIT.resize(n + 3, 0);
        bitcnt.resize(n + 3, 0);
    }
    void update1(int x, ll delta, int val){
          for(; x <= n; x += x&-x) {
              BIT[x] += delta;
              bitcnt[x] += val;
          }
    }
    pair<ll, ll> query1(int x, ll sum = 0LL){
         int val = 0;
         for(; x > 0; x -= x&-x) {
             sum += BIT[x]; val += bitcnt[x];
        }
         return {sum, val};
    }
}odd[102], even[102];

int main ()
{
    
    ll a, b, c, d, m, k, p,  t, x, y;
    ll  cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    int test, cnt = 0; scanf("%d", &test);
    
    while(test--){
        int n, q, l, r;
        scanf("%d %d", &n, &q);
        set<int> S[102];
        char type;
        for(int i = 1; i <= 100; i++){
            odd[i].init(n);
            even[i].init(n);
        }
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            if(i & 1){
                odd[A[i]].update1(i, i * A[i], 1);
            }
            else{
                even[A[i]].update1(i, i * A[i], 1);
            }
        }
        sum = 0;
        while(q--){
            scanf(" %c %d %d", &type, &l, &r);
            if(type == 'U'){
                if(l & 1){
                    odd[A[l]].update1(l, -1 * l * A[l], -1); A[l] = r;
                    odd[A[l]].update1(l, l * A[l], 1);
                    
                }
                else{
                    even[A[l]].update1(l, -1 * l * A[l], -1); A[l] = r;
                    even[A[l]].update1(l, l * A[l], 1);
                }
            }
            else{
                ans = 0; ll res = 0;
                for(int i = 1; i <= 100; i++){
                    pair<ll, ll> pr1 = odd[i].query1(r); 
                    pair<ll, ll> pr2 = odd[i].query1(l - 1); 
                    pair<ll, ll> pr3 = even[i].query1(r); 
                    pair<ll, ll> pr4 = even[i].query1(l - 1); 
                    a = pr1.first - pr2.first;
                    a = a - (1LL * i *(l - 1) * (pr1.second - pr2.second));
                    b = pr3.first - pr4.first;
                    b = b - (1LL * i * (l - 1) * (pr3.second - pr4.second));
                    ans += a; res += b;
                    //cout <<a <<" a b "<<b << endl;
                }
                //cout << ans <<" "<< res<<endl;
                sum += (l & 1?1LL: -1LL) * (ans - res);
            }
        }
        printf("Case #%d: %lld\n", ++cnt, sum);

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
