
// Problem: Sherlock and Inversions
// Contest: HackerEarth - Data Structures - Advanced Data Structures - Fenwick (Binary Indexed) Trees
// URL: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/sherlock-and-inversions/
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MAX 500006
ll BIT[MAX], A[MAX];

struct FT{
    ll n;
    FT(){}
    void init(ll _n){
        n = _n;
    }
    
    void update(ll x, ll delta){
          for(; x <= n; x += x&-x) BIT[x] += delta;
    }
    ll query(ll x, ll sum = 0LL){
         for(; x > 0; x -= x&-x) sum += BIT[x];
         return sum;
    }
};


// dorkar hoile k = sqrt((n * n)/ q) kora jaite pare.
const ll blocksize = 350;
struct query{
    ll l, r, idx;
    query(ll a, ll b, ll c){
        l = a; r = b; idx = c;
    }
    bool operator <(query other) const {
        ll l1 = l / blocksize; 
        ll l2 = other.l / blocksize;
        if(l1 != l2) return l < other.l;
        return l1 % 2? r > other.r : r < other.r;
    }
};

struct MO{
   vector<query> queries;
   vector<ll> ans;
   ll n, l, r, m; FT ft;ll sum  = 0;
   MO(ll _n, ll _m){
      n = _n; l = 1; r = 0;
      queries.clear(); m = _m;
      ans.resize(m, 0);
      ft.init(n);
   } 
   void mo(){
       
       for (ll i = 0; i < m; i++){
            while(l > queries[i].l) {
                addl(--l);
            }
            while(r < queries[i].r){
                addr(++r);
            } 
            while(l < queries[i].l){
                removel(l++);
            }
            while(r > queries[i].r){
                remover(r--);
            } 
            ans[queries[i].idx] = sum;
            //cout << sum <<" "<<l <<" "<< r << endl;
        }
    }
    void addl(ll x) { 
        ll a = ft.query(A[x] - 1);
        sum += a;
        ft.update(A[x], 1);
        //sum += a[x]; 
    }
    void addr(ll x){
        ll a = ft.query(n) - ft.query(A[x]);
        sum += a;
        ft.update(A[x], 1);
    }
    void removel(ll x) {
        ll a = ft.query(A[x] - 1);
        sum -= a;
        ft.update(A[x], -1);
    }
    void remover(ll x){
        ll a = ft.query(n) - ft.query(A[x]);
        sum -= a;
        ft.update(A[x], -1);
    }
    void solve(){
        ll a, b;
        for (ll i = 0; i < m; i++){
            scanf("%lld %lld", &a, &b);
            queries.pb(query(a,b,i));
        }
        sort(queries.begin(), queries.end());
        mo();
        for(ll i = 0; i < m; i++){
            cout << ans[i] << endl;
        }
        //for (auto it: queries)cout << it.l<<" " << it.r <<" " << it.idx << endl;
    }
};

int main (){
    vector<ll> V;
    ll n, m; 
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        cin >> A[i];
        V.pb(A[i]);
    } 
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for(ll i = 1; i <= n; i++){
        A[i] = lower_bound(V.begin(), V.end(), A[i]) - V.begin() + 1;
    }
    MO mos(n, m);
    mos.solve();
}