
// Problem: Merged LIS
// Contest: CodeChef - January Cook-Off 2022 Division 2
// URL: https://www.codechef.com/COOK137B/problems/MERGEDLIS
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
ll D[MAX];

struct segment_tree{
    int n;
    vector<int> tree;
    segment_tree(int _n){
        n = _n;
        tree.clear();
        tree.resize(4 * n, 0);
    }
    void update(int node, int b, int e,int key, int value){
        if(e < key || key < b)return;
        if(b == e){
            tree[node] = value;
            //cout<<tree[node]<<" gg "<<b<<endl;
            return;
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (b + e) >> 1;
        update(left, b, mid, key,value);
        update(right, mid+1, e, key,value);
        tree[node] = max(tree[left],tree[right]);
    }
    int query(int node, int b, int e, int key){
        //cout<<b<<" "<<e<<" "<<node<<" "<<key<<" "<<tree[node]<<endl;
        if(b > key)return 0;
        if(b == e){
            return tree[node];
        }
        if(e<=key) return tree[node];
        int left,right,mid;
        left = (node<<1);
        right = left + 1;
        mid = (b + e) >> 1;
        int L = query(left, b, mid, key);
        int R = query(right, mid+1, e, key);
        return max(L,R);
    }
};


int main ()
{
    fastIO();
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    ll Max = 0, Min = 2e18;
    string s, s1, s2;

    cin >> t;

    while(t--){
        cin >> n >> m;
        vector<int> v, vec;
        for(int i = 0; i < n; i++){
            cin >> a; v.pb(a); A[i] = a;
        }
        for(int i = 0; i < m; i++){
            cin >> a; v.pb(a); B[i] = a;
        }
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        
        Max = 0;
        for(int i = 0; i < n; i++){
            A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
            Max = max(Max, A[i]);
        }
        segment_tree st(Max + 1);
        for(int i = 0; i < n; i++){
            C[A[i]] = max(C[A[i]], (ll)st.query(1, 1, Max, A[i]) + 1);
            st.update(1, 1, Max, A[i], C[A[i]]);
        }
        ll sup_max = Max;
        Max = 0; ll smax = 0;
        for(int i = 0; i < m; i++){
            B[i] = lower_bound(v.begin(), v.end(), B[i]) - v.begin() + 1;
            Max = max(Max, B[i]);
        }
        
        segment_tree st1(Max + 1);
        for(int i = 0; i < m; i++){
            D[B[i]] = max(D[B[i]], (ll)st1.query(1, 1, Max, B[i]) + 1);
            st1.update(1, 1, Max, B[i], D[B[i]]);
        }
        sup_max = max(Max, sup_max); C[sup_max + 1] = 0;D[sup_max + 1] = 0;
        for(int i = sup_max; i >= 1; i--){
            C[i] = max(C[i], C[i + 1]);
        }
        for(int i = sup_max; i >= 1; i--){
            D[i] = max(D[i], D[i + 1]);
        }
    
        cout << C[1] + D[1] << endl;
        
        for(int i = 0; i <= sup_max; i++){
            C[i] = D[i] = 0;
        }

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
