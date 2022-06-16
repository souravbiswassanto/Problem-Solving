
// Problem: C. Xenia and Weights
// Contest: Codeforces - Codeforces Round #197 (Div. 2)
// URL: https://codeforces.com/problemset/problem/339/C
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
string s, s1, s2;
bool dp[2003][50][11];
bool vis[2003][50][11];
vector<int> v;
int n;
bool chk;

bool calc(int i , int flag, int sum, int ans, int last){
    if(chk)return 1;
    if(i == n){
        if((flag == 0 and sum > ans) or(flag == 1 and ans > sum)){
            yes;
            for(int j = 0; j < v.size(); j++){
                cout << v[j] <<" ";
            }
            cout << endl;
            chk = 1;
            return 1;
        }
        return 0;
    }
    int a = sum - ans;
    if(i != 0 and ((flag == 0 and sum <= ans) or (flag == 1 and ans <= sum))){
        return 0;
    }
    bool& ret = dp[i][a][last];
    if(vis[i][a][last])return ret;
    vis[i][a][last] = 1;
    ret = false;
    for(int j = 0; j <= 9; j++){
        if(s[j] == '0' or (j + 1 == last))continue;
        int c = sum + (flag? j + 1: 0);
        int d = ans + (!flag? j + 1: 0);
        v.pb(j + 1);
        ret |= calc(i + 1, flag ^ 1, c, d, j + 1);
        v.pop_back();
    }
    
    return ret;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    

    cin >> s;
    cin >> n;
    mem(dp, 0);
    mem(vis, 0);
    calc(0, 1, 0, 0, 0);
    if(!chk)no;
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
