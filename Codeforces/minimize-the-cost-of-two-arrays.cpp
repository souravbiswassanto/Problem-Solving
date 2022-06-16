
// Problem: Minimize the cost of Two Arrays
// Contest: HackerRank - 5th DRMC International Tech Carnival 2022- Programming Contest [Preliminary]
// URL: https://www.hackerrank.com/contests/5th-drmc-international-tech-carnival-2022-programming-contest-preliminary/challenges/minimize-the-cost-of-two-arrays
// Memory Limit: 512 MB
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
ll A[MAX], B[MAX], C[MAX], n;
int dp[101][20003];
bool vis[101][20003];
bool track[101][20003];

int calc(int i, int sum){
    if(i == n){
        return abs(sum);
    }
    int &ret = dp[i][sum];
    if(vis[i][sum])return ret;
    vis[i][sum] = 1;
    int a = calc(i + 1, sum + C[i]);
    int b = calc(i + 1, sum - C[i]);
    if(a <= b){
        ret = a;
        track[i][sum] = 1;
    }
    else{
        ret = b;
        track[i][sum] = 0;
    }
    return ret;
}
void Track(int sum = 0){
    int cntr = 0;
    while(cntr < n){
        int a = track[cntr][sum];
        if(a == 0)swap(A[cntr], B[cntr]);
        if(a == 1)sum += C[cntr];
        else sum -= C[cntr]; cntr++;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        for(int i = 0; i < n; i++){
            cin >> B[i];
        }
       
        for(int i = 0; i < n; i++){
            C[i] = A[i] - B[i];
        }
        mem(vis, 0); mem(track, 0);
        calc(0, 0); Track();
        sum = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                sum += 1LL * (A[i] + A[j]) * (A[i] + A[j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                sum += 1LL * (B[i] + B[j]) * (B[i] + B[j]);
            }
        }
        cout << sum << endl;

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
