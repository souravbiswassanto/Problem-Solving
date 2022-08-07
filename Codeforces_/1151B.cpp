
// Problem: B. Dima and a Bad XOR
// Contest: Codeforces - Codeforces Round #553 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1151/B
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
int dp[503][1028], res[503][1028];
int mat[501][501], n, m;

int calc(int idx, int Xor){
    if(idx == n){
        if(Xor)return 1;
        return 0;
    }
    int &ret = dp[idx][Xor];
    if(ret != -1)return ret;
    ret = 0;
    for(int i = 0; i < m; i++){
        int a = calc(idx + 1, Xor ^ mat[idx][i]);
        if(a)res[idx][Xor] = Xor ^ mat[idx][i];
        ret |= a;
    }
    return ret;
}
void printsol(){
    int Xor = 0;
    for(int i = 0; i < n; i++){
        int a = Xor ^ res[i][Xor];
        Xor = res[i][Xor];
        for(int j = 0; j < m; j++){
            if(a == mat[i][j]){
                cout << j + 1 <<" "; break;
            }
        }
    }
}
int main ()
{
    fastIO();
    ll a, b, c, d, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            cin >> mat[i][j];
        }
    }
    mem(dp, -1);
    ans = calc(0, 0);
    if(ans){
        cout << "TAK"<<endl;
        printsol();
    }
    else cout <<"NIE"<< endl;
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
