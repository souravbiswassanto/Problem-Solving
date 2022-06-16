
// Problem: D. Maximum Product Strikes Back
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.com/contest/1660/problem/D
// Memory Limit: 256 MB
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

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> A[i];
        int twov = 0, negtwo = 0, neg = 0;
        cntr = 0, cnt = n;
        vector<int> zero, minus, two; 
        for(int i = 1; i <= n; i++){
            if(A[i] < 0)minus.pb(i);
            if(A[i] == 0)zero.pb(-i);
            if(A[i] == 2 or A[i] == -2)two.pb(i);
        }
        l = 0; r = 0; zero.pb(0); Max = 0;//minus.pb(INT_MAX); two.pb(INT_MAX);
        sort(minus.begin(), minus.end());
        sort(zero.begin(), zero.end());
        sort(two.begin(), two.end());
        for(int i = 1; i <= n; i++){
            //cout << i << endl;
            if(A[i] == 0)continue;
            int zpos = abs(*lower_bound(zero.begin(), zero.end(), -i));
            int totneg = upper_bound(minus.begin(), minus.end(), i) - lower_bound(minus.begin(), minus.end(), zpos);
            int tottwo = upper_bound(two.begin(), two.end(), i) - lower_bound(two.begin(), two.end(), zpos);
            //cout << zpos <<" "<<totneg<<" "<<tottwo << endl;
            if(totneg % 2){
                zpos = abs(*lower_bound(minus.begin(), minus.end(), zpos));zpos++;
                tottwo = upper_bound(two.begin(), two.end(), i) - lower_bound(two.begin(), two.end(), zpos);
            }
            //cout << zpos <<" "<<totneg<<" "<<tottwo << endl;
            if(tottwo > Max){
                cntr = A[zpos] == 0?zpos: zpos - 1;
                cnt = n - i;
                Max = tottwo;
            }
        }
        cout << cntr <<" "<< cnt << endl;

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
