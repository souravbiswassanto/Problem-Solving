
// Problem: D. Igor In the Museum
// Contest: Codeforces - Educational Codeforces Round 1
// URL: https://codeforces.com/problemset/problem/598/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
ll A[1003][1003], B[1002][1002], C[1002][1002];
map<pair<int, int>, pair<int, int>> M;
map<pair<int, int>, int> res;
int dr[4] = {-1, 0, 1, 0};
int dl[4] = {0, -1, 0, 1};
int counter;
int sx, sy;

void dfs(int x, int y){
    B[x][y] = 1;
    //cout << x <<" "<< y << endl;
    for(int i = 0; i < 4; i++){
        int X, Y;
        X = x + dr[i];
        Y = y + dl[i];
        if(B[X][Y])continue;
        if(A[X][Y] == 0)continue;
        if(A[X][Y] == 2){counter++; continue;}
        M[{X, Y}] = {sx, sy};
        dfs(X, Y);
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

    cin >> n >> m >> q;
    for(int i = 1; i <= n ;i++){
        cin >> s;
        for(int j = 1; j <= m; j++){
            if(s[j - 1] == '.')A[i][j] = 1;
            else A[i][j] = 2;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            counter = 0;
            sx = i; sy = j;
            if(B[i][j] || A[i][j] == 2)continue;
            dfs(i, j);
            C[i][j] = counter;
            M[{i, j}] = {i, j};
        }
    }
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m; j++){
            
            C[i][j] = C[M[{i, j}].first][M[{i, j}].second];
        }
    }
    while(q--){
        cin >> a >> b;
        cout << C[a][b] << endl;
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
