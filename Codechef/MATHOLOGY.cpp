
// Problem: Mathology
// Contest: CodeChef - March Lunchtime 2022 dvision 2
// URL: https://www.codechef.com/LTIME106B/problems/MATHOLOGY/
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
#define   ll     int
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
vector<int> dv[100005];
const int N = 100005;
const int bs = 1000;
int blockN[N], cntdb[bs], cntarr[N];

void sievedv(){
    for(int i = 1; i < N; i++){
        blockN[i] = i / bs;
        for(int j = i; j < N; j += i){
            dv[j].pb(i);
        }
    }
    
}

const int blocksize = 720;
struct query{
    int l, r, idx, block;
    query(int a, int b, int c, int d){
        l = a; r = b; idx = c; block = d;
    }
    bool operator <(query other) const {
        
        if(block != other.block) return l < other.l;
        return block % 2? r > other.r : r < other.r;
    }
};

struct MO{
   vector<query> queries;
   vector<int> ans;
   int n, l, r, q;
   MO(int _n, int _q){
      n = _n; l = 0; r = -1; q = _q;
      queries.clear();
      ans.resize(q, 0);
   } 
   void mo(){
       for (int i = 0; i < q; i++){
            while(l > queries[i].l) {
                add(--l);
            }
            while(r < queries[i].r){
                add(++r);
            } 
            while(l < queries[i].l){
                remove(l++);
            }
            while(r > queries[i].r){
                remove(r--);
            } 
            queryAns(queries[i].idx);
            //ans[queries[i].id] = sum;
        }
    }
    void add(int x) { 
        x = A[x];
        for(auto y: dv[x]){
            cntarr[y]++;
            if(cntarr[y] == 2){
                cntdb[blockN[y]]++;
            }
        }
        //sum += a[x]; 
    }
    void remove(int x) {
        x = A[x];
        for(auto y: dv[x]){
            cntarr[y]--;
            if(cntarr[y] == 1){
                cntdb[blockN[y]]--;
            }
        }
        //sum -= a[x];
    }
    int queryAns(int idx){
        int valblock;
        for(int i = bs - 1; i >= 0; i--){
            if(cntdb[i]){
                valblock = i; break;
            }
        }
        for(int i = (valblock + 1) * bs - 1; i >= valblock * bs; i--){
            if(cntarr[i] >= 2){
                ans[idx] = i; break;
            }
        }
    }
    void solve(){
        int a, b;
        for (int i = 0; i < q; i++){
            scanf("%d %d", &a, &b); a--; b--;
            queries.pb(query(a, b, i, a/blocksize));
        }
        sort(queries.begin(), queries.end());
        //for(auto it: queries)cout << it.l<<" "<<it.r <<" "<<it.idx << endl;
        mo();
        for (int i = 0; i < q; i++){
            printf("%d\n", ans[i]);
        }
        mem(cntarr, 0); mem(cntdb, 0);
    }
};

int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    
    ll a, b, c, d, n, m, k, l, p, q, r, t, x, y;
    ll cnt = 0, cntr = 0, sum = 0,ans = 1, check = 0;
    string s, s1, s2;
    
    sievedv();
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i++){
            scanf("%d", &A[i]);
        }
        MO mo_s(n, q);
        mo_s.solve();

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
