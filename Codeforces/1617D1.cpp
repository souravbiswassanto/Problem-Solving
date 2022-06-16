
// Problem: D1. Too Many Impostors (easy version)
// Contest: Codeforces - Codeforces Round #761 (Div. 2)
// URL: https://codeforces.com/contest/1617/problem/D1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

template<class T> using oset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key returns the 0 based position of a value
// find_by_order returns a pointer pointing at the kth element 
// also 0 indexed
ll A[MAX], B[MAX], C[MAX];

int main ()
{
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n;
        vector<int> v1, v2;
        for(int i = 1; i <= n - 2; i++){
            cout <<"? "<< i <<" "<< i + 1 <<" "<< i + 2 << endl;
            cin >> a;
            if(a == 1){
                v1.pb(i);
            }
            else v2.pb(i);
        }
        int idx1 , idx2, idx3, id1, id2, id3, cm, im;
        for(int i = 0; i < v1.size(); i++){
            auto it = upper_bound(v2.begin(), v2.end(), v1[i] + 2);
            if(it != v2.end()){
                idx1 = v1[i];
                id1 = *it; break;
            }
            if(abs(v2[0] - v1[i]) >= 3){
                idx1 = v1[i];
                id1 = v2[0]; break;
            }
        }
        idx2 = idx1 + 1; idx3 = idx1 + 2;
        id2 = id1 + 1; id3 = id1 + 2;
        
        cout << "? "<<id2 <<" "<< id3 <<" "<<idx3<<endl;
        cin >> a;
        cout << "? "<< id2 <<" "<< id3<<" "<<idx2<<endl;
        cin >> b;
        if(a or b){
            if(a)cm = idx3;
            else cm = idx2;
            cout << "? "<< cm <<" "<<" "<<id1<<" "<<id2<<endl;
            cin >> c;
            cout <<"? "<< cm <<" "<<" "<<id1<<" "<<id3<<endl;
            cin >> d;
            if(c == 0){
                im = id2;
            }
            else im = id3;
        }
        else{
            im = id3;
            cout << "? "<<im <<" "<< idx3<<" "<<idx2 << endl;
            cin >> c;
            cout << "? "<<im <<" "<< idx2 <<" "<< idx1 << endl;
            cin >> d;
            if(d == 1)cm = idx2;
            else cm = idx3;
        }
        vector<int> V;
        V.pb(im);
        for(int i = 1; i <= n; i++){
            if(i == cm or i == im)continue;
            cout << "? "<<cm <<" "<<im <<" "<<i<<endl;
            cin >> c;
            if(c == 0)V.pb(i);
        }
        cout <<"! "<<V.size()<<" ";
        for(int i = 0; i < V.size(); i++)cout << V[i] <<" "; cout << endl;
        

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
