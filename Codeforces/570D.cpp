#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
using namespace std;
#define ll long long
#define pb push_back
#define MAX 500006
#define mem(a,v) memset(a,v,sizeof(a))

const int two = 2;
int cnt[MAX][27], sz[MAX], col[MAX], Depth[MAX];
int ans[MAX], odd[MAX];
bool big[MAX];
vector<int> g[MAX];
vector<pair<int, int> > query[MAX];

struct SACK{
    int n, m;
    void init(int _n, int _m){
        n = _n;
        m = _m;
        mem(big, false);
        mem(cnt, 0);
    }
    
    void getsz(int v, int p, int depth = 1){
        sz[v] = 1;
        for(auto u : g[v]){
            if(u != p){
                Depth[u] = depth + 1;
                getsz(u, v, depth + 1);
                sz[v] += sz[u];
            }
        }
    }
    void add(int v, int p){
        cnt[Depth[v]][col[v]] += 1;
        if(cnt[Depth[v]][col[v]] % two){
            odd[Depth[v]]++;
        }
        else {
            odd[Depth[v]]--;
        }
        for(auto u: g[v]){
            if(u != p && !big[u]){
               add(u, v);
            }
        }

    }
    void remove(int v, int p){
        cnt[Depth[v]][col[v]] -= 1;
        odd[Depth[v]] = 0;
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
            ans[it.first] = (odd[it.second] <= 1)? 1 : 0;
            /*
            for(int i = 0; i < 26; i++){
                if(cnt[it.second][i] % two)c++;
            }
            if(c > 1)ans[it.first] = 0;
            else ans[it.first] = 1;
            */
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
        Depth[0] = 1;
        getsz(0, -1);
        dfs(0, -1, 1);
        for (int i = 0; i < m; i++){
            if(ans[i])printf("Yes\n");
            else printf("No\n");
        }
    }
};
int main(){
    int n, m;
    char ch;
    scanf("%d %d", &n, &m);
    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d", &a); a--;
        g[i].pb(a);
        g[a].pb(i);
    }
    for(int i = 0; i < n; i ++){
        scanf(" %c", &ch);
        col[i] = ch - 97;
    }
    SACK sack;
    sack.init(n, m);
    sack.solve();
}
