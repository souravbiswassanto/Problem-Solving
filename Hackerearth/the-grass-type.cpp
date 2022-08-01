
// Problem: The Grass Type
// Contest: HackerEarth - Algorithms - Graphs - Depth First Search
// URL: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/the-grass-type/
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
map<int, int> cnt;
int  sz[MAX], col[MAX];
ll ans[MAX], res[MAX], sum;
bool big[MAX];
vector<int> g[MAX];

struct SACK{
    int n;
    void init(int _n){
        n = _n;
        mem(big, false);
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
    void add(int v, int p, int val){
        if(val % col[v] == 0)sum += cnt[val / col[v]];
        for(auto u: g[v]){
            if(u != p && !big[u]){
               add(u, v, val);
            }
        }
    }
    void add1(int v, int p){
        cnt[col[v]]++;
        for(auto u: g[v]){
            if(u != p && !big[u]){
               add1(u, v);
            }
        }
    }
    void remove(int v, int p){
        for(auto u: g[v]){
            if(u != p && !big[u]){
                cnt[col[u]] -= 1;
                remove(u, v);
            }
        }
    }
    void dfs(int v, int p, bool keep){
        int mx = -1, bigChild = -1;
        for(auto u : g[v]){
           if(u != p && sz[u] > mx){
              mx = sz[u], bigChild = u;
           }
        }
        for(auto u : g[v]){
            if(u != p && u != bigChild){
                dfs(u, v, 0);
            }
        } 
        if(bigChild != -1){
            dfs(bigChild, v, 1); big[bigChild] = 1;
        }
        for(auto u: g[v]){
            if(u != bigChild and u != p){
                add(u, v, col[v]);
                add1(u, v);
            }
        }
        sum += cnt[1];
        
        if(bigChild != -1){
            big[bigChild] = 0;
        }
        if(keep == 0){
            remove(v, p); 
        }
        else {
            cnt[col[v]]++;
        }
    }
    
    void solve(){
        getsz(0, -1);
        dfs(0, -1, 1);
        printf("%lld", sum);
        printf("\n");
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
    for (int i = 0; i < n; i++){
        scanf("%d", &col[i]);
    }
    SACK sack;
    sack.init(n);
    sack.solve();
}
