
// Problem: D. Tree and Queries
// Contest: Codeforces - Codeforces Round #221 (Div. 1)
// URL: https://codeforces.com/contest/375/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
using namespace std;
#define ll long long
#define pb push_back
#define MAX 500006
#define mem(a,v) memset(a,v,sizeof(a))

int cnt[MAX], sz[MAX], col[MAX];
int ans[MAX], odd[MAX];
bool big[MAX];
vector<int> g[MAX];
vector<pair<int, int> > query[MAX];
int N, Max;
int BIT[MAX];
struct FT{
    int n;
    void init(int _n){
        n = 100000;
    }
    void update(int x, int delta){
          for(; x <= n; x += x&-x) BIT[x] += delta;
    }
    int query(int x, int sum = 0){
         for(; x > 0; x -= x&-x) sum += BIT[x];
         return sum;
    }
}Bit;

struct SACK{
    int n, m;
    void init(int _n, int _m){
        n = _n; m = _m;
        mem(big, false);
        mem(cnt, 0);
    }
    
    void getsz(int v, int p){
        sz[v] = 1;
        for(auto u : g[v]){
            if(u != p){
                getsz(u, v);
                sz[v] += sz[u];
            }
        }
    }
    void add(int v, int p){
        cnt[col[v]] += 1;
        if(cnt[col[v]] > 1)Bit.update(cnt[col[v]] - 1, -1);
        Bit.update(cnt[col[v]], 1);
        for(auto u: g[v]){
            if(u != p && !big[u]){
               add(u, v);
            }
        }

    }
    void remove(int v, int p){
        cnt[col[v]] -= 1;
        Bit.update(cnt[col[v]] +  1, -1);
        if(cnt[col[v]])Bit.update(cnt[col[v]], 1);
        for(auto u: g[v]){
            if(u != p && !big[u]){
               remove(u, v);
            }
        }
    }
    int dfs(int v, int p, bool keep){
        int mx = -1, bigChild = -1;
        for(auto u : g[v]){
           if(u != p && sz[u] > mx){
              mx = sz[u], bigChild = u;
           }
        }
        int Max = 0;
        for(auto u : g[v]){
            if(u != p && u != bigChild){
                dfs(u, v, 0);
            }
        }
        if(bigChild != -1){
            dfs(bigChild, v, 1); big[bigChild] = 1;
        }
        add(v, p);
        for (auto it: query[v]){
            int c = 0;
            int a = Bit.query(100000);
            if(it.second > 1) c = Bit.query(it.second - 1);
            ans[it.first] = a - c;
            
        }
        if(bigChild != -1){
            big[bigChild] = 0;
        }
        if(keep == 0){
            remove(v, p); 
            Max = 0;
        }
        return Max;
    }
    
    void solve(){
        
        int a, b;
        for (int i = 0; i < m; i++){
            scanf("%d %d", &a, &b); a--;
            query[a].push_back({i, b});
        }
        getsz(0, -1);
        dfs(0, -1, 1);
        for (int i = 0; i < m; i++){
            printf("%d\n", ans[i]);
        }
    }
};
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    N = n;
    for(int i = 0; i < n; i++){
        scanf("%d", &col[i]);
    }
    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[b].pb(a);
        g[a].pb(b);
    }
    Bit.init(n);
    SACK sack;
    sack.init(n, m);
    sack.solve();
}
