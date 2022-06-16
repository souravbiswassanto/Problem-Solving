
// Problem: C. Madoka and Childish Pranks
// Contest: Codeforces - Codeforces Round #777 (Div. 2)
// URL: https://codeforces.com/contest/1647/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0); cout.precision(20);}

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
struct sourav{
    int a, b, c, d;
    sourav(int e, int f, int g, int h){
        a = e; b = f; c = g; d = h;
    }
};

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> m; vector<sourav> v;
        int ar[n + 2][m + 2], arr[n + 2][m + 2];
        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0;j < m; j++){
                if(s[j] == '0')arr[i][j] = 0;
                else arr[i][j] = 1;
                ar[i][j] = 0;
            }
        }
        if(arr[0][0]){
            cout << -1 << endl; continue;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 1; j--){
                if(arr[i][j] == ar[i][j])continue;
                if(arr[i][j]){
                    v.pb(sourav(i, j - 1, i , j));
                    ar[i][j - 1] = 0;
                    ar[i][j] = 1;
                }
                else {
                    v.pb(sourav(i, j, i, j));
                    ar[i][j] = arr[i][j];
                }
            }
        }
        for(int i = n - 1; i > 0; i--){
            if(arr[i][0] == ar[i][0])continue;
            if(arr[i][0]){
                v.pb(sourav(i-1, 0, i, 0));
                ar[i][0] = 1;
                ar[i-1][0] = 0;
            }
            else {
                v.pb(sourav(i, 0, i, 0));
                ar[i][0] = arr[i][0];
            }
        }
        cout << v.size() << endl;
        for(int i = 0; i < v.size(); i++){
            cout << v[i].a + 1 <<" "<<v[i].b + 1 <<" "<<v[i].c + 1 <<" "<<v[i].d + 1 << endl;
        }

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
