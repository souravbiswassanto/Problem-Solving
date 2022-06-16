
// Problem: D. Harmonious Graph
// Contest: Codeforces - Codeforces Round #600 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1253/D
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
ll A[MAX], B[MAX], C[MAX];
int parent[MAX];
vector<int> lst[MAX];

void make_set(int v) {
    lst[v] = vector<int>(1, v);
    parent[v] = v;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap(a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
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

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        make_set(i);
    }
    
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        union_set(a, b);
    }
    for(int i = 1; i <= n; i++){
        if(lst[i].size() == 0)continue;
        sort(lst[i].begin(), lst[i].end());
    }
    for(int i = 1; i <= n; ){
        int cc = parent[i];
        p = lst[cc].size();
        b = lst[cc][p - 1];
        
        while(i < n and b >= i + 1){
            int ncc = parent[i + 1];
            if(ncc != cc){
                d = lst[ncc].size();
                b = max((int)b, (int)lst[ncc][d - 1]);
                union_set(cc, ncc);
                sum++;
                cc = parent[cc];
            }
            i++;
        }
        i++;
    }
    cout << sum << endl;
    
    
    
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
