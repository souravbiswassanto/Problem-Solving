// Problem: D. Water Tree
// Contest: Codeforces - Codeforces Round #200 (Div. 1)
// URL: https://codeforces.com/problemset/problem/343/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
using namespace std;
#define MAX 500106
#define ll long long
#define pb push_back
#define mem(a,v) memset(a,v,sizeof(a))

ll n, m, all, cnt = 1;
vector<ll> g[MAX], nxt, csz;
vector<ll> tree, mx;
ll val[MAX], A[MAX]; 
ll Size[MAX], p[MAX], chain[MAX];
ll base[MAX], top[MAX], depth[MAX];
ll waterat[MAX];
// chain array stores the chain number of a node v 

struct SegmentTree{
    vector<ll> tree,rmqtree;
	vector<ll> lazy;
    void init(ll n){
        tree.clear(); tree.resize(4 * n,0);
        rmqtree.resize(4 * n, 0);
        mx.clear(); mx.resize(4 * n, 0);
        lazy.clear(); lazy.resize(n * 4, 0);
    }
     //** Segment TREE PART STARTED**//
     void build(ll node, ll tb, ll te){
	    if(tb > te) return;
		if(tb == te){
			rmqtree[node]  = val[base[tb]];//value goes here
			return;
		}
		ll mid=(tb + te) >> 1; 
		ll left = (node * 2);
		ll right = node * 2 + 1;
		build(left, tb, mid);
		build(right, mid + 1, te);
		rmqtree[node] = rmqtree[left] + rmqtree[right];
	}
     
     void rmqupdate(ll node, ll tb, ll te,ll idx, ll newval){
        if(te < idx || idx < tb)return; 
        if(tb == te){
            rmqtree[node] = newval;
            return;
        }
        ll left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        rmqupdate(left, tb, mid, idx, newval);
        rmqupdate(right, mid + 1, te, idx, newval);
        rmqtree[node] = rmqtree[left] + rmqtree[right];
    }
    
    ll rmqquery(ll node, ll tb, ll te, ll qb, ll qe){
        if(tb > te) return 0;
        if(qb > te || qe < tb)return 0;
        if(qb <= tb && te <= qe){
            return rmqtree[node];
        }
        ll left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        ll L = rmqquery(left, tb, mid, qb, qe);
        ll R = rmqquery(right, mid + 1, te, qb, qe);
        return L + R;
    }
     
    
    //** Segment TREE PART ENDED**//
} st;
struct HLD{
    ll n, m;
    void init(ll _n, ll _m){
        n = _n;
        m = _m;
        for(ll i = 0; i <= n; i++)g[i].clear();
        nxt.clear(); nxt.resize(n + 1,  -1);
        csz.clear(); csz.resize(n + 1, 0); cnt = 1; all = 0;
    }
    
    //** HLD PART STARTED**///
    void dfs(ll source, ll pr = 0){
        p[source] = pr;
        Size[source] = 1;
        for(auto to: g[source]){
            if(to == pr)continue;
            depth[to] = depth[source] + 1;
            dfs(to, source);
            Size[source] += Size[to];
            if(nxt[source] == -1 || Size[to] > Size[nxt[source]]){
              nxt[source] = to;
            }
        }
    }
    //**STILL HLD PART**///
    void hld(ll v, ll pr = -1){
        chain[v] = cnt - 1;
        base[v] = all++;
        if(!csz[cnt - 1]){
            top[cnt - 1] = v;
        }
        ++csz[cnt - 1];
        if(nxt[v] != -1){
            hld(nxt[v], v);
        }
        for(auto to: g[v]){
            if(to == pr || to == nxt[v])continue;
            ++cnt;
            hld(to, v);
         }
    }    
    //**STILL HLD PART**///
    ll go(ll a, ll b){
        ll res = 0;
        while(chain[a] != chain[b]){
            if(depth[top[chain[a]]] < depth[top[chain[b]]]) swap(a, b);
            ll start = top[chain[a]];
            res += st.rmqquery(1, 0, n - 1, base[start], base[a]);
            //cout << res <<" a"<< endl;
            a = p[start];
        }
        if(depth[a] > depth[b]) swap(a, b);
        res += st.rmqquery(1, 0, n - 1, base[a], base[b]);
        return res;
    }

    // ****//** HLD PART ENDED **//*****//
    
    void solve(){
        ll a, b;
        for(ll i = 1; i < n; i++){
            scanf("%lld %lld", &a, &b);
            a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0);
        hld(0);
        //st.build(1, 0 , n - 1);
        for(ll i = 0; i < n; i++){
            st.rmqupdate(1, 0, n - 1, base[i], val[i]);
        }
        //for(auto it: st.rmqtree)cout << it << " "; cout << endl;
        p[0] = 0; ll cntr = 1;
        ll type;
        
        for(ll i = 1; i <= m; i++){
            scanf("%lld",&type);
            if(type == 1){
                scanf("%lld %lld", &a , &b);
                a--;
                st.rmqupdate(1, 0, n - 1, base[a], b);
            }
            else if(type == 2){
                scanf("%lld", &a);
                a--;
                printf("%lld\n",go(0, a));
            }
            
        }
    }
   
}hl;

int main(){
    scanf("%lld %lld", &n, &m); ll a, b;
    for(ll i = 0; i < n; i++){
        scanf("%lld", &val[i]);
    }
    hl.init(n, m);
    st.init(n);
    hl.solve();
    
    return 0;
}
