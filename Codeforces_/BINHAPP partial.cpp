
// Problem: Binary String Happiness
// Contest: CodeChef - July Lunchtime 2022 Division 1 (Rated)
// URL: https://www.codechef.com/LTIME110A/problems/BINHAPP
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
#define   MAX    1000006
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
ll tot[MAX], Left[MAX], Right[MAX], len[MAX], md[MAX];
ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
ll Max = 0, Min = 2e18;
string s[MAX], s1, s2;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    

    
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> len[i];
        cin >> s[i];
        cntr = 0; Max = 0; check = 0; cnt = 0; ll mn = INT_MAX, mx  = 0;
        for(int j = 0; j < len[i]; j++){
            if(s[i][j] == '1'){
                cntr++; check = 1;
            }
            else cntr--;
            Max = max(Max, cntr);
            mn = min(cntr, mn);
            mx = max(mx, cntr - mn);
        }
        md[i] = mx;
        tot[i] = cntr;
        Left[i] = Max - max(0LL, cntr);
        cntr = 0; Max = 0; mn = INT_MAX; mx = 0;
        for(int j = len[i] - 1; j >= 0; j--){
            if(s[i][j] == '1')cntr++;
            else cntr--;
            Max = max(Max, cntr);
            mn = min(cntr, mn);
            mx = max(mx, cntr - mn);
        }
        md[i] = max(md[i], mx);
        Right[i] = Max - max(0LL, cntr);
    }
    for(int i = 1; i <= q; i++){
        cin >> l >> r; ans = 0;
        sum = 0; int id1 = -1, id2 = -2;
        int mx1 = 0, mx3 = 0; int mx2 = 0, mx4 = 0;
        for(int j = l; j <= r; j++){
            if(tot[j] > 0)sum += tot[j];
            if(Left[j] >= mx1){
                mx3 = mx1;
                mx1 = Left[j];
                id1 = j;
            }
            else if(Left[j] > mx3)mx3 = Left[j];
            if(Right[j] >= mx2){
                mx4 = mx2;
                mx2 = Right[j];
                id2 = j;
            }
            else if(Right[j] > mx4)mx4 = Right[j];
            ans = max(ans, md[j]);
        }
        ans = max(ans, sum);
        if(id1 == id2){
            sum += max(mx1 + mx4, mx2 + mx3);
        }
        else sum += mx1 + mx2;
        cout << max(sum, ans) << endl;
        
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
