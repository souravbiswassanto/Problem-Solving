
// Problem: E. Lomsat gelral
// Contest: Codeforces - Educational Codeforces Round 2
// URL: https://codeforces.com/contest/600/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
ll ans[MAX], res[MAX];
bool big[MAX];
vector<int> g[MAX];

struct SACK{
    int n;
    void init(int _n){
        n = _n;
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
    int add(int v, int p, int Max){
        cnt[col[v]] += 1;
        res[cnt[col[v]]] += col[v];
        Max = max(Max, cnt[col[v]]);
        for(auto u: g[v]){
            if(u != p && !big[u]){
               Max = add(u, v, Max);
            }
        }
        return Max;
    }
    void remove(int v, int p){
        res[cnt[col[v]]] -= col[v];
        cnt[col[v]] -= 1;
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
                Max = dfs(u, v, 0);
            }
        } 
        if(bigChild != -1){
            Max = dfs(bigChild, v, 1); big[bigChild] = 1;
        }
        Max = add(v, p, Max);
        ans[v] = res[Max];
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
        getsz(0, -1);
        int Max = dfs(0, -1, 1);
        for (int i = 0; i < n; i++)printf("%lld ",ans[i]);
        printf("\n");
    }
};
int main(){
    int n;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &col[i]);
    }
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
