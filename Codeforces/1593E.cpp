
// Problem: E. Gardener and Tree
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
#define   MAX    400006
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
set<int> G[MAX];
set<pair<int, int>> V;

int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> k;
        for(int i = 1; i < n; i++){
            cin >> a >> b;
            G[a].insert(b);
            G[b].insert(a);
        }
        for(int i = 1; i <= n; i++){
            if(G[i].size() == 0)continue;
            V.insert({G[i].size(), i});
        }
        while(!V.empty() and k > 0){
            auto it = V.begin();
            vector<int> vec;
            while(it != V.end()){
                if(it->first > 1)break;
                vec.pb(it->second);
                it++;
            }
            for(int i = 0; i < vec.size(); i++){
                V.erase({1, vec[i]});
            }
            if(V.empty())break;
            //cout << V.size()<<endl;
            for(int i = 0; i < vec.size(); i++){
                auto it1 = G[vec[i]].begin();
                a = *it1;
                V.erase({G[a].size(),a});
                G[a].erase(vec[i]);
                V.insert({G[a].size(), a});
                
            }
            
            //cout << V.size()<<" down"<<endl;
            //cout << k << endl;
            k--;
            if(V.size() == 1 and k == 0)break;
            if(V.size() == 1 and k != 0)V.clear();
        }
        cout << V.size() << endl;
        for(int i = 0; i <= n; i++){
            G[i].clear();
        }
        V.clear();
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
