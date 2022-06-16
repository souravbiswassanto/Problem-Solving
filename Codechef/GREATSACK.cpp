
// Problem: Great Responsibility
// Contest: CodeChef - Alohomora 
// URL: https://www.codechef.com/ALMR2022/problems/GREATSACK
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

int cnt[MAX];
int sz[MAX], A[MAX];
bool big[MAX];
vector<int> g[MAX];
vector<pair<int, int>> query, arr;
vector<pair<int, pair<int, int> >> val[MAX];
vector<int> divs[MAX];

void divfact(){
    for(int i = 1; i <= 200000; i++){
        for(int j = i; j <= 200000; j += i){
            divs[j].pb(i);
        }
    }
}

struct SACK{
    int n, q;
    void init(int _n, int _q){
        mem(big, false);
        mem(cnt, 0);
        n = _n; q = _q;
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
    void add(int v, int p, int x){
        //cnt[col[v]] += x;
        cnt[A[v]] += x;
        for(auto u: g[v]){
            if(u != p && !big[u]){
                add(u, v, x);
            }
        }
    }
    
    void dfs(int v, int p, bool keep){
        int mx = -1, bigChild = -1;
        //cout << v << endl;
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
            dfs(bigChild, v, 1), big[bigChild] = 1;
        }
        add(v, p, 1);
        //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
        for(int i = 0; i < val[v].size(); i++){
            int a = val[v][i].first;
            int b = val[v][i].second.first;
            int c = val[v][i].second.second;
            //cout <<v<<" "<< a <<" "<< b <<" "<< c <<" "<< cnt[a] << endl;
            int cntr = 0;
            for(auto it: divs[a]){
                cntr += cnt[it];
            }
            if(c == 1){
                query[b].first = cntr;
            }
            else{
                query[b].second = cntr;
            }
        }
        if(bigChild != -1){
            big[bigChild] = 0;
        }
        if(keep == 0){
            add(v, p, -1);
        }
    }
    
    void solve(){
        getsz(0, -1);
        int u, v, x;
        for(int i = 0; i < q; i++){
            scanf("%d %d %d", &u, &v, &x); u--; v--;
            arr.pb({u, v});
            val[u].pb({x, {i, 1}});
            val[v].pb({x, {i, 2}});
        }
        query.resize(q + 1);
        dfs(0, -1, 0);
        for(int i = 0; i < q; i++){
            if(query[i].first < query[i].second){
                cout << arr[i].second + 1<< endl;
            }
            else if(query[i].first > query[i].second){
                cout << arr[i].first + 1<< endl;
            }
            else cout <<"Draw" << endl;
        }
    }
};
int main(){
    divfact();
    
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    SACK sack;
    sack.init(n, q);
    sack.solve();
}
