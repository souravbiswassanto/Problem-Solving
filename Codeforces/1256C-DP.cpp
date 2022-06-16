
// Problem: R. Platforms Jumping
// Contest: Codeforces - Week #12 (Difficulty: 1700)
// URL: https://codeforces.com/group/3Yfvg96Ezo/contest/314037/problem/R
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
ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
bool dp[2000][2000];
bool vis[2000][2000];
int Idx[2000][2000];

bool calc(int idx, int M){
    //cout << idx <<" "<< M << endl;
    if(idx > n){
        if(M == m) return 1;
        else return 0;
    }
    if(m == M and idx <= n)return 0;
    bool &ret = dp[idx][M];
    if(vis[idx][M])return ret;
    vis[idx][M] = 1;
    int start = idx + A[M];
    int End = (idx + A[M] - 1) + d;
    //cout << start <<" se "<< End << endl;
    for(int i = start; i <= End; i++){
        ret = calc(i, M + 1);
        if(ret){
            Idx[idx][M] = i; break;
        }
    }
    return ret;
}

int main ()
{
    fastIO();
    
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;
    cin >> n >> m >> d;
    for(int i = 0; i < m; i++){
        cin >> A[i];
    }
    bool ck = false; a = -1;
    for(int i = 1; i <= d; i++){
        ck = calc(i, 0);
        if(ck == 1){
            a = i;
            break;
        }
    }
    if(ck == 0){
        cout << "NO" << endl; return 0;
    }
    //cout << a << endl; a = 0;
    B[a] = ++cnt;
    for(int i = 1; i < m; i++){
        for(int j = a + 1; j <= n; j++){
            if(Idx[j][i] != 0){
                //cout << Idx[j][i] << endl;
                a = j; 
                B[a] = ++cnt; break;
            }
        }
        //cout << a << endl;
    }
    cout << "YES" << endl;
    for(int  i = 1; i <= n;){
        if(B[i]){
            cnt = i;
            a = B[i];
            while(i <= n and A[B[cnt] - 1]--){B[i++] = a; cout << B[i - 1] <<" ";}
        }
        else cout << B[i++] <<" ";
        
    }
    cout << endl;
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
