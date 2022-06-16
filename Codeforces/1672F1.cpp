
// Problem: F1. Array Shuffling
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/F1
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	
template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];
vector<int> g[MAX];

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
        for(int i = 0; i <= n; i++){
            g[i].clear();
            B[i] = 0; C[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            B[A[i]]++;
            g[A[i]].pb(i);
        }
        set<pair<int, int>> S;
        for(int i = 1; i <= n; i++){
            if(!B[i])continue;
            S.insert(mp(-B[i], i));
        }
        //cout << S.size() << endl;
        while(S.size()){
            //cout << n <<" "<< S.size() << endl;
            vector<pair<int, int> > v;
            for(auto it: S){
                //cout << it.first <<" "<< it.second << endl;
                v.pb(it);
            }
            //cout << endl;
            int root = v[0].second; c = root;
            for(int i = 1; i < v.size(); i++){
                a = v[i].second;
                p = g[a].back(); g[a].pop_back();
                C[p] = root;
                //cout << a <<" "<< root << " " << p << endl;
                root = a;
            }
            p = g[c].back(); g[c].pop_back();
            C[p] = v[v.size() - 1].second;
            
            for(int i = 0; i < v.size(); i++){
                a = v[i].first * -1;
                if(a == 1){
                    S.erase(v[i]);
                }
                else{
                    S.erase(v[i]);
                    S.insert(mp(v[i].first + 1, v[i].second));
                }
            }
            
        }
        for(int i = 1; i <= n; i++){
            cout << C[i] <<" ";
        }
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
