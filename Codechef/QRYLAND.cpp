#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
using namespace std;
#define MAX 500106
#define ll int
#define ull long long
#define pb push_back
#define mem(a,v) memset(a,v,sizeof(a))

ll n, m, all, cnt = 1;
vector<int> g[MAX], nxt, csz;
vector<ll> tree, mx;
ll val[MAX], A[MAX]; 
ll Size[MAX], p[MAX], chain[MAX];
ll base[MAX], top[MAX], depth[MAX];
int waterat[MAX];
// chain array stores the chain number of a node v 

struct data{
    ull sum;
    int Xor = 0 , Min = INT_MAX, Max = 0, total = 0;
    
} Null;
vector<data> prefix(MAX);

void precalc (){
    prefix[0].sum = 0LL;
    prefix[0].Xor = 0;
    for(int i = 1; i <= 250005; i++){
        prefix[i].sum = 1LL * prefix[i - 1].sum + i;
        prefix[i].Xor = prefix[i - 1].Xor ^ i;
    }
}

struct SegmentTree{
    vector<data> tree;
    void init(int n){
        tree.clear(); tree.resize(4 * n);
    }
     //** Segment TREE PART STARTED**//
     void update(int node, int tb, int te,int idx, int newval){
        if(te < idx || idx < tb)return; 
        if(tb == te){
            tree[node].sum = (ull)newval;
            tree[node].Xor = newval;
            tree[node].Max = newval;
            tree[node].Min = newval;
            return;
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        update(left, tb, mid, idx, newval);
        update(right, mid + 1, te, idx, newval);
        tree[node].Max = max(tree[left].Max,tree[right].Max);
        tree[node].Min = min(tree[left].Min,tree[right].Min);
        tree[node].sum = tree[left].sum + tree[right].sum;
        tree[node].Xor = tree[left].Xor ^ tree[right].Xor;
        //cout << node <<" " << tree[node].sum << endl;
    }
    
    struct data query(int node, int tb, int te, int qb, int qe){
        if(tb > te) return Null;
        if(qb > te || qe < tb)return Null;
        if(qb <= tb && te <= qe){
            return tree[node];
        }
        int left, right, mid;
        left = (node << 1);
        right = left + 1;
        mid = (tb + te) >> 1;
        struct data L = query(left, tb, mid, qb, qe);
        struct data R = query(right, mid + 1, te, qb, qe);
        struct data Return;
        Return.sum = L.sum + R.sum;
        Return.Xor = L.Xor ^ R.Xor;
        Return.Min = min(L.Min, R.Min);
        Return.Max = max(L.Max, R.Max);
        return Return;
    }
    //** Segment TREE PART ENDED**//
} st;
struct HLD{
    int n, m;
    void init(int _n, int  _m){
        n = _n; m = _m;
        for(int i = 0; i <= n; i++)g[i].clear();
        nxt.clear(); nxt.resize(n + 1,  -1);
        csz.clear(); csz.resize(n + 1, 0); cnt = 1; all = 0;
    }
    
    //** HLD PART STARTED**///
    void dfs(int source, int pr = 0){
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
    void hld(int v, int pr = -1){
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
    struct data go(int a, int b){
        struct data Return = Null;
        struct data L = Null;
        int total = 0;
        while(chain[a] != chain[b]){
            if(depth[top[chain[a]]] < depth[top[chain[b]]]) swap(a, b);
            int start = top[chain[a]];
            L = st.query(1, 0, n - 1, base[start], base[a]);
            total += (base[a] - base[start] + 1);
            Return.sum = L.sum + Return.sum;
            Return.Xor = L.Xor ^ Return.Xor;
            Return.Min = min(L.Min, Return.Min);
            Return.Max = max(L.Max, Return.Max);
            a = p[start];
        }
        if(depth[a] > depth[b]) swap(a, b);
        L = st.query(1, 0, n - 1, base[a], base[b]);
        total += (base[b] - base[a] + 1);
        Return.sum = L.sum + Return.sum;
        Return.Xor = L.Xor ^ Return.Xor;
        Return.Min = min(L.Min, Return.Min);
        Return.Max = max(L.Max, Return.Max);
        Return.total = total;
        //cout << Return.sum << endl;
        return Return;
    }
    // ****//** HLD PART ENDED **//*****//
    
    void solve(){
        int a, b;
        for(int i = 0; i < n; i++){
            scanf("%d", &val[i]);
        }
        for(int i = 1; i < n; i++){
            scanf("%d %d", &a, &b);
            a--; b--;
            g[a].pb(b);
            g[b].pb(a);
        }
        dfs(0);
        hld(0);
        for(int i = 0; i < n; i++){
            st.update(1, 0, n - 1, base[i], val[i]);
        }
        p[0] = 0; int cntr = 1;
        int type;
        for(int i = 1; i <= m; i++){
            scanf("%d",&type);
            if(type == 2){
                scanf("%d %d", &a, &b);
                a--;
                st.update(1, 0, n - 1, base[a], b);
            }
            else if(type == 1){
                scanf("%d %d", &a, &b);
                a--;b--;
                struct data L = go(a, b);
                ull Sum = prefix[L.total].sum;
                int Xor = prefix[L.total].Xor, Min = 1, Max = L.total;
                //cout <<L.total <<" " << L.Max <<" " << L.Min << " " << L.sum <<" " << L.Xor << endl;
                
                if(Xor == L.Xor and Sum == L.sum and Min == L.Min and Max == L.Max){
                    printf("Yes\n");
                }
                else printf("No\n");
                
            }
            
        }
    }
   
}hl;


int main(){
    int t;
    precalc();
    Null.sum = 0LL;
    Null.Xor = 0;
    Null.Max = 0;
    Null.Min = INT_MAX;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m); int a, b;
        hl.init(n, m);
        st.init(n);
        hl.solve();
    }
    
    return 0;
}
