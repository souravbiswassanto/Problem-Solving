
// Problem: F. Dominant Indices
// Contest: Codeforces - Educational Codeforces Round 47 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1009/problem/F
// Memory Limit: 512 MB
// Time Limit: 4500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
using namespace std;
#define ll int
#define pb push_back
#define MAX 2000006
#define mem(a,v) memset(a,v,sizeof(a))

int cnt[MAX], sz[MAX], depth[MAX], cur;
ll ans[MAX], res[MAX];
bool big[MAX];
vector<int> g[MAX];
int Max;
struct SACK{
    int n;
    void init(int _n){
        n = _n;
        mem(big, false);
        mem(cnt, 0);
    }
    void getsz(int v, int p, int dep = 1){
        sz[v] = 1;
        for(auto u : g[v]){
            if(u != p){
                depth[u] = dep + 1;
                getsz(u, v, dep + 1);
                sz[v] += sz[u];
            }
        }
    }
    int add(int v, int p, int Max){
        cnt[depth[v]] += 1;
        Max = max(Max, cnt[depth[v]]);
        for(auto u: g[v]){
            if(u != p && !big[u]){
               Max = add(u, v, Max);
            }
        }
        return Max;
    }
    int query(int v, int p, int Max, int Min = INT_MAX){
        if(cnt[depth[v]] == Max){
            Min = min(depth[v] - depth[cur], Min);
        }
        for(auto u: g[v]){
            if(u != p && !big[u]){
               Min = query(u, v, Max, Min);
            }
        }
        return Min;
    }
    void remove(int v, int p){
        cnt[depth[v]] -= 1;
        for(auto u: g[v]){
            if(u != p && !big[u]){
               remove(u, v);
            }
        }
    }
    pair<int, int> dfs(int v, int p, bool keep){
        int mx = -1, bigChild = -1;
        for(auto u : g[v]){
           if(u != p && sz[u] > mx){
              mx = sz[u], bigChild = u;
           }
        }
        pair<int, int> res;
        int Min = 0;
        int Max = 0;
        for(auto u : g[v]){
            if(u != p && u != bigChild){
                res = dfs(u, v, 0);
            }
        } 
        if(bigChild != -1){
            res = dfs(bigChild, v, 1); big[bigChild] = 1;
        }
        int mxx;
        cur = v;
        mxx = add(v, p, res.first);
        int mn = query(v, p, mxx);
        if(mn > 1e8) ans[v] = res.second + 1, mn = res.second + 1;
        else ans[v] = mn;
        if(bigChild != -1){
            big[bigChild] = 0;
        }
        if(keep == 0){
            remove(v, p); 
            mxx = 0; mn = 0;
        }
        return {mxx, mn};
    }
    
    void solve(){
        depth[0] = 1;
        getsz(0, -1);
        pair<int, int> Max = dfs(0, -1, 1);
        for (int i = 0; i < n; i++)printf("%d\n",ans[i]);
    }
};
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    SACK sack;
    sack.init(n);
    sack.solve();
}
