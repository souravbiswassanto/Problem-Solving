
// Problem: F. Red-Black Number
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/F
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
ll n, a, b;
string s;
struct print{
    int idx, j, rem1, rem2;
    print(){
        idx = INT_MAX;
    }
    print(int id, int i, int r, int r1){
        idx = id;
        j = i;
        rem1 = r;
        rem2 = r1;
    }
    
};
int path[42][42][42][42];
int dp[42][42][42][42];

int calc(int idx, int j, int rem1, int rem2){
    if(idx == n){
        if((rem1 == 0 and rem2 == 0) and (j != n and j != 0)){
            return abs((n - j) - j);
        }
        else return 1000000;
    }
    int &ret = dp[idx][j][rem1][rem2];
    if(ret != -1)return ret;
    ret = 1000000;
    int c = calc(idx + 1, j + 1, (rem1 * 10 + s[idx] - '0') % a, rem2);
    int d = calc(idx + 1, j, rem1, (rem2 * 10 + s[idx] - '0') % b);
    if(c < d){
        path[idx][j][rem1][rem2] = j + 1;
    }
    else {
        path[idx][j][rem1][rem2] = j;

    }
    
    ret = min(c, d);
    return ret;
}

void printpath(int idx, int j, int rem1, int rem2){
    int c = path[idx][j][rem1][rem2];
    if(idx == n)return;
    if(c ==  j + 1){
        cout <<'R';
        printpath(idx + 1, j + 1, (rem1 * 10 + s[idx] - '0') % a, rem2);
    }
    else {
        cout <<'B';
        printpath(idx + 1, j,rem1, (rem2 * 10 + s[idx] - '0') % b);

    }
}

int main ()
{
    fastIO();
    ll  c, d, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string  s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> a >> b;
        cin >> s;
        mem(dp, -1);
        //cout << s << endl;
        ans = calc(0, 0, 0, 0);
        //cout << ans << endl;
        if(ans == 1000000){
            cout << -1 << endl;continue;
        }
        printpath(0, 0, 0, 0);
        cout << endl;
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
