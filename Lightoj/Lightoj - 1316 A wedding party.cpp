
// Problem: A Wedding Party
// Contest: LightOJ
// URL: https://lightoj.com/problem/a-wedding-party
// Memory Limit: 64 MB
// Time Limit: 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 5000
#define pb push_back
#define mp make_pair
#define   mem(a,v)   memset(a,v,sizeof(a))

struct edge{
    int vertex, weight;
    edge(int a, int b){
        vertex = a; weight = b;
    }
};
struct node{
    int vertex, cost;
    node(int a, int b){
        vertex = a;
        cost = b;
    }
    bool operator<(node other)const{
        return cost > other.cost;
    }
};

vector<int> adj[MAX], adj_rev[MAX];
vector<bool> used;
vector<int> order, component, roots, root_nodes;
vector<vector<int>> adj_scc(MAX);
int vis[MAX], A[MAX], B[MAX], shop[MAX], D[MAX];
int Size[MAX], ans[MAX];
int n, m, x, y, k, w;
vector<edge> g[MAX];
priority_queue<node> pq;
int dist[17][MAX];
ll mxshop;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

ll dfs3(int source){
    ll res = -INT_MAX;
    for(auto v: adj_scc[source]){
        
        ll a = dfs3(v);
        res = max(res, a + shop[source]);
    }
    if(source == roots[n - 1])return shop[source];
    else return res;
    
}

void Dijkstra(int source){
    
    for(int i = 0; i <= n; i++) dist[source][i] = INT_MAX;
    pq.push(node(A[source], 0));
    dist[source][A[source]] = 0;
    
    while(!pq.empty()){
        
        node u = pq.top(); pq.pop();
	    if(u.cost != dist[source][u.vertex]) continue;
	    for(auto v: g[u.vertex]){
	        
            if(dist[source][u.vertex] + v.weight < dist[source][v.vertex]){
                dist[source][v.vertex] = dist[source][u.vertex] + v.weight;
                pq.push(node(v.vertex, dist[source][v.vertex]));
            }
        }
    }
}

ll dp[17][1 << 15];

ll calc(int idx, int mask, int last){
    if(idx == mxshop){
        //cout << last <<" "<< mask <<" "<< dist[last][n - 1] << endl;
        return dist[last][n - 1];
    }
    ll &ret = dp[last][mask];
    if(ret != -1)return ret;
    ret = INT_MAX;
    for(int i = 0; i < k; i++){
        if(mask & (1 << i))continue;
        ll a = calc(idx + 1, mask | (1 << i), i);
        ll b = (idx == 0)? D[A[i]]: dist[last][A[i]];\
        ret = min(ret, a + b);
    }
    return ret;
}

int main() {
    int tc; 
    scanf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++){
        scanf("%d %d %d", &n, &m, &k); 
        printf("Case %d: ", cs);
        order.clear();
        root_nodes.clear();
        mxshop = 0;
        for(int i = 0; i < n; i++){
            Size[i] = 0;
            B[i] = 0;
            adj_scc[i].clear();
            adj[i].clear();
            adj_rev[i].clear();
            g[i].clear();
        }
        
        for(int i = 0; i < k; i++){
            scanf("%d", &A[i]);
            B[A[i]] = 1;
        }
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d %d", &a, &b, &w);
            adj[a].push_back(b);
            adj_rev[b].push_back(a);
            g[a].pb(edge(b, w));
        }
    
        used.assign(n, false);
    
        for (int i = 0; i < n; i++)
            if (!used[i])
                dfs1(i);
        
        used.assign(n, false);
        reverse(order.begin(), order.end());
        roots.assign(n, 0);
        for (auto v : order){
            if (!used[v]) {
                dfs2 (v);
                int root = component.front();
                Size[root] = component.size(); int cntr = 0;
                for (auto u : component) {roots[u] = root;  if(B[u])cntr++;}
                root_nodes.push_back(root);
                shop[root] = cntr;
                component.clear();
            }
        }
        
        for (int v = 0; v < n; v++){
            for (auto u : adj[v]) {
                int root_v = roots[v], root_u = roots[u];
        
                if (root_u != root_v)
                    adj_scc[root_v].push_back(root_u);
            }
        }
        
        int a = roots[0];
        mxshop = dfs3(a);
        
        if(mxshop < 0){
            printf("Impossible\n"); continue;
        }
        int c = A[0];
        A[0] = 0;
        Dijkstra(0);
        A[0] = c;
        for(int i = 0; i < n; i++){
            D[i] = dist[0][i];
        }
        for(int i = 0; i < k; i++){
            Dijkstra(i);
        }
        mem(dp, -1);
        ll res = calc(0, 0, 0);
        printf("%lld %lld\n", mxshop, res);
    }
}


